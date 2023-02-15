#include "mainwindow.h"
#include <QDebug>
#include <QScrollBar>
#include <QPushButton>
#include <iostream>

MainWindow::MainWindow()
{
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
        mainTimerLbl->setText(timers[Sorting::findMin(timers)].getTime().toString());

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

//void MainWindow::stopTimer()
//{
////    for(int i = 0; i < timers.size(); i++){
////        if(timers[i].getTime().toString() == listW->selectedItems().first()->text()){
////            if(!stoppedTimersPositions.empty()){
////                for(int j = 0; j < stoppedTimersPositions.size(); j++){
////                    if(i != stoppedTimersPositions[j]){
////                        stoppedTimersPositions.append(i);
////                    } else {
////                        stoppedTimersPositions.removeAt(j);
////                    }
////                }
////             } else
////                 stoppedTimersPositions.append(i);
////        }
////    }


//}

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







