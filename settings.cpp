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
    settingsWindow->setGeometry(20,20,300,300);
    settingsWindow->setWindowTitle("Settings");
    settingsWindow->setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::Dialog);


    QVBoxLayout *vbox = new QVBoxLayout();
    QHBoxLayout *hbox = new QHBoxLayout();
    doNotLbl = new QLabel("Do not disturbe mode");
    sortByTimeIncreaseLabel= new QLabel("Sort timers by time(increase)");
    sortByTimeDecreaseLabel = new QLabel("Sort timers by time(decrease)");
    sortByNameLabel   = new QLabel("Sort timers by description");
    doNotCheckBox = new QCheckBox();
    sortByTimeIncrease= new  QRadioButton();
    sortByTimeDecrease= new  QRadioButton();
    sortByName= new  QRadioButton();
    infoOKBtn = new QPushButton("OK");

    //doNotLbl = new QLabel("Do not disturbe mode");
   // doNotCheckBox = new QCheckBox();
    doNotCheckBox->setChecked(false);
    sortByTimeIncrease->setChecked(true);
    sortByTimeDecrease->setChecked(false);
    sortByName->setChecked(false);

    vbox->addWidget(doNotLbl);
    vbox->addWidget(doNotCheckBox);
    vbox->addWidget(sortByTimeIncreaseLabel);
    vbox->addWidget(sortByTimeIncrease);
    vbox->addWidget(sortByTimeDecreaseLabel);
    vbox->addWidget(sortByTimeDecrease);
    vbox->addWidget(sortByNameLabel);
    vbox->addWidget(sortByName);
    vbox->addLayout(hbox);
    vbox->addWidget(infoOKBtn);

    settingsWindow->setLayout(vbox);
    //settingsWindow->setObjectName("Settings");
    //settingsWindow->setFixedSize(250,150);
//    settingsWindow->show();

    connect(infoOKBtn, &QPushButton::clicked, this, &Settings::infoOk);
}
void Settings::showSettingsWindow(){
    settingsWindow->show();
}
void Settings::sortInfo(QList<Timer> &timers){
    if(sortByTimeIncrease->isChecked()==true) Sorting::sortByTimeIncrease(timers);
    if(sortByTimeDecrease->isChecked()==true) Sorting::sortByTimeDecrease(timers);
    if(sortByName->isChecked()==true) Sorting::sortByTimeDescription(timers);
}
