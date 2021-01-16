<p  align="center">МИНИСТЕРСТВО НАУКИ И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ<br>
Федеральное государственное автономное образовательное учреждение высшего образования<br>
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"<br>
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ<br>
Кафедра компьютерной инженерии и моделирования</p>
<br>
<h3  align="center">Отчёт по лабораторной работе № 2<br> по дисциплине "Программирование"</h3>
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


## Цель работы
Целью работы является научится создавать навык для Алисы на сервисе Яндекс.Диалоги и сохранять данные в файлах Excel.

Директории:
[[C++]](./C++) [[Python]](./Python)

### Информация о проекте

Стандарт С++: `С++20`
<br>
Компилятор: `g++-10` (gcc v10.2.0)
<br>
ОС: `Windows 10`

Постановка задачи
--------------------------
1. Разработайте и зарегистрируйте навык для Алисы на сервисе Яндекс.Диалоги;

2. В качестве backend-a для навыка реализуйте приложение на языке С++ выполняющее следующие функции:
   1. Составление продуктовой корзины:
      * Добавление продукта в корзину;
      * Удаление продукта из корзины;
      * Очистка корзины;
      * Вывод списка товаров в корзине;
      * Подсчёт стоимости товаров в корзине.
   2. Вывод справочной информации по навыку;
   3. Регистрацию webhook-ов сторонних сервисов;
   4. Отправку данных на сторонние сервисы. 

3. В качестве стороннего сервиса реализуйте приложение на языке Python выполняющее следующие функции:
   1. Ожидание данных о покупке;
   2. Сохранение поступивших данных в excel-документ.

Выполнение работы
--------------------------
**1.** Подготовка серверной части 
Для работы с сетью я использовал библиотеку: [https://github.com/yhirose/cpp-httplib](https://github.com/yhirose/cpp-httplib). Также благодаря информации, которой дал нам преподаватель, я смог разобраться что такое post- запрос.
Предоставляю код серверной части. Начну с подключения библиотек:
```C++
#include <iostream>
#include <string>
#include <io.h>
#include <fstream>  
#include "include/cpp_httplib/httplib.h"
#include "include/cpp_httplib/json.hpp" 
using namespace std;
using namespace httplib;
using json = nlohmann::json;
//code
```
**1.1.** Следующим этапом  мы будем организовывать   взаимодействие  с подчинёнными сервисами посредством Webhook-ов. Для начала начнем с 
создания шаблонов и файлов:
```c++
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
    //code
```
**1.2.** Далее нам понадобиться разработать способ  регистрации  и удаления подключенных сервисов  во время работы сервера. 
<details><summary>Исходный код </summary>

```c++
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
    svr.Post("/webhooks", gen_response);          
    std::cout << "Start server... OK\n"; 
    svr.listen("localhost", 1234);        
}
```
</details>
<br>

**1.3.** Добавление подключенного сервиса :
<p  align="center"><img  src=./image/1.jpg></p>
<p  align="center">Рис. 1. Загрузка подключенного сервиса </p>

**1.4.** Удаление подключенного сервиса :
<p  align="center"><img  src=./image/2.jpg></p>
<p  align="center">Рис. 2. Удаление подключенного сервиса </p>

Подготовка к работе с сервисом Яндекс.Диалоги
----------------
Мне удалось войти в Яндекс.Диалоги, а также частично начать создавать навык о покупках, для этого я воспользовался приложением ngrok.exe и сайтом http://webhook.site 
<details><summary>Исходный код </summary>

```	C++
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
    Client cli("http://webhook.site");
    auto all = cli.Post("/853fdcd3-ffb8-473a-8a4b-659478b36bfc", R"({"Hello": "world"})", "text/json");
    if (all) {
        if (all->status == 200) {
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
//code
```
</details>
<br>

<p  align="center"><img  src=./image/4.jpg></p>
<p  align="center">Рис. 3. Ответ Алисы </p>






 Клиентское приложение 
 ---------------------------------
**1.** Для того чтобы создать клиентское приложение, необходимо было установить дополнительные подпрограммы(Flask, openpyxl). Подключение нужных библиотек: 
```Python 
from flask import Flask
from flask.globals import request
import openpyxl
import os.path
from datetime import datetime
#code
```
**2.**  Подключаем декоратор и обработчик, который определяет какой пришел запрос post или get :
```Python 
app = Flask(__name__)

file = os.path.abspath(os.path.dirname(__file__))

size_buffer = 0
buffer = []

@app.route('/', methods=['POST', 'GET'])
def index():
   global buffer
   
   if request.method == 'POST':
      
      buffer += [request.json]
      print('req.body:', buffer[-1])
      if (len(buffer) > size_buffer):
         excel()
         buffer = []
             
      return 'OK'
      
   elif request.method == 'GET':
      return 'Это GET запрос'
#code
```
**3.** Подключаем функцию, которая работает с json и создает файл data.xlsx:
```Python
def excel():
   global buffer
   
   STORAGE_FILE = os.path.join(file, 'data.xlsx')
   
   book = None
   if not os.path.exists(STORAGE_FILE):
      book = openpyxl.Workbook()
      book.active['A1'] = 'N'
      book.active['B1'] = 'User ID'
      book.active['C1'] = 'Datetime'
      book.active['D1'] = 'Item'
      book.active['E1'] = 'Prise'
      book.save(STORAGE_FILE)
   else:
      book = openpyxl.open(STORAGE_FILE)   
   sheet = book.active
   
   max_row = len(sheet['A'])
   
   row = max_row + 1
   for dataset in buffer:
      check = dataset['check']
      for item in check:
          sheet[row][0].value = row - 1
          sheet[row][1].value = dataset['user_id']
          sheet[row][2].value = datetime.now()
          sheet[row][3].value = item['item']        
          sheet[row][4].value = item['price']
          row += 1

   book.save(STORAGE_FILE)
   book.close()
   #code 
```
<details><summary>Исходный код </summary>

```Python 
from flask import Flask
from flask.globals import request
import openpyxl
import os.path
from datetime import datetime

app = Flask(__name__)

file = os.path.abspath(os.path.dirname(__file__))

size_buffer = 0
buffer = []

@app.route('/', methods=['POST', 'GET'])
def index():
   global buffer
   
   if request.method == 'POST':
      
      buffer += [request.json]
      print('req.body:', buffer[-1])
      if (len(buffer) > size_buffer):
         excel()
         buffer = []
         
         
      return 'OK'
      
   elif request.method == 'GET':
      return 'Это GET запрос'


def excel():
   global buffer
   
   STORAGE_FILE = os.path.join(file, 'data.xlsx')
   
   book = None
   if not os.path.exists(STORAGE_FILE):
      book = openpyxl.Workbook()
      book.active['A1'] = 'N'
      book.active['B1'] = 'User ID'
      book.active['C1'] = 'Datetime'
      book.active['D1'] = 'Item'
      book.active['E1'] = 'Prise'
      book.save(STORAGE_FILE)
   else:
      book = openpyxl.open(STORAGE_FILE)   
   sheet = book.active
   
   max_row = len(sheet['A'])
   
   row = max_row + 1
   for dataset in buffer:
      check = dataset['check']
      for item in check:
          sheet[row][0].value = row - 1
          sheet[row][1].value = dataset['user_id']
          sheet[row][2].value = datetime.now()
          sheet[row][3].value = item['item']        
          sheet[row][4].value = item['price']
          row += 1

   book.save(STORAGE_FILE)
   book.close()

if __name__ == '__main__':
   app.run()
#code 
```
</details>
<br>

<p  align="center"><img  src=./image/3.jpg></p>
<p  align="center">Рис. 4. Файл excel </p>

 **Вывод:** Большинство поставленных задачи  было выполнено, а цель работы  практически достигнута, хоть у меня не получилось доделать лабораторную работу верно, все равно я получил полезные навыки, которые пригодятся мне в будущем. Мной было разработано приложение, выполняющее составление списка продуктов и подсчет суммарной стоимости чека.
 
 Разработка сервера была выполнена с использованием сторонних библиотек: json для работы с json и cpp-httplib для работы с http запросами. Клиент использует такие библиотеки как: Flask - для того чтобы слушать POST запросы, openpyxl - для работы с файлами xlsx.
