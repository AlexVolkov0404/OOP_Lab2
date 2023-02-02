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
class timeoutwindow : public QObject
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
   timeoutwindow();
   void signalsound(QString description, QString paths);
   void sound();

};

#endif // TIMEOUTWINDOW_H
