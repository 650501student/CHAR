#pragma once
#define TRAINHEADER_H
#include <QtWidgets>
#include "dialog.h"
class Training : public QWidget
{
    Q_OBJECT

public:
    Training();
    QStringList fileToList();
    QString trainSelect();      //подстановка случайных букв в строку
    bool checkEndOfStrList();   //проверка на пройденность всех этапов
    void newMenuWindow();       //выход в меню
    void setAll();              //переход на следующий уровень
private:
    int currentLevel;           //уровень
    QLabel *label;
    QLabel *nameLevel;
    QLineEdit *inputField;      //строка ввода
    QPushButton *hintButton;    //кнопка подсказки
    QString filename;
    QStringList sList;
public slots:
    void hintClicked();
    void inputValidation();
};
