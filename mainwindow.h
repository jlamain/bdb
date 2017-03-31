
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QStandardItemModel>

#include "ui_mainwindow.h"

class DiscModel;

class MainWindow : public QMainWindow {

    Q_OBJECT

public:
    MainWindow();


private:
    Ui_MainWindow ui;
    DiscModel *model;
};
#endif
