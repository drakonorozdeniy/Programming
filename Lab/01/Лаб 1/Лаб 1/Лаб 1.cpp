#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "include/cpp_httplib/httplib.h"
#include "include/cpp_httplib/json.hpp"
using json = nlohmann::json;
using namespace std; 
using namespace httplib;
int prevtime=0, unixtime = 1;
string b_line, str,a = "";
int  pover  (int a) {
    Client cli("http://worldtimeapi.org");
    auto res = cli.Get("/api/timezone/Europe/Simferopol");
    if (res) {
        if (res->status == 200) {
            json j2 = json::parse(res->body);
            a = j2["unixtime"];
        }
        else {
            std::cout << "Status code: " << res->status << std::endl;
        }
    }
    else {
        auto err = res.error();
        std::cout << "Error code: " << err << std::endl;
    }return a;
}
string line(string c ) {
    Client cli("http://api.openweathermap.org");
    auto res = cli.Get("/data/2.5/onecall?lat=44.952116&lon=34.102411&exclude=current,minutely,daily,alerts&units=metric&lang=ru&appid=2d3977d669c689c7762d22177616c5f4");
    if (res) {
        if (res->status == 200) {
            c = (res->body);
        }
        else {
            std::cout << "Status code: " << res->status << std::endl;
        }
    }
    else {
        auto err = res.error();
        std::cout << "Error code: " << err << std::endl;
    }return c;
}
void gen_response(const Request& req, Response& res) {
    if (prevtime / 3600 < (pover(unixtime)/3600)) {
        b_line = line(a);
        json j = json::parse(line(a));
        string weather = j["hourly"][0]["weather"][0]["description"];
        string icon = j["hourly"][0]["weather"][0]["icon"];
        double  temp = (j["hourly"][0]["temp"]);
        int pop = round(temp);
        string temp_1 = to_string(pop);
        ifstream file("template.html");
        if (!file.is_open()) {
            cout << "Ошибка фаила" << endl;
        }
        else {
            string A = "{hourly[i].weather[0].description}";
            string B = "{hourly[i].weather[0].icon}";
            string C = "{hourly[i].temp}";
            getline(file, str, '\0');
            str.replace(str.find(A), A.length(), weather);
            str.replace(str.find(B), B.length(), icon);
            str.replace(str.find(C), C.length(), temp_1);
            str.replace(str.find(C), C.length(), temp_1);
            prevtime = pover(unixtime);
            res.set_content(str, "text/html");
        }
    }
    else {
        json j = json::parse(b_line);
        string weather = j["hourly"][0]["weather"][0]["description"];
        string icon = j["hourly"][0]["weather"][0]["icon"];
        double temp =(j["hourly"][0]["temp"]);
        int pop = round(temp);
        string temp_1 = to_string(pop);
        ifstream file("template.html");
        if (!file.is_open()) {
            cout << "Ошибка фаила" << endl;
        }
        else {
            string A = "{hourly[i].weather[0].description}";
            string B = "{hourly[i].weather[0].icon}";
            string C = "{hourly[i].temp}";
            getline(file, str, '\0');
            str.replace(str.find(A), A.length(), weather);
            str.replace(str.find(B), B.length(), icon);
            str.replace(str.find(C), C.length(), temp_1);
            str.replace(str.find(C), C.length(), temp_1);
            prevtime = pover(unixtime);
            res.set_content(str, "text/html");
        }
    }
}
json pip= json::array();
void gen_response2(const Request& req, Response& res) {
    if (prevtime / 3600 < (pover(unixtime) / 3600)) {
        b_line = line(a);
        json p = json::parse(line(a));
        string lolipop = p["hourly"][0]["weather"][0]["description"];
        double  temp = (p["hourly"][0]["temp"]);
        int pop = round(temp);
        prevtime = pover(unixtime);
        pip.push_back({ {"temp",pop},{"description",lolipop} });
        json l = pip.dump(2);
        res.set_content(l, "text/json");
  

    }else {
        json p = json::parse(b_line);
        string lolipop = p["hourly"][0]["weather"][0]["description"];
        double  temp = (p["hourly"][0]["temp"]);
        int pop = round(temp);
        prevtime = pover(unixtime);
        pip.push_back({ {"temp",pop},{"description",lolipop} });
        json l = pip.dump(2);
        res.set_content(l, "text/json");
}
}
int main() {
    Server svr;
    svr.Get("/", gen_response);
    std::cout << "Start server... OK\n";
    svr.Get("/raw", gen_response2);
    std::cout << "Start server... OK\n";
    svr.listen("localhost", 3000);
}
