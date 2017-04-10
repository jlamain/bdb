
#include <QStandardItemModel>
#include <QDebug>
#include <QPrintDialog>
#include <QPrinter>
#include <QPainter>


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
            rows.push_back(index.row());
        }
        model->deleteRows(rows);
    }
}

void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer(QPrinter::HighResolution);

    printf("on_actionPrint_triggered\n");
    QPrintDialog printDialog(&printer, this);
    if (printDialog.exec() == QDialog::Accepted) {
        auto width = printer.width();
        auto height = printer.height();


        QPainter painter;
        painter.begin(&printer);
        //qDebug() << page;

        QFont font = painter.font();
        font.setPointSize(10);
        painter.setFont(font);

        const int top = 20;
        const int linespacing = 14;
        const int nr_width = 40;
        const int clip_whitespace = 10;
        int x = 0;
        int y = top;

        painter.setClipRect(0,0, width / 2 - clip_whitespace, height, Qt::ReplaceClip);
        for (const auto & d: discs)
        {
            painter.drawText(x + clip_whitespace, y, QString::number(d.nr));
            painter.drawText(x + nr_width, y, d.title );

            y+= linespacing;
            if (y > height - top)
            {
                if (x == 0)
                {
                    x = width / 2;
                    y = top;
                    painter.setClipRect(x,0, width / 2 - clip_whitespace, height, Qt::ReplaceClip);

                } else
                {
                    painter.setClipRect(0,0, width / 2 - clip_whitespace, height, Qt::ReplaceClip);
                    x = 0;
                    y = top;
                    printer.newPage();
                }
            }
        }
        painter.end();

    }

}

void MainWindow::actionsOnQuit()
{
    printf("actionsOnQuit\n");
    model->save();
}

