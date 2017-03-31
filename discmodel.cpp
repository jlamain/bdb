#include "discmodel.h"

DiscModel::DiscModel(QObject *parent)
        :QAbstractTableModel(parent)
{
}

int DiscModel::rowCount(const QModelIndex & /*parent*/) const
{
    return 2;
}

int DiscModel::columnCount(const QModelIndex & /*parent*/) const
{
    return 3;
}

QVariant DiscModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        return QString("Row%1, Column%2")
                .arg(index.row() + 1)
                .arg(index.column() +1);
    }
    return QVariant();
}