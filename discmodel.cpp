
#include <QStandardPaths>
#include <QDir>
#include <QDomDocument>

#include "discmodel.h"

DiscModel::DiscModel(QObject *parent, std::vector <Disc> & discs)
        :QAbstractTableModel(parent), discs(discs)
{
}

int DiscModel::rowCount(const QModelIndex & /*parent*/) const
{
    //printf("size %d\n", (int)discs.size());
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
       // printf("get col %d row %d dat:%s\n", col, row, ret.toUtf8().data());

        return ret;
    }
    return QVariant();
}

QVariant DiscModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
                case 0:
                    return QString(tr("Nr"));
                case 1:
                    return QString(tr("Title"));
            }
        }
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

void DiscModel::addDisc(Disc d)
{
    beginInsertRows(QModelIndex(), discs.size(), discs.size());
    discs.push_back(d);
    endInsertRows();

    QModelIndex top = createIndex(discs.size() - 1, 0, nullptr);
    QModelIndex bottom = createIndex(discs.size() - 1, 3, nullptr);

    emit dataChanged(top, bottom);
}
