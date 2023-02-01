#include "settings.h"

Settings::Settings()
{
    doNotLbl = new QLabel("Do not disturbe mode");
    doNotCheckBox = new QCheckBox();
    doNotCheckBox->setChecked(false);
    doNotDisturb = false;
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

    infoOKBtn = new QPushButton("OK");

    hbox->addWidget(doNotLbl);
    hbox->addWidget(doNotCheckBox);
    vbox->addLayout(hbox);
    vbox->addWidget(infoOKBtn);

    settingsWindow->setLayout(vbox);
    settingsWindow->setObjectName("Settings");
    settingsWindow->setFixedSize(250,150);
    settingsWindow->show();

    connect(infoOKBtn, &QPushButton::clicked, this, &Settings::infoOk);
}
