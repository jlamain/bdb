
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "disc.h"

class DiscModel;
class QStandardItemModel;

class MainWindow : public QMainWindow {

    Q_OBJECT
    std::vector <Disc> discs;

    public:
    MainWindow();


    private:
    Ui_MainWindow ui;
    DiscModel *model;
//    QStandardItemModel *model;

    public slots:
    void on_actionAddDisc_triggered();
    void on_actionRemoveDisc_triggered();
    void on_actionPrint_triggered();
    void actionsOnQuit();


};
#endif
