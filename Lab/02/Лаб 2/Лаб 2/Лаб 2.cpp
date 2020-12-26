#include <iostream>
#include <string>
#include <io.h>
#include <fstream>  
#include "include/cpp_httplib/httplib.h"
#include "include/cpp_httplib/json.hpp" 
using namespace std;
using namespace httplib;
using json = nlohmann::json;


// В этой функции формируем ответ сервера на запрос

void gen_response(const Request& req, Response& res) {
    // Выводим на экран тело запроса
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
int main() {
    Server svr;        
    svr.Post("/webhooks", gen_response);           // Вызвать функцию gen_response на post запрос
    std::cout << "Start server... OK\n"; // cout использовать нельзя
    svr.listen("localhost", 1234);         // Запускаем сервер на localhost и порту 1234
}