
#include <QStandardItemModel>
#include <QDebug>
#include <QPrintDialog>
#include <QPrinter>

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
    QItemSelectionModel *select = ui.tableView->selectionModel();

    if (select->hasSelection())
    {
        QModelIndexList selection = select->selectedRows();
        std::vector<int> rows;
        for(int i=0; i< selection.count(); i++)
        {

            QModelIndex index = selection.at(i);
            qDebug() << index.row();
            rows.push_back(index.row());
            model->deleteRows(rows);
        }
    }
//    select->selectedRows() // return selected row(s)
//    select->selectedColumns() // return selected column(s)
//
//    int idx = ui.tableView->sele
}

void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer(QPrinter::HighResolution);

    printf("on_actionPrint_triggered\n");
    QPrintDialog printDialog(&printer, this);
    if (printDialog.exec() == QDialog::Accepted) {
        // print ...
    }

}

void MainWindow::actionsOnQuit()
{
    printf("actionsOnQuit\n");
    model->save();
}

