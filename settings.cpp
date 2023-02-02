#include "settings.h"

Settings::Settings()
{


}
bool Settings :: infoOk(){
    doNotDisturb = doNotCheckBox->isChecked();
    settingsWindow->close();
    return doNotDisturb;
}
void Settings::setsettingswindow(){
    settingsWindow = new QWidget;
    QVBoxLayout *vbox = new QVBoxLayout();
    QHBoxLayout *hbox = new QHBoxLayout();
    doNotLbl = new QLabel("Do not disturbe mode");
    doNotCheckBox = new QCheckBox();
    infoOKBtn = new QPushButton("OK");

    doNotLbl = new QLabel("Do not disturbe mode");
    doNotCheckBox = new QCheckBox();
    doNotCheckBox->setChecked(false);

    hbox->addWidget(doNotLbl);
    hbox->addWidget(doNotCheckBox);
    vbox->addLayout(hbox);
    vbox->addWidget(infoOKBtn);

    settingsWindow->setLayout(vbox);
    settingsWindow->setObjectName("Settings");
    settingsWindow->setFixedSize(250,150);
//    settingsWindow->show();

    connect(infoOKBtn, &QPushButton::clicked, this, &Settings::infoOk);
}
void Settings::showSettingsWindow(){
    settingsWindow->show();
}
