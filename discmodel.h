
#ifndef DISCMODEL_H
#define DISCMODEL_H

#include <QAbstractTableModel>

class DiscModel : public QAbstractTableModel
{
Q_OBJECT
public:
    DiscModel(QObject *parent);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
};

#endif