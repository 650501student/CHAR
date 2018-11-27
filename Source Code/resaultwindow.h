#pragma once
#define RESSWIN_H
#include <QtWidgets>
#include "practicewindow.h"
#include "dialog.h"
class rwin : public QDialog
{
    Q_OBJECT
public:
    rwin(int rl = 0, int wl = 0, int rw = 0, int ww = 0);

private:
    int l_score, l_mistakes, w_score, w_mistakes;
    QPushButton *ok;        //выход в меню
    QPushButton *again;     //рестарт режима практики
    QLabel *l_sc, *w_sc;
    QTimer *tmr;
    QStringList li;
    QString *filename;

private slots:
    void newMenuWindow();       //выход в меню
    void newPracticeWindow();   //рестарт режима практики
    void waiting();             //блокирование сигналов на протяжении 2-ух секунд
};
