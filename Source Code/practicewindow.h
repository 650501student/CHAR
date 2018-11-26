#pragma once
#define PRACTICEWINDOW_H
#include <QtWidgets>
#include "resswin.h"
class Test : public QWidget
{
    Q_OBJECT

public:
    Test();
    QStringList fileToList();       //перенос файла в массив строк
    QString select();               //выбор рандомного слова из массива строк
    QString beginningSelect();      //выбор слов при запуске режима практики
    void spaceEvent();
private:
    int wrongLetters, rightLetters; //количество (не)правильно введённых букв
    int rightWords, wrongWords;     //количество (не)правильно введённых слов
    int tmrRemainingSec;            //время на ввод
    QString str;                    //вся строка в label
    QLineEdit *inputField;          //поле ввода
    QLabel *timerLabel;             //label для таймера
    QLabel *label;                  //label для слов ввода
    QString filename;               //путь к файлу
    QTimer *tmr;                    //таймер
    QStringList sList;              //массив строк, в кот. переносится файл
private slots:
    void newResult();               //функция создания окна результата
    void inputLetterValidation();   //функция проверки нажатия пробела
    void updateTime();              //обновление времени каждую секунду
};
