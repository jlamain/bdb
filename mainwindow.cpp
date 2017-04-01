#include "mainwindow.h"
#include "discmodel.h"

MainWindow::MainWindow()
    : QMainWindow()
{

    model = new DiscModel(this, discs);
    model->load();
    ui.setupUi(this);
    ui.tableView->setModel(model);
    ui.tableView->show();
    menuBar()->setNativeMenuBar(true);
}


void MainWindow::addDiscTriggered()
{
    printf("addDiscTriggered\n");
}

void MainWindow::removeDiscTriggered()
{
    printf("removeDiscTriggered\n");

}