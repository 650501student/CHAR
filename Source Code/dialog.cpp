#include "dialog.h"
Dialog::Dialog()
{
    setWindowTitle("Typing trainer");
    setFixedSize(220,150);

    practice = new QPushButton("&Practice");    //& -> Alt + P
    training = new QPushButton("&Training");    //& -> Alt + T
    reference = new QPushButton("&Reference");  //& -> Alt + R
    exit = new QPushButton("&Exit");    //& -> Alt + E

    //Cоединение сигналов со слотами
    connect(practice,SIGNAL(clicked()),this,SLOT(newPracticeWindow()));
    connect(training,SIGNAL(clicked()),this,SLOT(newTrainingWindow()));
    connect(reference,SIGNAL(clicked()),this,SLOT(refClicked()));
    connect(exit,SIGNAL(clicked()),this,SLOT(close()));
    QVBoxLayout *layout = new QVBoxLayout;

    //Добавление виджетов в вертикальный слой
    layout->addWidget(practice);
    layout->addWidget(training);
    layout->addWidget(reference);
    layout->addWidget(exit);
    setLayout(layout);
}
void Dialog::refClicked()
{
    QMessageBox *mBox = new QMessageBox(QMessageBox::Information,
                                        "Reference"," The program includes two modes: "
                                                    "the training mode and the test mode "
                                                    "for the print speed. During the "
                                                    "test, the time is counted, as well "
                                                    "as the statistics of speed and number of errors.\n "
                                                    " In practice mode, there is 60 seconds of time to enter text. "
                                                    "To go to the next word, press the space key.\n"
                                                    " Training mode. If you enter the specified string "
                                                    "incorrectly, you can not go to the next level. "
                                                    "The time is not counted in this mode.");
    mBox->exec();
}
void Dialog::newPracticeWindow()
{
    Test *test = new Test;
    test->show();
    test->setFixedSize(700,450);    //фиксированный размер окна
    test->move(myMove());           //перемещение окна на экране
    this->close();                  //закрытие текущего окна
}
void Dialog::newTrainingWindow()
{
    /*Training *training = new Training;
    training->show();
    training->setFixedSize(700,450);
    training->move(myMove());
    this->close();*/
}
QPoint Dialog::myMove()
{
    QPoint p;               //описывает точку на плоскости
    p.setX(p.x()+400);      //перемещение по оси x
    p.setY(p.y()+100);      //по оси y
    return p;
}
