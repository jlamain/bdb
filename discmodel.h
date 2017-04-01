
#ifndef DISCMODEL_H
#define DISCMODEL_H

#include <QAbstractTableModel>

#include "disc.h"

class DiscModel : public QAbstractTableModel
{
Q_OBJECT
private:
    std::vector<Disc> & discs;

public:
    DiscModel(QObject *parent, std::vector <Disc> & discs);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    void load();
    void save();
};

#endif