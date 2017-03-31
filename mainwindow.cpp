#include "mainwindow.h"
#include "discmodel.h"

MainWindow::MainWindow()
    : QMainWindow()
{

    model = new DiscModel(this);
    ui.setupUi(this);
    ui.tableView->setModel(model);
    ui.tableView->show();
}
