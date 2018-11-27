#include "resaultwindow.h"
rwin::rwin(int rl, int wl, int rw, int ww)
{
    l_score = rl;
    l_mistakes = wl;
    w_score = rw;
    w_mistakes = ww;

    setWindowTitle("Your result");
    setFixedSize(250,150);

    ok = new QPushButton("&Ok");
    again = new QPushButton("&Retry");
    l_sc = new QLabel("Keystrokes: " + QString::number(l_score) + " | " + QString::number(l_mistakes));
    w_sc = new QLabel("Words: " + QString::number(w_score) + " | " +  QString::number(w_mistakes));

    QVBoxLayout *lout = new QVBoxLayout;
    lout->addWidget(l_sc);
    lout->addWidget(w_sc);
    lout->addWidget(again);
    lout->addWidget(ok);
    setLayout(lout);

    connect(ok,SIGNAL(clicked()),this,SLOT(newMenuWindow()));
    //блокируются сигналы нажатия кнопки again
    again->blockSignals(true);
    //задержка чтобы пользователь случайно не нажал пробел и не потерял результаты
    QTimer::singleShot(2000, this, SLOT(waiting()));
    connect(again,SIGNAL(clicked()),this,SLOT(newPracticeWindow()));
}

void rwin::newMenuWindow()
{
    Dialog *d = new Dialog;
    d->show();
    this->close();
}

void rwin::newPracticeWindow()
{
    Test *t = new Test;
    t->show();
    t->setFixedSize(700,450);
    t->move(myMove());
    this->close();
}

void rwin::waiting()
{
    again->blockSignals(false); //отмена блока сигнала с кнопки again
}

QPoint rwin::myMove()
{
    QPoint p;               //описывает точку на плоскости
    p.setX(p.x()+400);      //перемещение по оси x
    p.setY(p.y()+100);      //по оси y
    return p;
}
