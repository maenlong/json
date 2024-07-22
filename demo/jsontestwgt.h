#ifndef JSONTESTWGT_H
#define QAESTESTWGT_H

#include <QWidget>

namespace Ui {
class JsonTestWgt;
}

class JsonTestWgt : public QWidget
{
    Q_OBJECT

public:
    explicit JsonTestWgt(QWidget *parent = nullptr);
    ~JsonTestWgt();

    void initTest();    //初始化测试，原程序启动入口示例

private slots:
    void on_generateBtn_clicked();      //生成json测试
    void on_parseBtn_clicked();     //解析json测试

private:
    Ui::JsonTestWgt *ui;
};

#endif // JSONTESTWGT_H
