<p  align="center">МИНИСТЕРСТВО НАУКИ И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ<br>
Федеральное государственное автономное образовательное учреждение высшего образования<br>
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"<br>
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ<br>
Кафедра компьютерной инженерии и моделирования</p>
<br>
<h3  align="center">Отчёт по лабораторной работе № 1<br> по дисциплине "Программирование"</h3>
<br><br>
<p>студента 1 курса группы ПИ-б-о-201(2)<br>
Карев Даниил Николаевич<br>
направления подготовки 09.03.04 "Программная инженерия"</p>
<br><br>
<table>
<tr><td>Научный руководитель<br> старший преподаватель кафедры<br> компьютерной инженерии и моделирования</td>
<td>(оценка)</td>
<td>Чабанов В.В.</td>
</tr>
</table>
<br><br>
<p  align="center">Симферополь, 2020</p>
<hr>

Цель:
-----------
1. Закрепить навыки разработки многофайловыx приложений;
2. Изучить способы работы с API web-сервиса;
3. Изучить процесс сериализации/десериализации данных в/из json;
4. Получить базовое представление о сетевом взаимодействии приложений;
Изучить способы работы с API web-сервиса;

Постановка задачи
--------------------------
Разработать сервис предоставляющий данные о погоде в городе Симферополе на момент запроса. В качестве источника данных о погоде используйте: [http://openweathermap.org/](http://openweathermap.org/). В состав сервиса входит: серверное приложение на языке С++ и клиентское приложение на языке Python
Серверное приложение (далее Сервер) предназначенное для обслуживания клиентских приложений и минимизации количества запросов к сервису _openweathermap.org_. Сервер должен обеспечивать возможность получения данных в формате JSON и виде _html_ виджета (для вставки виджета на страницу будет использоваться _[iframe](https://habr.com/ru/post/488516/)_).
Клиентское приложение должно иметь графический интерфейс отображающий сведения о погоде и возможность обновления данных по требованию пользователя.

Выполнение работы:
--------------------------

Создание серверного приложения
--------------


**1.** Для начала я решил изучить Структуру http-запроса, какие элементы туда входят и с чем мне нужно будет работать. C работой мне помогла разобраться картинка, а так же видео фрагменты предоставленные преподавателем. Я узнал что такое сетевой порт , путь к ресурсу , якорь и т.д .
![](https://vladimirchabanov.github.io/Lab1_fils/img/request.png)
<p  align="center">Рис. 1. Структура http-запроса </p>

**2.** Далее я приступил к работе с сервисом сервисом openweathermap.org. Я сгенерировал свой API key, использовал шаблон http://api.openweathermap.org/data/2.5/onecall? и такие параметры, как: lat(ширина), lon(долгота) - координаты города, exclude - исключение(исключаем всё, кроме почасового измерения),lang - установление языка(в нашем случае приравниваем к ru(русский)), units - устанавливаем в чём измеряем скорость ветра и температуру(metric - температура в Цельсиях, скорость ветра - м/с), 
а затем в переменную appid вставляю API key. Таким образом, я создал запрос:http://api.openweathermap.org/data/2.5/onecall?lat=44.952116&lon=34.102411&exclude=current,minutely,daily,alerts&units=metric&lang=ru&appid=2d3977d669c689c7762d22177616c5f4.

<p  align="center"><img  src=./image/№2.png></p>
<p  align="center">Рис. 2. Ответ сервера на запрос. </p>

Для полного понимания ответа его удобнее изучать в виде дерева, например при помощи [JSON Viewer](https://codebeautify.org/jsonviewer).

**3.** Работа с сервисом worldtimeapi.org. Мне удалось получить запрос для времени в Симферополе и изучить формат ответа. Cгенерирую запрос на сайте https://worldtimeapi.org. Для этого прописываю параметр timezone, далее указываю часть света (Europe), а затем город (Simferopol). Сам запрос: https://worldtimeapi.org/api/timezone/Europe/Simferopol.
<p  align="center"><img  src=./image/№4.png></p>
<p  align="center">Рис. 3. Ответ сервера на запрос. </p>

**4.** Далее я изучил руководство преподавателя, ознакомился с полезными видео материалами и ссылками.

**5.** Приступил к выполнению основной части лабораторной работы. Для начала скачиваю из репозитория библиотеку cpp_httplib, которая понадобится нам для работы с сетью. Также из того же репозитория скачиваем библиотеку nlohmann:json, которая понадобится для работы с json. Создаю консольное приложение С++, перехожу в папку с главным проектом и создаю папку include, куда распаковываю архивы, которые содержат библиотеки. Теперь подключаю все необходимые библиотеки. 
```C++
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "include/cpp_httplib/httplib.h"
#include "include/cpp_httplib/json.hpp"
using json = nlohmann::json;
using namespace std; 
using namespace httplib;
// code
```

**6.** Теперь создадим функцию типа int  для http://worldtimeapi.org  и string для  получения данных от сервисов http://openweathermap.org/ и http://worldtimeapi.org. Посылаем им get-запросы, возвращаем в переменную. 
```C++
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
//code
```
 **7.** Затем в цикле обноляем кэш. Если в нём содержится информация на 1 час больше, то кэш не обновляем. Если в кэше нет данных, устарел или запрос не делали, то кэш обновляется.

```C++
if (prevtime / 3600 < (pover(unixtime)/3600)) {
...
}
else {
    ...
}
//code
```
**8.** Выводим на сайт: http://localhost:3000/ После этого программа ищет строки в html-коде и заменяет их на строки, которые нам выдает сервер.

```C++
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
//code 
```
**9.** Для вормирования запросов для "/raw" я использовал теже функции что и для "/"
Также проверяем кэш в if . Если в кэше нет данных, устарел или запрос не делали, то кэш обновляется и высвечивается информация о погоде на начало следующего часа. Затем кидаем в переменную значение описания и температуры и выводим на сайт: http://localhost:3000/raw
```C++
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
//code
```
**10.** Создаём сервер. Затем для основного используем первую функцию, для /raw используем вторую функцию. Указываем, на каком хосте работает.Переходим на сайты и проверяем работу сервера.
<p  align="center"><img  src=./image/№19.png></p>
<p  align="center">Рис. 4. Готовый сервер</p>

**Создание клиентского приложения**
-----------------------

**1.** Графический интерфейс я реализовал с помощью Tkinter. В консоле, с помощью команды pip install requests(если при установке Pythona напротив PYTH вы не поставили галочку, то придётся решать эту проблемы собственноручно) устанавливаем модуль requetsts, который нам понадобится для работы с сетью. А для работы с json пользуемся модулем json. Теперь создаём функцию, в которую помещаем подключение к http://localhost:3000/raw, куда мы недавно выводили информацию о температуре и погоде.
```Python
import requests 
from tkinter import *
import json
from tkinter.font import BOLD
r = requests.get('http://localhost:3000/raw')
f=r.json()
a=f[0]["description"].encode('l1').decode()
b=str(f[0]["temp"])
#code
```
**2.** Затем  класс виджетов Label для отображения текста, задаём цвет, высоту, ширину. Область, которую мы обозначили в root.geometry, мы разделили на три части. Также задаём положение каждому Label.
```Python 
root = Tk ()
root.title("Погода")
root.geometry('134x189+200+100')

one =Label(root,text="Симферополь\n"+a, width=40,  font=("Ubuntu",8,BOLD), bg="#ffba00",  fg="black")
one.pack()
two=Label(root, text =b+"°C" , width=30,heigh=2 ,font=(" Droid Serif",40),bg="white", fg="black")
two.pack()

three=Label(root,text = "" , width=40, heigh=2, bg="#ffba00", )
three.pack()

root.mainloop()
#code 
```
**3.** Производим запуск  клиентского приложения.
<p  align="center"><img  src=./image/№12.png></p>
<p  align="center">Рис. 5.Готовое клиенсткое приложение</p>

**Вывод:**
Через создание соревера и клиентского приложения должен пройти каждый программист, потому что все люди взаимодействуют с приложениями и необходимо понимать как они работают, отуда берут данные. В данной лабораторной работе я закрепил навыки разработки многофайловых приложений, изучил способы работы с API web-сервиса,процесс сериализации/десериализации данных в/из json, получил базовое представление о сетевом взаимодействии приложения.
Разработал сервис, который предоставляет данные о погоде в городе Симферополь на момент запроса.Разработал для клиентского приложения графический интерфейс, отображающий данные о погоде и возможность объявления их по требованию пользователя.