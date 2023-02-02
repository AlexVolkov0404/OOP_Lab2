#include "timerdelete.h"

TimerDelete::TimerDelete()
{

}
void TimerDelete::delChosenTimer(QList<Timer> *timers, QListWidget *listW, QLabel *mainTimerLbl, QTextEdit *mainTimerDescriptionLbl){
    if(listW->currentRow()>=0&&listW ->item(listW->currentRow())->isSelected()){
        if(listW->currentRow()>=0){

            qDebug()<<timers->size();

            if(timers->size()==1){
                listW->clearSelection();
              //  qDebug()<<"durak1";
                delAllTimers(timers,listW, mainTimerLbl, mainTimerDescriptionLbl);
            }
            if(!timers->empty() && timers->size()!=1){
               // qDebug()<<"durak";
                listW->takeItem(listW->currentRow());
                timers->removeAt(listW->currentRow());
            }


        }
        else{
           // QMessageBox::warning(this,tr("Choose the timer"),tr("Please, choose the timer in Timers tab"));
            message.setText("Choose the timer!");
            message.setIcon(QMessageBox::Warning);
            message.setWindowTitle("Caution");
            message.exec();
            return;
        }
    }
    else{
        //QMessageBox::warning(this,tr("Choose the timer"),tr("Please, choose the timer in Timers tab"));
        message.setText("Choose the timer!");
        message.setIcon(QMessageBox::Warning);
        message.setWindowTitle("Caution");
        message.exec();
        return;
    }

}
void TimerDelete::delAllTimers(QList<Timer> *timers, QListWidget *listW, QLabel *mainTimerLbl, QTextEdit *mainTimerDescriptionLbl){
    if(timers->empty()){
        //QMessageBox::warning(this,tr("Timers is empty"),tr("Timers is empty"));
        message.setText("Timers is empty!");
        message.setIcon(QMessageBox::Warning);
        message.setWindowTitle("Caution");
        message.exec();
        return;
    }
    else{
        timers->clear();
        listW->blockSignals(true);
        listW->clear();
        listW->blockSignals(false);

        mainTimerLbl->setText("00:00:00");
        mainTimerDescriptionLbl->setText("\0");
    }
}
