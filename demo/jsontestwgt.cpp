#include "jsontestwgt.h"
#include "ui_jsontestwgt.h"

#include <QDebug>
#include "json.hpp"

JsonTestWgt::JsonTestWgt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JsonTestWgt)
{
    ui->setupUi(this);

    initTest();
}

JsonTestWgt::~JsonTestWgt()
{
    delete ui;
}

void JsonTestWgt::initTest()
{

}

void JsonTestWgt::on_generateBtn_clicked()
{
    nlohmann::ordered_json ojson;
    ojson["os"] = "Windows";
    ojson["os_version"] = "10.0.10.0";
    ojson["client"] = "WinApp";
    ojson["client_version"] = "1.2.3.4";

    std::string strJson = ojson.dump();
    ui->jsonTextEdit->clear();
    ui->jsonTextEdit->append(QString::fromStdString(strJson));
}

void JsonTestWgt::on_parseBtn_clicked()
{
    std::string strJson = ui->jsonTextEdit->toPlainText().toStdString();

    try
    {
        nlohmann::json json = nlohmann::json::parse(strJson);

        ui->stringTextEdit->clear();

        if (json.contains("os") && json["os"].is_string()) {
            std::string os = json["os"];
            ui->stringTextEdit->append(QString("Find Key = %1 Type = %2 Value = %3").arg("os").arg("string").arg(QString::fromStdString(os)));
        }

        if (json.contains("os_version") && json["os_version"].is_string()) {
            std::string os_version = json["os_version"];
            ui->stringTextEdit->append(QString("Find Key = %1 Type = %2 Value = %3").arg("os_version").arg("string").arg(QString::fromStdString(os_version)));
        }

        if (json.contains("client") && json["client"].is_string()) {
            std::string client = json["client"];
            ui->stringTextEdit->append(QString("Find Key = %1 Type = %2 Value = %3").arg("client").arg("string").arg(QString::fromStdString(client)));
        }

        if (json.contains("client_version") && json["client_version"].is_string()) {
            std::string client_version = json["client_version"];
            ui->stringTextEdit->append(QString("Find Key = %1 Type = %2 Value = %3").arg("client_version").arg("string").arg(QString::fromStdString(client_version)));
        }
    }
    catch (nlohmann::json::parse_error& e)
    {
        qDebug() << "\n nlohmann::json::parse_failed: "
                        << "\n source = " << QString::fromStdString(strJson)
                        << "\n reason = "<< e.what() << "\n ";
        return;
    }
}

