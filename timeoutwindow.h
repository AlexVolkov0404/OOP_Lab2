#ifndef TIMEOUTWINDOW_H
#define TIMEOUTWINDOW_H

#include <QProcess>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "qlabel.h"
#include "qpushbutton.h"
#include "qtextedit.h"
#include "qwidget.h"
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QString>
#include "timer.h"
class timeoutwindow : Timer
{
private:
    QWidget *signalWindow;
    QLabel *timeoutLbl;
    QTextEdit *timeoutDescLbl;
    QPushButton *timeoutOKBtn;
    QVBoxLayout *vbox;
    QMediaPlayer *player;
    QString description;
    QString paths;


public:
   timeoutwindow(QString description, QString paths);
   void signalsound(QString description, QString paths);

};

#endif // TIMEOUTWINDOW_H
