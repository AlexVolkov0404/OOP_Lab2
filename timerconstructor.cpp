#include "timerconstructor.h"

TimerConstructor::TimerConstructor()
{

}
void TimerConstructor::showConstructorWindow(QList<Timer> *timers,QListWidget *listW){
    addWindow = new QWidget();
    addWindow->resize(250,200);
    addWindow->setWindowTitle("New Timer");
    addTimerLbl = new QLabel("Time");
    addTimerLbl->setGeometry(20,60,50,20);
    addTimeEdit = new QTimeEdit();
    addTimeEdit->setDisplayFormat("hh:mm:ss");
    addTimeEdit->setGeometry(90,65,100,25);
    addDescLbl = new QLabel("Description");
    addDescLbl->setGeometry(20, 100, 50, 20);
    addTextEdit = new QTextEdit();
    addTextEdit->setGeometry(90,130,100,150);
    addCountLbl = new QLabel("Count of timers");
    amountTimer=new QSpinBox();
    amountTimer->setGeometry(90,130,10,150);
    amountTimer->setMinimum(1);
    addCountTextEdit = new QTextEdit();
    addPathsLbl = new QLabel("Paths of the document");
    addPathsTextEdit = new QTextEdit();
    addBtn = new QPushButton("Set Timer",addWindow);
    addWindow->setLayout(new QVBoxLayout());
    addWindow->layout()->addWidget(addTimerLbl);
    addWindow->layout()->addWidget(addTimeEdit);
    addWindow->layout()->addWidget(addDescLbl);
    addWindow->layout()->addWidget(addTextEdit);
    addWindow->layout()->addWidget(addCountLbl);
   // addWindow->layout()->addWidget(addCountTextEdit);
    addWindow->layout()->addWidget(amountTimer);
    addWindow->layout()->addWidget( addPathsLbl);
    addWindow->layout()->addWidget(addPathsTextEdit);
    addWindow->layout()->addWidget(addBtn);

    connect(addBtn, &QPushButton::clicked,this, [=](){addNewTimer(timers,listW);});
    //connect(addBtn, &QPushButton::clicked, this, &MainWindow::addTimerBtnClicked);
    addWindow->show();
}
void TimerConstructor::addNewTimer(QList<Timer> *timers,QListWidget *listW){
    QTime time(addTimeEdit->time().hour(),addTimeEdit->time().minute(),addTimeEdit->time().second());
    Timer timer(time,addTextEdit->toPlainText(),addPathsTextEdit->toPlainText());
    //listW->clear();
    for(int i = 0; i < amountTimer->value(); i++){
        timers->insert(timers->size(),timer);
        listW->addItem(timer.getTime().toString());
    }
    addWindow->close();
    timersort(*timers);
}
void TimerConstructor::timersort(QList<Timer> &timers){
    if(timers.size() > 1) {
        int i, j;
        for (i = 0; i < timers.size()-1; i++)
        for (j = 0; j < timers.size()-i-1; j++){
            if (timers[j].getTime() > timers[j+1].getTime()){
                Timer tmp = timers[j];
                timers[j] = timers[j+1];
                timers[j+1] = tmp;
            }
        }
    } else return;
}
