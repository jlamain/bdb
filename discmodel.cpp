#include "discmodel.h"

DiscModel::DiscModel(QObject *parent)
        :QAbstractTableModel(parent)
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