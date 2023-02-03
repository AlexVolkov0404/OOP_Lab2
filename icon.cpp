#include "icon.h"

Icon::Icon()
{

}
//void Icon::setIcon(int size){
//    figure= QString::number(size);
//    QPixmap pixmap(25,25);
//    pixmap.fill(Qt::transparent);
//    QPainter painter(&pixmap);
//    painter.drawPixmap(0, 0,25,25, QPixmap(":/Resources/clock.jpg"));
//    painter.setPen(QPen(Qt::white, 1, Qt::SolidLine, Qt::SquareCap));
//    painter.setBrush(QBrush(Qt::red));
//    if(size>0){
//        painter.drawEllipse(10, 10, 16, 16);
//        QFont font1("MS Shell Dlg 2", 8);
//        painter.setFont(font1);
//        painter.drawText(QRect(10, 13, 18, 13), Qt::AlignCenter, figure);
//    }
//    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
//    painter.end();
//    setWindowIcon(QIcon(pixmap));
//}
