#pragma once
#define DIALOG_H
#include "practicewindow.h"
#include "trainheader.h"
class Dialog : public QDialog
{
    Q_OBJECT //макросс для включения метаобъектных функций
public:
    Dialog(); 
    QPoint myMove();
private:
    QPushButton *practice;    //режим теста
    QPushButton *training;    //режим обучения
    QPushButton *reference;   //справка
    QPushButton *exit;        //выход из программы
private slots:                //слоты нажатий кнопок
    void newPracticeWindow(); //режим практики
    void newTrainingWindow(); //режим обучения
    void refClicked();        //отображение справки
};
