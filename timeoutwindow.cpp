#include "timeoutwindow.h"


timeoutwindow::timeoutwindow()
{
//    this->description=description;
//    this->paths=paths;
}
void timeoutwindow :: signalsound(QString description, QString paths)
{

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
//    auto audioOutput = new QAudioOutput();
//    player = new QMediaPlayer();
//    player->setSource( QUrl("qrc:/Resources/AlarmClock.wav"));
//    player->setAudioOutput(audioOutput);
//    audioOutput->setVolume(50);
//    player->play();
    QAbstractButton::connect(timeoutOKBtn, &QPushButton::clicked, signalWindow, &QPushButton::close);
}
void timeoutwindow::sound(){
    auto audioOutput = new QAudioOutput();
    player = new QMediaPlayer();
    player->setSource( QUrl("qrc:/Resources/AlarmClock.wav"));
    player->setAudioOutput(audioOutput);
    audioOutput->setVolume(50);
    player->play();
}
