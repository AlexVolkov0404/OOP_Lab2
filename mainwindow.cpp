#include "mainwindow.h"
#include <QDebug>
#include <QScrollBar>
#include <QPushButton>
#include <iostream>

MainWindow::MainWindow()
{
//    doNotLbl = new QLabel("Do not disturbe mode");
//    doNotCheckBox = new QCheckBox();
//    doNotCheckBox->setChecked(false);
//    doNotDisturb = false;

    tmp = "\0";
    temp.setHMS(0,0,0);  
    setToolBar();
    settings.setsettingswindow();
    QLabel *tmr = new QLabel("Nearest Timer",this);
    tmr->setGeometry(50,85,100,20);
    mainTimerLbl = new QLabel(this);
    mainTimerLbl->setText("00:00:00");
    mainTimerLbl->setGeometry(40,100,130,40);

    QFont font = mainTimerLbl->font();
    font.setPixelSize(32);
    mainTimerLbl->setFont(font);

    QLabel *desc = new QLabel("Description",this);
    desc->setGeometry(260,60,70,20);

    mainTimerDescriptionLbl = new QTextEdit(this);
    mainTimerDescriptionLbl->setGeometry(250,80,230,100);
    mainTimerDescriptionLbl->setReadOnly(true);

    QLabel *tmrslbl = new QLabel("Timers",this);
    tmrslbl->setGeometry(40,205,50,20);

    QScrollBar *sbt = new QScrollBar(Qt::Vertical);
    QScrollBar *sba = new QScrollBar(Qt::Vertical);

    listW = new QListWidget(this);
    listW->setVerticalScrollBar(sbt);
    listW->setGeometry(30,225,200,200);

    QLabel *alarmlbl = new QLabel("Alarm-clocks",this);
    alarmlbl->setGeometry(280,205,100,20);

    listB= new QListWidget(this);
    listB->setVerticalScrollBar(sba);
    listB->setGeometry(270,225,200,200);


    connect(listW, &QListWidget::currentRowChanged, this, &MainWindow::showDescription);
   // listW->clearSelection();
    connect(listB, &QListWidget::currentRowChanged, this, &MainWindow::showDescriptionAlarm);
    startTimer(1000);






}

void MainWindow::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e);

    figure= QString::number(timers.size());
    QPixmap pixmap(25,25);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.drawPixmap(0, 0,25,25, QPixmap(":/Resources/clock.jpg"));
    painter.setPen(QPen(Qt::white, 1, Qt::SolidLine, Qt::SquareCap));
    painter.setBrush(QBrush(Qt::red));
    if(timers.size()>0){
        painter.drawEllipse(10, 10, 16, 16);
        QFont font1("MS Shell Dlg 2", 8);
        painter.setFont(font1);
        painter.drawText(QRect(10, 13, 18, 13), Qt::AlignCenter, figure);
    }
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.end();
    setWindowIcon(QIcon(pixmap));



    timelbl->setText(QTime::currentTime().toString());
    settings.sortInfo(timers);
    settings.sortInfo(alarms);
    if(timers.size() > 0 && listW->count()>0){
        for(int i = 0; i < timers.size(); i++){
            timers[i].setTime(timers[i].getTime().addMSecs(-500));
            listW->item(i)->setText(timers[i].getTime().toString());
        }
//        if(!stoppedTimersPositions.empty()){
//            for(int i = 0; i < stoppedTimersPositions.size(); i++){
//                timers[stoppedTimersPositions[i]].setTime(timers[stoppedTimersPositions[i]].getTime().addMSecs(500));
//            }
//        }
        mainTimerLbl->setText(timers[0].getTime().toString());

        for(int i = 0; i < timers.size(); i++){
            if(timers[i].getTime() == temp){
               // timeoutwindow(timers[i].getDesc(),timers[i].getPaths());
                wind.signalsound(timers[i].getDesc(),timers[i].getPaths());
               if(settings.infoOk()==false) wind.sound();
                mainTimerDescriptionLbl->setText("\0");
                //stoppedTimersPositions.append(i);
                timers.removeAt(i);
                listW->clearSelection();
                QListWidgetItem *it = listW->takeItem(i);
                   delete it;
            }
        }
    }


    if(alarms.size() > 0 && listB->count()>0){
        qDebug() << QTime::currentTime() << Qt::endl;
        qDebug() << alarms[0].getTime() << Qt::endl;
        for(int i = 0; i < alarms.size(); i++){
            listB->item(i)->setText(alarms[i].getTime().toString());
        }
        for(int i = 0; i < alarms.size(); i++){
            if(alarms[i].getTime().hour() == QTime::currentTime().hour()&&alarms[i].getTime().minute() == QTime::currentTime().minute()&&alarms[i].getTime().second() == QTime::currentTime().second()){
                wind.signalsound(alarms[i].getDesc(),alarms[i].getPaths());
               if(settings.infoOk()==false) wind.sound();
                //timeoutWindowAlarm();
                //timeoutwindow wind(alarms[0].getDesc(),alarms[0].getPaths());
                //if(settings.infoOk()==false)  wind.signalsound();
                //stoppedAlarmsPositions.append(i);
                alarms.removeAt(i);
                QListWidgetItem *it2 = listB->takeItem(i);
                   delete it2;
            }
        }
    }
}


void MainWindow::setToolBar()
{
    QPixmap addpix(":/Resources/add.png");
    QPixmap editpix(":/Resources/edit.png");
    QPixmap deletepix(":/Resources/delete.png");
    QPixmap deleteallpix(":/Resources/deleteAll.png");
    QPixmap infopix(":/Resources/info.png");
   // QPixmap stoppix(":/Resources/stop.jpg");
    QPixmap currenttime(":/Resources/clock.jpg");

    toolbar = addToolBar("Main Toolbar");
    toolbar->setFixedHeight(40);
    toolbar->setStyleSheet("QToolBar{spacing:10px;}");
    toolbar->addSeparator();

    QMenu *file;
    file = menuBar()->addMenu(QIcon(addpix),"&ADD");
    QAction *add = addAction("New Timer");
    QAction *addAlarm = addAction("New Alarm");
      file->addAction(add);
      file->addAction(addAlarm);
    //QAction *stop = toolbar->addAction(QIcon(stoppix),"Stop timer");
    // toolbar->addSeparator();


     QMenu *edt;
     edt = menuBar()->addMenu(QIcon(editpix),"&EDIT");
    QAction *edit = addAction("edit Timer");
    QAction *editAlarm = addAction("edit Alarm");
    edt->addAction(edit);
    edt->addAction(editAlarm);

     QMenu *del;
     del = menuBar()->addMenu(QIcon(deletepix),"&DEL");
    QAction *dlete = addAction("Delete Timer");
    QAction *dleteAlarm = addAction("Delete Alarm");
    del->addAction(dlete);
    del->addAction(dleteAlarm);

    QMenu *delALL;
    delALL = menuBar()->addMenu(QIcon(deleteallpix),"&DELALL");
   QAction *dleteAll = addAction("Delete All Timers");
   QAction *dleteAlarmAll = addAction("Delete All Alarms");
   delALL->addAction(dleteAll);
   delALL->addAction(dleteAlarmAll);

    QAction *info = toolbar->addAction(QIcon(infopix),"Timer's Info");
    toolbar->setMovable(false);
    toolbar->addSeparator();

    toolbar->addAction(QIcon(currenttime),"Current time: ");
    timelbl = new QLabel(QTime::currentTime().toString());
    startTimer(1000);
    toolbar->addWidget(timelbl);

   // connect(add, &QAction::triggered, this, &MainWindow::addTimer);
   // connect(addAlarm, &QAction::triggered, this, &MainWindow::addAlarm);

   // connect(edit, &QAction::triggered, this, &MainWindow::toEditWindow);
    // connect(editAlarm, &QAction::triggered, this, &MainWindow::toEditWindowAlarm);

    //connect(dlete, &QAction::triggered, this, &MainWindow::deleteTimer);
    //connect(dleteAlarm, &QAction::triggered, this, &MainWindow::deleteAlarm);

    //connect(dleteAll, &QAction::triggered, this, &MainWindow::deleteAllTimers);
   // connect(dleteAlarmAll, &QAction::triggered, this, &MainWindow::deleteAllAlarms);

    connect(info, &QAction::triggered,&settings,&Settings::showSettingsWindow);



    connect(edit, &QAction::triggered, &econstructor, [=](){econstructor.showEditWindow(&timers,listW);});
    connect(add, &QAction::triggered, &constructr, [=](){constructr.showConstructorWindow(&timers,listW);});
    connect(dlete,&QAction::triggered,&delet,[=](){delet.delChosenTimer(&timers,listW,mainTimerLbl,mainTimerDescriptionLbl);});
    connect(dleteAll,&QAction::triggered,&delet,[=](){delet.delAllTimers(&timers,listW,mainTimerLbl,mainTimerDescriptionLbl);});

    connect(editAlarm, &QAction::triggered, &econstructor, [=](){econstructor.showEditWindow(&alarms,listB);});
    connect(addAlarm, &QAction::triggered, &constructr, [=](){constructr.showConstructorWindow(&alarms,listB);});
    connect(dleteAlarm,&QAction::triggered,&delet,[=](){delet.delChosenTimer(&alarms,listB,mainTimerLbl,mainTimerDescriptionLbl);});
    connect(dleteAlarmAll,&QAction::triggered,&delet,[=](){delet.delAllTimers(&alarms,listB,mainTimerLbl,mainTimerDescriptionLbl);});





}










//done1
void MainWindow::addTimer()
{
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

    QPushButton *addBtn = new QPushButton("Set Timer",addWindow);

    // Добавим на окно менеджер вертикального расположения элементов
    addWindow->setLayout(new QVBoxLayout());
    // А теперь, при помощи менеджера расположения, добавим сами виджеты на окно
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

    connect(addBtn, &QPushButton::clicked, this, &MainWindow::addTimerBtnClicked);
    addWindow->show();
}
//void MainWindow::addAlarm()
//{
//    addWindowAlarm = new QWidget();
//    addWindowAlarm->resize(250,200);
//    addWindowAlarm->setWindowTitle("New Alarm");

//    addAlarmLbl = new QLabel("Time");
//    addAlarmLbl->setGeometry(20,60,50,20);

//    addTimeEditAlarm = new QTimeEdit();
//    addTimeEditAlarm->setDisplayFormat("hh:mm:ss");
//    addTimeEditAlarm->setGeometry(90,65,100,25);

//    addDescLblAlarm = new QLabel("Description");
//    addDescLblAlarm->setGeometry(20, 100, 50, 20);

//    addTextEditAlarm = new QTextEdit();
//    addTextEditAlarm->setGeometry(90,130,100,150);

//    addCountLblAlarm = new QLabel("Count of alarms");
//    amountTimerAlarm=new QSpinBox();
//    amountTimerAlarm->setGeometry(90,130,10,150);
//    amountTimerAlarm->setMinimum(1);

//    addCountTextEditAlarm = new QTextEdit();

//    addPathsLblAlarm = new QLabel("Paths of the program");
//    addPathsTextEditAlarm = new QTextEdit();

//    QPushButton *addBtnAlarm = new QPushButton("Set Alarm",addWindowAlarm);

//    // Добавим на окно менеджер вертикального расположения элементов
//    addWindowAlarm->setLayout(new QVBoxLayout());
//    // А теперь, при помощи менеджера расположения, добавим сами виджеты на окно
//    addWindowAlarm->layout()->addWidget(addAlarmLbl);
//    addWindowAlarm->layout()->addWidget(addTimeEditAlarm);
//    addWindowAlarm->layout()->addWidget(addDescLblAlarm);
//    addWindowAlarm->layout()->addWidget(addTextEditAlarm);
//    addWindowAlarm->layout()->addWidget(addCountLblAlarm);
//    addWindowAlarm->layout()->addWidget(amountTimerAlarm);
//    addWindowAlarm->layout()->addWidget( addPathsLblAlarm);
//    addWindowAlarm->layout()->addWidget(addPathsTextEditAlarm);
//    addWindowAlarm->layout()->addWidget(addBtnAlarm);

//    connect(addBtnAlarm, &QPushButton::clicked, this, &MainWindow::addAlarmBtnClicked);
//    addWindowAlarm->show();
//}
//done1
//

//done2
void MainWindow::toEditWindow()
{
    if(listW->currentRow()>=0&&listW ->item(listW->currentRow())->isSelected()){
        if(!timers.empty()){
            tmp = listW->selectedItems().first()->text();
            if(tmp == "\0"){
                QMessageBox::warning(this,tr("Choose the timer"),tr("Please, choose the timer in Timers tab"));
                return;
            }
        } else {
            QMessageBox::warning(this,tr("Timers is empty"),tr("Timers is empty"));
            return;
        }

        for(int i = 0; i < timers.size(); i++){
            if(tmp == timers[i].getTime().toString()){
                positionToEdit = i;
                buffer.setTime(timers[i].getTime());
                buffer.setDesc(timers[i].getDesc());
            }
        }
        editWindow = new QWidget();
        editWindow->resize(200,250);
        editWindow->setObjectName("Edit Timers");

        QVBoxLayout *vbox = new QVBoxLayout();

        editTimeLbl = new QLabel("Edit time:");
        editDescLbl = new QLabel("Edit description:");
        editTimeEdit = new QTimeEdit();
        editTimeEdit->setDisplayFormat("hh:mm:ss");
        editTimeEdit->setTime(timers[positionToEdit].getTime());
        editDescEdit = new QTextEdit();
        editTimerBtn = new QPushButton("OK");

        vbox->addWidget(editTimeLbl);
        vbox->addWidget(editTimeEdit);
        vbox->addWidget(editDescLbl);
        vbox->addWidget(editDescEdit);
        vbox->addWidget(editTimerBtn);

        connect(editTimerBtn, &QPushButton::clicked, this, &MainWindow::editTimerBtnClicked);
        editWindow->setLayout(vbox);
        editWindow->show();
    }
    else{
        QMessageBox::warning(this,tr("Choose the timer"),tr("Please, choose the timer in Timers tab"));
        return;
    }

}
//void MainWindow::toEditWindowAlarm(){
//    if(listB->currentRow()>=0&&listB->item(listB->currentRow())->isSelected()){
//        if(!alarms.empty()){
//            tmpAlarm = listB->selectedItems().first()->text();
//            if(listB->currentRow()<0){
//                QMessageBox::warning(this,tr("Choose the alarm"),tr("Please, choose the alarm in Alarms tab"));
//                return;
//            }
//        } else {
//            QMessageBox::warning(this,tr("Alarms is empty"),tr("Alarms is empty"));
//            return;
//        }

//        for(int i = 0; i < alarms.size(); i++){
//            if(tmp == alarms[i].getTimeAlarm().toString()){
//                positionToEditAlarm = i;
//                bufferAlarm.setTimeAlarm(alarms[i].getTimeAlarm());
//                bufferAlarm.setDescAlarm(alarms[i].getDescAlarm());
//            }
//        }
//        editWindowAlarm = new QWidget();
//        editWindowAlarm->resize(200,250);
//        editWindowAlarm->setObjectName("Edit Timers");

//        QVBoxLayout *vboxAlarm = new QVBoxLayout();

//        editTimeLblAlarm = new QLabel("Edit time:");
//        editDescLblAlarm = new QLabel("Edit description:");
//        editTimeEditAlarm = new QTimeEdit();
//        editTimeEditAlarm->setDisplayFormat("hh:mm:ss");
//        editDescEditAlarm = new QTextEdit();
//        editTimerBtnAlarm = new QPushButton("OK");

//        vboxAlarm->addWidget(editTimeLblAlarm);
//        vboxAlarm->addWidget(editTimeEditAlarm);
//        vboxAlarm->addWidget(editDescLblAlarm);
//        vboxAlarm->addWidget(editDescEditAlarm);
//        vboxAlarm->addWidget(editTimerBtnAlarm);

//        connect(editTimerBtnAlarm, &QPushButton::clicked, this, &MainWindow::editAlarmBtnClicked);
//        editWindowAlarm->setLayout(vboxAlarm);
//        editWindowAlarm->show();
//    }
//    else{
//        QMessageBox::warning(this,tr("Choose the alarm"),tr("Please, choose the alarm in Alarms tab"));
//        return;
//    }
//}
//done2

//
//done1
void MainWindow::addTimerBtnClicked()
{
    QTime time(addTimeEdit->time().hour(),addTimeEdit->time().minute(),addTimeEdit->time().second());
    Timer timer(time,addTextEdit->toPlainText(),addPathsTextEdit->toPlainText());
    //listW->clear();
    for(int i = 0; i < amountTimer->value(); i++){
       // timers.append(timer);

        timers.insert(timers.size(),timer);
        listW->addItem(timer.getTime().toString());
        // qDebug()<<timers.size();
    }
    addWindow->close();
    timersSort();

    if(timers.empty()){
        mainTimerLbl->setText("00:00:00");
        mainTimerDescriptionLbl->setText(" ");
    } else {
        //mainTimerLbl->setText(timers[0].getTime().toString());

    }
    //updateTimersListW();
    qDebug()<<"timers.size()";
}
//void MainWindow::addAlarmBtnClicked()
//{
//    QTime timeAlarm(addTimeEditAlarm->time().hour(),addTimeEditAlarm->time().minute(),addTimeEditAlarm->time().second());
//    Alarm alarm(timeAlarm,addTextEditAlarm->toPlainText(),addPathsTextEditAlarm->toPlainText());
//    for(int i = 0; i < amountTimerAlarm->value(); i++){
//        alarms.insert(alarms.size(),alarm);

//        listB->addItem(alarm.getTimeAlarm().toString());
//    }
//    addWindowAlarm->close();
//    //timersSort();
//    //if(timers.empty()){
//        //mainTimerLbl->setText("00:00:00");
//        //mainTimerDescriptionLbl->setText(" ");
//   // } else {
//       // mainTimerLbl->setText(timers[0].getTime().toString());
//       // mainTimerDescriptionLbl->setText(timers[0].getDesc());
//   // }
//    //updateTimersListW();
//   // updateAlarmsListB();
//}
//done1
//

void MainWindow::stopTimer()
{
//    for(int i = 0; i < timers.size(); i++){
//        if(timers[i].getTime().toString() == listW->selectedItems().first()->text()){
//            if(!stoppedTimersPositions.empty()){
//                for(int j = 0; j < stoppedTimersPositions.size(); j++){
//                    if(i != stoppedTimersPositions[j]){
//                        stoppedTimersPositions.append(i);
//                    } else {
//                        stoppedTimersPositions.removeAt(j);
//                    }
//                }
//             } else
//                 stoppedTimersPositions.append(i);
//        }
//    }


}

//done2
void MainWindow::editTimerBtnClicked()
{
    QTime time(editTimeEdit->time().hour(),editTimeEdit->time().minute(),editTimeEdit->time().second());

    timers[positionToEdit].setTime(time);
    timers[positionToEdit].setDesc(editDescEdit->toPlainText());

    //timersSort();
    buffer.setTime(time);
    buffer.setDesc(editDescEdit->toPlainText());
    timersSort();
    editWindow->close();
}
//void MainWindow::editAlarmBtnClicked(){
//    QTime timeAlarm(editTimeEditAlarm->time().hour(),editTimeEditAlarm->time().minute(),editTimeEditAlarm->time().second());

//    alarms[listB->currentRow()].setTimeAlarm(timeAlarm);
//    alarms[listB->currentRow()].setDescAlarm(editDescEditAlarm->toPlainText());
//    //timersSort();
//    listB->item(listB->currentRow())->setText(editTimeEditAlarm->text());
//    //bufferAlarm.setTimeAlarm(timeAlarm);
//   // bufferAlarm.setDescAlarm(editDescEditAlarm->toPlainText());
//   listB->clearSelection();
//    editWindowAlarm->close();
//}
//done2

//done4
void MainWindow::deleteTimer()
{
    if(listW->currentRow()>=0){

        qDebug()<<timers.size();

        if(timers.size()==1){
            listW->clearSelection();
          //  qDebug()<<"durak1";
            deleteAllTimers();
        }
        if(!timers.empty() && timers.size()!=1){
           // qDebug()<<"durak";
            listW->takeItem(listW->currentRow());
            timers.removeAt(listW->currentRow());
        }


    }
    else{
        QMessageBox::warning(this,tr("Choose the timer"),tr("Please, choose the timer in Timers tab"));
        return;
    }



}
//done4
//void MainWindow::deleteAlarm(){
//    if(listB->currentRow()>=0){

//        qDebug()<<alarms.size();

//        if(alarms.size()==1){
//            listB->clearSelection();
//          //  qDebug()<<"durak1";
//            deleteAllAlarms();
//        }
//        if(!alarms.empty() && alarms.size()!=1){
//           // qDebug()<<"durak";
//            listB->takeItem(listB->currentRow());
//            alarms.removeAt(listB->currentRow());
//        }


//    }
//    else{
//        QMessageBox::warning(this,tr("Choose the alarm"),tr("Please, choose the Alarm in Alarms tab"));
//        return;
//    }
//}
//done4
void MainWindow::deleteAllTimers()
{
    if(timers.empty()){
        QMessageBox::warning(this,tr("Timers is empty"),tr("Timers is empty"));       
        return;
    }
    else{
        timers.clear();
        listW->blockSignals(true);
        listW->clear();
        listW->blockSignals(false);

        mainTimerLbl->setText("00:00:00");
        mainTimerDescriptionLbl->setText("\0");
    }

}
//done4
//void MainWindow::deleteAllAlarms(){
//    if(alarms.empty()){
//        QMessageBox::warning(this,tr("Alarms is empty"),tr("Alarms is empty"));
//        return;
//    }
//    else{
//        alarms.clear();
//        listB->blockSignals(true);
//        listB->clear();
//        listB->blockSignals(false);
//        mainTimerLbl->setText("00:00:00");
//        //mainTimerDescriptionLbl->setText("\0");
//    }
//}

//void MainWindow::settingsWindowSlot()
//{
//    settingsWindow = new QWidget;
//    QVBoxLayout *vbox = new QVBoxLayout();
//    QHBoxLayout *hbox = new QHBoxLayout();

//    infoOKBtn = new QPushButton("OK");

//    hbox->addWidget(doNotLbl);
//    hbox->addWidget(doNotCheckBox);
//    vbox->addLayout(hbox);
//    vbox->addWidget(infoOKBtn);

//    settingsWindow->setLayout(vbox);
//    settingsWindow->setObjectName("Settings");
//    settingsWindow->setFixedSize(250,150);
//    settingsWindow->show();

//    connect(infoOKBtn, &QPushButton::clicked, this, &MainWindow::infoOKBtnClicked);
//}

//void MainWindow::infoOKBtnClicked()
//{
//    doNotDisturb = doNotCheckBox->isChecked();
//    settingsWindow->close();
//}

//done1
void MainWindow::timersSort() {
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
//done1

void MainWindow::updateTimersListW()
{
    //constructr.addNewTimer(timers);
 qDebug()<<"hi";
    listW->clear();


    for(int i = 0; i < timers.size(); i++){

        listW->addItem(timers[i].getTime().toString());

    }
}
void MainWindow::updateAlarmsListB()
{
    listB->clear();
    for(int i = 0; i < alarms.size(); i++){
        listB->addItem(alarms[i].getTime().toString());
    }
}

void MainWindow::showDescription(){
    if(listW->count()>0 && timers.size()>0){
        mainTimerDescriptionLbl->setText("\0");
        if(listW->count()== timers.size())   mainTimerDescriptionLbl->setText(timers[listW->currentRow()].getDesc());
        listW->clearSelection();
        listB->clearSelection();
    }
    else   mainTimerDescriptionLbl->setText("\0");
}
void MainWindow::showDescriptionAlarm(){
    //listW->blockSignals(true);
   // listB->setEnabled(true);
    mainTimerDescriptionLbl->setText("\0");

      mainTimerDescriptionLbl->setText(alarms[listB->currentRow()].getDesc());
      listW->clearFocus();

       listB->clearSelection();
      // listB->setEnabled(false);
      // listB->setEnabled(true);
       // listW->blockSignals(false);
}







//done3
void MainWindow::timeoutwindow(QString description,QString paths){
//    this->description=description;
//    this->paths=paths;
    QProcess *process = new QProcess();
    QString file = paths;
    process->start(file);
    QVBoxLayout *vbox = new QVBoxLayout();
    signalWindow = new QWidget();
    signalWindow->resize(250,200);
    signalWindow->setObjectName("TIMEOUT!");
    timeoutLbl = new QLabel("Timeout! There is description:");
    timeoutDescLbl = new QTextEdit();
    timeoutDescLbl->setText(description);
    timeoutDescLbl->setReadOnly(true);
    timeoutOKBtn = new QPushButton("OK");
    vbox->addWidget(timeoutLbl);
    vbox->addWidget(timeoutDescLbl);
    vbox->addWidget(timeoutOKBtn);

    signalWindow->show();
    signalWindow->setLayout(vbox);
     qDebug()<<"timers.size()1111111111111111";
    auto audioOutput = new QAudioOutput();
    player = new QMediaPlayer();
    player->setSource( QUrl("qrc:/Resources/AlarmClock.wav"));
    player->setAudioOutput(audioOutput);
    audioOutput->setVolume(50);
  /*  if(settings.infoOk()==false)*/ player->play();
   connect(timeoutOKBtn, &QPushButton::clicked, signalWindow, &QPushButton::close);
}
