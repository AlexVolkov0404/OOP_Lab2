#include "editconstructor.h"

EditConstructor::EditConstructor()
{

}
void EditConstructor::showEditWindow(QList<Timer> *timers,QListWidget *listW){
    if(listW->currentRow()>=0&&listW ->item(listW->currentRow())->isSelected()){
        checker(*timers,listW);

        editWindow = new QWidget();
        editWindow->resize(200,250);
        editWindow->setObjectName("Edit Timers");

        QVBoxLayout *vbox = new QVBoxLayout();

        editTimeLbl = new QLabel("Edit time:");
        editDescLbl = new QLabel("Edit description:");
        editTimeEdit = new QTimeEdit();
        editTimeEdit->setDisplayFormat("hh:mm:ss");

        //editTimeEdit->setTime(timers[positionToEdit].getTime());
        editDescEdit = new QTextEdit();
        editTimerBtn = new QPushButton("OK");
        setTimeEdit(*timers);

        vbox->addWidget(editTimeLbl);
        vbox->addWidget(editTimeEdit);
        vbox->addWidget(editDescLbl);
        vbox->addWidget(editDescEdit);
        vbox->addWidget(editTimerBtn);


        connect(editTimerBtn, &QPushButton::clicked, this,[=](){editTimerInformation(*timers);});
        editWindow->setLayout(vbox);
        editWindow->show();
    }
    else{       
        message.setText("Choose the timer!");
        message.setIcon(QMessageBox::Warning);
        message.setWindowTitle("Caution");
        message.exec();
        return;
    }
}
void EditConstructor::editTimerInformation(QList<Timer> &timers){
    QTime time(editTimeEdit->time().hour(),editTimeEdit->time().minute(),editTimeEdit->time().second());

    timers[positionToEdit].setTime(time);
    timers[positionToEdit].setDesc(editDescEdit->toPlainText());
    //constructor.timersort(timers);
    editWindow->close();
}
void EditConstructor::checker(QList<Timer> &timers, QListWidget *listW){
    if(!timers.empty()){
        tmp = listW->selectedItems().first()->text();
        if(tmp == "\0"){          
           message.setText("Choose the timer!");
           message.setIcon(QMessageBox::Warning);
           message.setWindowTitle("Caution");
           message.exec();          
            return;
        }
    } else {       
        message.setText("Timers is empty!");
        message.setIcon(QMessageBox::Warning);
        message.setWindowTitle("Caution");
        message.exec();
        return;
    }
    for(int i = 0; i < timers.size(); i++){
        if(tmp == timers[i].getTime().toString()){
            positionToEdit = i;
        }
    }

}

void EditConstructor::setTimeEdit(QList<Timer> &timers){
    editTimeEdit->setTime(timers[positionToEdit].getTime());
    editDescEdit->setText(timers[positionToEdit].getDesc());
}
