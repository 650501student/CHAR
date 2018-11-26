#include "practicewindow.h"

Test::Test()
{
    tmrRemainingSec = 60;                           //количество секунд
    filename = "C:/engwords.txt";
    sList = fileToList();                           //перенос словаря из файла в массив строк
    rightLetters = wrongLetters = 0;
    rightWords = wrongWords = 0;

    QTime midnight(0, 0, 0);                        //QTime для автоматической рандомизации
    qsrand(midnight.secsTo(QTime::currentTime()));  //использование системных часов
    setStyleSheet("background-color:white;");
    setWindowTitle("Good luck have fun");

    label = new QLabel;
    label->setText(beginningSelect());              //добавление случайных слов в label
    label->setFixedHeight(70);

    timerLabel = new QLabel;
    timerLabel->setText("Time: " + QString::number(tmrRemainingSec));
    timerLabel->setFixedHeight(70);

    inputField = new QLineEdit;
    inputField->setFixedHeight(70);
    QVBoxLayout *lay = new QVBoxLayout;
    lay->addWidget(timerLabel);
    lay->addWidget(label);
    lay->addWidget(inputField);
    setLayout(lay);

    //сигнал textEdited не вызывается при изменении строки программно
    connect(inputField,SIGNAL(textEdited(QString)), this, SLOT(inputLetterValidation()));

    tmr = new QTimer;
    tmr->setInterval(1000);
    connect(tmr, SIGNAL(timeout()), this, SLOT(updateTime()));
    tmr->start();
    QTimer::singleShot(tmrRemainingSec*1000, this, SLOT(newResult()));
}

QStringList Test::fileToList()
{
    QFile file(filename);
    try{
        if(!file.open(QFile::ReadOnly | QFile::Text))
            {
                QString *exception=new QString("Can't open file!");
                throw exception;
            }
    }
    catch(QString *ex)
    {
        file.close();
        QMessageBox::warning(0,"Warning", ex->toLocal8Bit().constData());
        exit(0);
    }
    QTextStream tStream(&file);
    while (1)
    {
        QString line = tStream.readLine();  //считывание строки из tStream
        if (line.isNull())                  //если строка пустая
            break;                          //выход из цикла
        else
            sList.append(line);             //добавление строки
    }
    file.close();                           //закрытие файла
    return sList;                           //возвращение массива строк
}

QString Test::select()
{
    QString tmp(sList.at(rand()%2999)); //tmp содержит случайную строку
    return tmp + " ";                   //добавление пробелов между словами и возвращение строки
}

QString Test::beginningSelect()
{
    for(int i=0;i<20;i++)       //цикл вывода 20-и слов
        str.append(select());   //добавление нового слова
    return str;
}

void Test::newResult()
{
    rwin *rw = new rwin(rightLetters, wrongLetters, rightWords, wrongWords);
    rw->show();
    this->close();
}

void Test::inputLetterValidation()  //сравнение слов
{
    QString ae = inputField->text();//запись в QString ae текста из lineedit
    ae = ae.right(1);               //последний введённый в lineedit символ
    if(ae == " ")                   //если клавиша пробел
        spaceEvent();
}
void Test::spaceEvent() //нажатие на пробел - сравенение введённого и переход к следующему слову
{
    QString t = label->text();      //в строку st2 записывается содержимое label'а
    int s = t.indexOf(" ", 0);      //нахождение индекса первого пробела(также длина слова)
    QString word = t.left(s+1);     //в word хранится первое слово с пробелом
    if(inputField->text() == word)  //если введено правильно
    {
        rightLetters += s;          //введённые буквы + кол-во букв в слове
        rightWords++;
    }
    else
    {
        wrongLetters += s;
        wrongWords++;
    }
    t = t.mid(s+1);         //записывается строка без первого слова и пробела
    t.append(select());     //в конце добавляется рандомное слово из словаря
    label->setText(t);      //в label записывается строка
    inputField->clear();    //чистка lineedit'а для последующего ввода
}

void Test::updateTime()
{
    --tmrRemainingSec;          //оставшееся время -1
    if ( tmrRemainingSec > 0)   //если ещё есть время
        timerLabel->setText("Time: " + QString::number(tmrRemainingSec));
    else
    tmr->stop();
}

