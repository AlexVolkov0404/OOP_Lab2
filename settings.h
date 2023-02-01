#ifndef SETTINGS_H
#define SETTINGS_H


#include "qboxlayout.h"
#include "qcheckbox.h"
#include "qlabel.h"
#include "qpushbutton.h"
#include "qwidget.h"
class Settings :public QObject
{
    Q_OBJECT
private:
    QWidget *settingsWindow;
    QLabel *doNotLbl;
    QCheckBox *doNotCheckBox;
    QPushButton *infoOKBtn;
    QVBoxLayout *vbox;
    QHBoxLayout *hbox ;
    bool doNotDisturb;
public:
    Settings();

public slots:
    void setsettingswindow();
     bool infoOk();
};

#endif // SETTINGS_H
