
#include <QStandardPaths>
#include <QDir>
#include <QDomDocument>

#include "discmodel.h"

DiscModel::DiscModel(QObject *parent, std::vector <Disc> & discs)
        :QAbstractTableModel(parent), discs(discs)
{
    Disc d1;
    d1.nr = 1;
    d1.title = "Pulp Fiction";

    discs.push_back(d1);
}

int DiscModel::rowCount(const QModelIndex & /*parent*/) const
{
    return discs.size();
}

int DiscModel::columnCount(const QModelIndex & /*parent*/) const
{
    return 2;
}

QVariant DiscModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        int row = index.row();
        int col = index.column();
        QString ret;
        switch (col)
        {
            case 0:
                ret.setNum(discs[row].nr);
                break;
            case 1:
                ret = discs[row].title;
                break;
        }
        return ret;
    }
    return QVariant();
}

void DiscModel::load()
{
    QString path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    path = path + QDir::separator() + "broerdb.xml";

    QDomDocument doc("broerdb");
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly))
        return;
    if (!doc.setContent(&file)) {
        file.close();
        return;
    }
    file.close();
    printf("load %s\n", path.toUtf8().constData());
}


void DiscModel::save()
{

}