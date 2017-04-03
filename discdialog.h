
#ifndef BDB_DISCDIALOG_H
#define BDB_DISCDIALOG_H


#include <QDialog>

#include "disc.h"
#include "ui_discdialog.h"

class DiscDialog: public QDialog {

    public:
    DiscDialog(QWidget * parent, Disc & d);

    public:
    Ui_DiscDialog ui;
    Disc &        disc;


};


#endif //BDB_DISCDIALOG_H
