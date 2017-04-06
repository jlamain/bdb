
#include <QStandardItemModel>

#include "mainwindow.h"
#include "discmodel.h"
#include "discdialog.h"

MainWindow::MainWindow()
    : QMainWindow()
{

    model = new DiscModel(this, discs);
    model->load();
//    model = new QStandardItemModel(0,2);
//    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nr"));
//    model->setHeaderData(1, Qt::Horizontal, QObject::tr("title"));
    ui.setupUi(this);
    ui.tableView->setModel(model);
    //ui.tableView->resizeColumnToContents(0);
    ui.tableView->resizeColumnToContents(1);
    //ui.tableView->resizeColumnToContents(2);
    ui.tableView->show();
    menuBar()->setNativeMenuBar(true);

    connect(qApp,SIGNAL(aboutToQuit()),this,SLOT(actionsOnQuit()));
}


void MainWindow::on_actionAddDisc_triggered()
{
    Disc new_disc;

    auto max = 0;
    auto max_iter = std::max_element(discs.begin(), discs.end(), [](Disc a, Disc b){ return a.nr < b.nr; });

    if (max_iter!= discs.end()) {
        max = max_iter->nr;
    }

    new_disc.nr = max + 1;
    DiscDialog * d = new DiscDialog(this, new_disc);

    int ret = d->exec();
    if (ret == QDialog::Accepted)
    {
        model->addDisc(d->getDisc());
    }
    delete d;


}

void MainWindow::on_actionRemoveDisc_triggered()
{
    printf("removeDiscTriggered\n");

}

void MainWindow::on_actionPrint_triggered()
{
    printf("on_actionPrint_triggered\n");

}

void MainWindow::actionsOnQuit()
{
    printf("actionsOnQuit\n");
    model->save();
}

