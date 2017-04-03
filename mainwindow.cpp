
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
    ui.tableView->show();
    menuBar()->setNativeMenuBar(true);
}


void MainWindow::addDiscTriggered()
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
        new_disc.nr = d->ui.nr->text().toInt();
        new_disc.title = d->ui.title->text();
        //new_disc.description = d->ui.description->;

        model->addDisc(new_disc);
    }
    delete d;


}

void MainWindow::removeDiscTriggered()
{
    printf("removeDiscTriggered\n");

}