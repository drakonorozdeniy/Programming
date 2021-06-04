#include "httplib.h"
#include <QCoreApplication>
#include <QTime>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

using namespace httplib;

void log(QString str){
    qDebug().noquote() << QString("[%1] %2").arg(QTime::currentTime().toString(), str);
}

QJsonArray gloabalJson;

void gen_response(const Request& req, Response& res) {
    log("Получили POST запрос");
    if (req.has_param("username") && req.has_param("score")) {

        QString name = QString::fromUtf8(req.get_param_value("username"));
        double value1 = QString::fromUtf8(req.get_param_value("score")).toDouble();
        log("Получены параметры: ");
        log(name);
        log(QString().number(value1));

        QJsonObject temp;
        temp.insert("username", QJsonValue::fromVariant(name));
        temp.insert("score", value1);
        gloabalJson.push_back(temp);
        log("Новые данные успешно добавлены");

        res.set_content("OK", "text/plain; charset=UTF-8");
    }
    else {
        log("В запросе не все параметры");
        res.set_content("Ooppsss", "text/plain; charset=UTF-8");
    }
}

void gen_response_get(const Request& req, Response& res) {
    log("Получили GET запрос");
    QJsonDocument doc(gloabalJson);
    log("Отправляем все накопленные данные");
    log(doc.toJson());
    res.set_content(doc.toJson().data(), "text/plain; charset=UTF-8");
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    setlocale(LC_ALL, "");
    Server svr;
    svr.Post("/", gen_response);
    svr.Get("/", gen_response_get);
    log("Сервер запущен");
    svr.listen("localhost", 3000);

    return a.exec();
}

