#include <iostream>
#include <string>
#include <io.h>
#include <fstream>  
#include "include/cpp_httplib/httplib.h"
#include "include/cpp_httplib/json.hpp" 
using namespace std;
using namespace httplib;
using json = nlohmann::json;
void gen_response(const Request& req, Response& res) {
    // Создаём клиент и привязываем к домену. Туда пойдут наши запросы
    Client cli("http://webhook.site");
    // Отправляем post в теле которого будет текст {"Hello": "world"}
    auto all = cli.Post("/853fdcd3-ffb8-473a-8a4b-659478b36bfc", R"({"Hello": "world"})", "text/json");
    // res преобразуется в true, если запрос-ответ прошли без ошибок
    if (all) {
        // Проверяем статус ответа, т.к. может быть 404 и другие
        if (all->status == 200) {
            // В res->body лежит string с ответом сервера
            std::cout << all->body << std::endl;
            string c = (all->body);
            res.set_content(c, "text/html");
        }
        else {
            std::cout << "Status code: " << all->status << std::endl;
        }
    }
    else {
        auto err = all.error();
        std::cout << "Error code: " << err << std::endl;
    }
}
int main() {
    Server svr;
    svr.Get("/", gen_response);
    svr.Post("/", gen_response);
    std::cout << "Start server... OK\n";
    svr.listen("localhost", 80);
}

