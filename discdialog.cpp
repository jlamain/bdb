//
// Created by Jeroen Lamain on 03-04-17.
//

#include "discdialog.h"


DiscDialog::DiscDialog(QWidget * parent, Disc & d)
        : QDialog(parent), disc(d)
{
    ui.setupUi(this);
    ui.nr->setText(QString::number(d.nr));
    ui.title->setText(d.title);
    ui.description->setText(d.description);
}

