
#ifndef BDB_DISCDIALOG_H
#define BDB_DISCDIALOG_H


#include <QDialog>

#include "disc.h"
#include "ui_discdialog.h"

class DiscDialog: public QDialog {

    Q_OBJECT

    public:
    DiscDialog(QWidget * parent, Disc d);
    Disc getDisc() const;

    private:
    Ui_DiscDialog   ui;
    Disc            disc;

    public slots:
    void nrFinished();
    void titleFinished();
    void typeChanged(int);
    void nrOfDiscsFinished();
    void descriptionFinished();
};


#endif //BDB_DISCDIALOG_H
