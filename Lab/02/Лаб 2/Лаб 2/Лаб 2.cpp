#include <iostream>
#include <string>
#include <io.h>
#include <fstream>  
#include "include/cpp_httplib/httplib.h"
#include "include/cpp_httplib/json.hpp" 
using namespace std;
using namespace httplib;
using json = nlohmann::json;

//WEBHOOKS
void gen_response(const Request& req, Response& res) {

    std::cout << req.body.c_str();
    json p;
    string shablonstr, webliststr, end;
    ifstream fin; ifstream weblistfile; ifstream endhooks;
    string html, example ;
    fstream file;
    endhooks.open("endhooks.html"); getline(endhooks, end, '\0');
    fin.open("shablon.html"); getline(fin, shablonstr, '\0');
    file.open("webhook.json");
    weblistfile.open("web_list.html"); getline(weblistfile, webliststr, '\0');
    file >> p;
    if (req.has_param("del")){
        auto val = req.get_param_value("del");
        for (int i = 0; i < (p["webhooks"].size()); i++) 
            if (p["webhooks"][i]["url"]==val) 
                p["webhooks"].erase(p["webhooks"].begin() + i);
        
    } 
    else if (req.has_param("set")) {
        auto val = req.get_param_value("set");
        p["webhooks"].push_back({ { "url", val } });
    }
    ofstream pip("out_2.json");
    pip << p;
    string g = "{webhooks_list}";
    if (p["webhooks"].size() == 0) {
        webliststr.replace(webliststr.find(g), g.length(), "");
        res.set_content(webliststr, "text/html; charset=UTF-8");

    }
    else {
        webliststr.replace(webliststr.find(g), g.length(), "");
        webliststr.replace(webliststr.find(end), end.length(), "");
        for (int i = 0; i < (p["webhooks"].size()); i++) {
            string a = p["webhooks"][i]["url"];
            string url = "{Webhook URL}";
            int   n = shablonstr.find(url);
            if (n == 96) {
                shablonstr.replace(shablonstr.find(url), url.length(), a);
                shablonstr.replace(shablonstr.find(url), url.length(), a);
                webliststr += shablonstr;
                webliststr += "\n";

            }
            else {
                url = p["webhooks"][i - 1]["url"];
                shablonstr.replace(shablonstr.find(url), url.length(), a);
                shablonstr.replace(shablonstr.find(url), url.length(), a);
                webliststr += shablonstr;
                webliststr += "\n";
            }
        }
        webliststr += "\n";
        webliststr += end;
        ofstream o_file("out.html");
        o_file << webliststr;
        res.set_content(webliststr, "text/html; charset=UTF-8");

    }
    file.close(); 
    file.open("webhook.json");
    file << p;
}

//ALICE

json silence = {
	{"title", u8"Молчать"},
	{"hide", true}
};

json speaker = {
	{"title", u8"Говорить"},
	{"hide", true}
};

json help = {
	{
		{"title", u8"Помощь"},
		{"hide", true}
	}
};
json help_buttons = {
	{
		{"title", u8"Молчать"},
		{"hide", true}
	},
	{
		{"title", u8"Говорить"},
		{"hide", true}
	},
	{
		{"title", u8"Корзина"},
		{"hide", true}
	},
	{
		{"title", u8"Выход"},
		{"hide", true}
	}
};

enum  voice {
	on,
	off
};
enum  skills {
	help_skill,
	exit_skill
};

json send_to_user(const string& text, const string& tts, const json& buttons, const json* new_session = nullptr, const bool end_session = false) {
	json data = {
		{"response",
		{
			{"buttons", buttons},
			{"end_session", end_session}
		}
		},
		{"version", "1.0"}
	};
	if (new_session != nullptr && (*new_session)["voice"] == on) {
		if (tts != "") {
			data["response"]["tts"] = tts;
		}
		data["response"]["buttons"].push_back(silence);
	}
	else if (new_session != nullptr && (*new_session)["voice"] == off) {
		data["response"]["buttons"].push_back(speaker);
	}
	if (text != "") {
		data["response"]["text"] = text;
	}

	return data;
}

json session_json = json::array();
void alice(const Request& req, Response& res)
{
	json request = json::parse(req.body);
	string user_id = request["session"]["application"]["application_id"];
	json* new_session = nullptr;
	string txt, tts;

	for (auto& session : session_json) {
		if (session["user_id"] == user_id) {
			new_session = &session;
			break;
		}
	}
	if (request["session"]["new"].get<bool>()) {
		if (new_session == nullptr) {	
			json session;
			session["user_id"] = user_id;		
			session["skills"] = exit_skill;		
			session["voice"] = on;				
			session["check"] = json::array();

			session_json.push_back(session);
			new_session = &session_json[session_json.size() - 1];
		}
		else {
			(*new_session)["skills"] = exit_skill;
			(*new_session)["voice"] = on;
		}
		txt = u8"Здравствуйте! Я помогу вам с покупками";
		tts = u8"Здравствуйте! Я помогу вам с покупками";
		json res_file = send_to_user(txt, tts, help, new_session);
		res.set_content(res_file.dump(2), "text/json; charset=UTF-8");
		return;
	}
	if (new_session == nullptr) {
		txt = u8"Произошла ошибка, сессия окончена.";
		tts = u8"Произошла ошибка, сессия окончена.";
		json res_file = send_to_user(txt, tts, help, new_session);
		res.set_content(res_file.dump(2), "text/json; charset=UTF-8");
		return;
	}

	string com = request["request"]["command"];

	if ((*new_session)["skills"] == help_skill) {
		if (com == u8"молчать") {
			txt = u8R"(Данная команда отключает озвучку всех сообщений.
				       О чем ещё рассказать?)";
			tts = u8R"(Данная команда отключает озвучку всех сообщений.
				       О чем ещё рассказать?)";
		}
		else if (com == u8"говорить") {
			txt = u8R"(Данная команда подключает озвучку всех сообщений.
					   О чем ещё рассказать?)";
			tts = u8R"(Данная команда подключает озвучку всех сообщений.
				       О чем ещё рассказать?)";
		}
		else if (com == u8"корзина") {
			txt = u8R"(Возможность Корзина имеет несколько команд:
					   1. Очистить корзину - удаляет все содержимое вашей корзины.
                       2. Добавить в корзину - добавляет в корзину новый товар.
					      Для добавления используйте "Добавить в корзину <наименование, цена> рублей"
					   3. Удалить из корзины - удаляет один товар из вашей корзины.
						  Для удаления используйте "Удалить из корзины <наименование>"
					   4. Что в корзине - отображение полного списка ваших товаров.
					   5. Сумма - считает стоимость собранной вами корзины.
					   О чем рассказать ещё?)";
			tts = u8R"(Возможность Корзина имеет несколько команд:
					   1. Очистить корзину - удаляет все содержимое вашей корзины.
                       2. Добавить в корзину - добавляет в корзину новый товар.
					      Для добавления используйте "Добавить в корзину <наименование, цена> рублей"
					   3. Удалить из корзины - удаляет один товар из вашей корзины.
						  Для удаления используйте "Удалить из корзины <наименование>"
					   4. Что в корзине - отображение полного списка ваших товаров.
					   5. Сумма - считает стоимость собранной вами корзины.
					   О чем рассказать ещё?)";
		}
		else if (com == u8"выход") {
			txt = u8"Выход из режима помощи";
			tts = u8"Выход из режима помощи";
			(*new_session)["skills"] = exit_skill;
		}
		else {
			txt = u8"Неизвестная команда";
			tts = u8"Неизвестная команда";
		}
		json res_file;
		if ((*new_session)["skills"] == help_skill) {
			res_file = send_to_user(txt, tts, help_buttons, new_session);
		}
		else {
			res_file = send_to_user(txt, tts, help, new_session);
		}
		res.set_content(res_file.dump(2), "text/json; charset=UTF-8");
	}
	else {
		if (com == u8"молчать") {
			txt = u8"Молчу, молчу";
			tts;
			(*new_session)["voice"] = off;
			json res_file = send_to_user(txt, tts, help, new_session);
			res.set_content(res_file.dump(2), "text/json; charset=UTF-8");
		}
		else if (com == u8"говорить") {
			txt = u8"Хорошо";
			tts = u8"Хорошо";
			(*new_session)["voice"] = on;
			json res_file = send_to_user(txt, tts, help, new_session);
			res.set_content(res_file.dump(2), "text/json; charset=UTF-8");
		}
		else if (com == u8"помощь") {
			txt = u8R"(Молчать - отключение озвучки реплик.
					 Говорить - включение озвучки реплик. 
					 Корзина - помощь в организации вашей покупки.
				     О чем рассказать подробнее?
					 Нажмите "Выход" для выхода из режима помощи.)";
			tts = u8R"(Молчать - отключение озвучки реплик.
					 Говорить - включение озвучки реплик. 
					 Корзина - помощь в организации вашей покупки.
				     О чем рассказать подробнее?
					 Нажмите "Выход" для выхода из режима помощи.)";
			json res_file = send_to_user(txt, tts, help_buttons, new_session);
			(*new_session)["skills"] = help_skill;
			res.set_content(res_file.dump(2), "text/json; charset=UTF-8");
		}

		else if (com == u8"очистить корзину") {
			txt = u8"Корзина очищена";
			tts = u8"Корзина очищена";
			json res_file = send_to_user(txt, tts, help, new_session);
			(*new_session).erase("check");
			(*new_session)["check"] = json::array();
			res.set_content(res_file.dump(2), "text/json; charset=UTF-8");
		}
		else if (com.find(u8"добавить в корзину") == 0) {
			size_t size = request["request"]["nlu"]["tokens"].size();
			txt = u8"ОК";
			tts = u8"ОК";
			string item_name;
			int item_price = 0, num_index = 0;
			bool set_price = false;

			for (auto ent : request["request"]["nlu"]["entities"]) {
				if (ent["type"].get<string>() == "YANDEX.NUMBER") {
					num_index = ent["tokens"]["start"];
					int val = ent["value"];
					if (val <= 0) {
						txt = u8"Цена не может быть отрицательной или равняться нулю";
						tts = u8"Цена не может быть отрицательной или равняться нулю";
					}
					else {
						item_price = val;
					}
					set_price = true;
					break;
				}
			}
			if (size == 3) {
				txt = u8"Что добавлять?";
				tts = u8"Что добавлять?";
			}
			else if (num_index == 3) {
				txt = u8"Укажите название товара";
				tts = u8"Укажите название товара";
			}
			else if (!set_price) {
				txt = u8"Укажите цену";
				tts = u8"Укажите цену";
			}
			else {
				for (int i = 3; i < num_index; ++i) {
					item_name += request["request"]["nlu"]["tokens"][i].get<string>();
					item_name += " ";
				}
				item_name.pop_back();
				json item = {
					{"item",  item_name},
					{"price", item_price}
				};
				(*new_session)["check"].push_back(item);
			}

			json res_file = send_to_user(txt, tts, help, new_session);
			res.set_content(res_file.dump(2), "text/json; charset=UTF-8");
		}
		else if (com.find(u8"удалить из корзины") == 0) {
			size_t size = request["request"]["nlu"]["tokens"].size();
			string name = "";

			for (int i = 3; i < size; ++i) {
				name += request["request"]["nlu"]["tokens"][i].get<string>();
				name += " ";
			}
			bool found = false;
			int	item_index = 0;

			if (name == "") {
				txt = u8"Укажите название товара";
				tts = u8"Укажите название товара";
			}
			else {
				name.pop_back();
				for (auto& cart_item : (*new_session)["check"]) {
					if (cart_item["item"].get<string>() == name) {
						found = true;
						break;
					}
					++item_index;
				}
				if (!found) {
					txt = u8"Товар отсутствует в корзине";
					tts = u8"Товар отсутствует в корзине";
				}
				else {
					txt = u8"ОК";
					tts = u8"ОК";
					(*new_session)["check"].erase((*new_session)["check"].begin() + item_index);
				}
			}
			json res_file = send_to_user(txt, tts, help, new_session);
			res.set_content(res_file.dump(2), "text/json; charset=UTF-8");
		}
		else if (com == u8"что в корзине") {
			if ((*new_session)["check"].empty()) {
				txt = u8"В корзине ничего нет";
				tts = u8"В корзине ничего нет";
			}
			else {
				txt = u8"Товары в корзине:";
				tts = u8"Товары в корзине:";
				for (auto& elem : (*new_session)["check"]) {
					int price = elem["price"].get<int>();

					txt += "\n"
						+ elem["item"].get<string>()
						+ u8" ценой "
						+ std::to_string(price);
					tts += "\n"
						+ elem["item"].get<string>()
						+ u8" ценой "
						+ std::to_string(price);

					if (price % 10 == 1) {
						txt += u8" рубль,";
						tts += u8" рубль,";
					}
					else if (price % 10 < 5 && price % 10 > 0) {
						txt += u8" рубля,";
						tts += u8" рубля,";
					}
					else {
						txt += u8" рублей,";
						tts += u8" рублей,";
					}
				}
				txt.pop_back();
				tts = txt;
			}

			json res_file = send_to_user(txt, tts, help, new_session);
			res.set_content(res_file.dump(2), "text/json; charset=UTF-8");
		}
		else if (com == u8"сумма") {
			size_t size = request["request"]["nlu"]["tokens"].size();
			int sum = 0;
			for (auto& cart_item : (*new_session)["check"]) {
				sum += cart_item["price"].get<int>();
			}
			string str_sum = to_string(sum);
			txt = u8"В корзине товаров на " + str_sum;
			tts = u8"В корзине товаров на " + str_sum;

			if (sum % 10 == 1) {
				txt += u8" рубль";
				tts += u8" рубль";
			}
			else if (sum % 10 < 5 && sum % 10 > 0) {
				txt += u8" рубля";
				tts += u8" рубля";
			}
			else {
				txt += u8" рублей";
				tts += u8" рублей";
			}

			json res_file = send_to_user(txt, tts, help, new_session);
			res.set_content(res_file.dump(2), "text/json; charset=UTF-8");
		}
		else {
			txt = u8"Неизвестная команда";
			tts = u8"Неизвестная команда";

			json res_file = send_to_user(txt, tts, help, new_session);
			res.set_content(res_file.dump(2), "text/json; charset=UTF-8");
		}
	}
}

int main() {
    Server svr;        
    svr.Post("/webhooks", gen_response);  
	svr.Post("/", alice);
    std::cout << "Start server... OK\n"; 
    svr.listen("localhost", 1234);        
}