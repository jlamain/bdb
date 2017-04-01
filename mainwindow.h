
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "disc.h"

class DiscModel;

class MainWindow : public QMainWindow {

    Q_OBJECT
    std::vector <Disc> discs;

    public:
    MainWindow();


    private:
    Ui_MainWindow ui;
    DiscModel *model;

    public slots:
    void addDiscTriggered();
    void removeDiscTriggered();

};
#endif
