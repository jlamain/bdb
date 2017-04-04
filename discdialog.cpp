//
// Created by Jeroen Lamain on 03-04-17.
//

#include "discdialog.h"


DiscDialog::DiscDialog(QWidget * parent, Disc d) : QDialog(parent), disc(d) {
    ui.setupUi(this);
    ui.nr->setText(QString::number(d.nr));
    ui.title->setText(d.title);
    ui.description->setText(d.description);
}



Disc DiscDialog::getDisc() const
{
    return disc;
}

void DiscDialog::nrFinished()
{
    int nr = ui.nr->text().toInt();
    disc.nr = nr;
}
void DiscDialog::titleFinished()
{
    disc.title = ui.title->text();
}
void DiscDialog::typeChanged(int d)
{
    disc.type = static_cast<Disc::DiscType>(d);
}

void DiscDialog::nrOfDiscsFinished()
{
    int nr = ui.nrOfDiscs->text().toInt();
    disc.nrOfDvds = nr;
}
void DiscDialog::descriptionFinished()
{
    disc.description = ui.description->toPlainText();
}