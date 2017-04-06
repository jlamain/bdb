
#include <QStandardPaths>
#include <QDir>
#include <QXmlStreamReader>
#include <QDebug>

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
    return 3;
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
            case 2:
                ret.setNum(discs[row].rating);
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
                case 2:
                    return QString(tr("Rating"));
            }
        }
    }
    return QVariant();
}

void DiscModel::load()
{

    QString path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    path = path + QDir::separator() + "broerdb.xml";
    qDebug() << "Load " << path;

    QFile file(path);
    if (!file.open(QIODevice::ReadOnly))
        return;

    QXmlStreamReader s;
    s.setDevice(&file);

    s.readNext();
    beginInsertRows(QModelIndex(), discs.size(), discs.size());

    while(!s.atEnd()) {

        QStringRef tag = s.name();

        if (s.isStartElement() && tag == "dvd")
        {
            Disc d;
            QXmlStreamAttributes attr = s.attributes();
            for (int i=0;i < attr.count(); i++)
            {
                QXmlStreamAttribute at = attr[i];
                auto atname = at.name();
                auto atvalue = at.value();
                if (atname == "nr")
                {
                    d.nr = atvalue.toInt();
                }
                else if (atname == "title")
                {
                    d.title = atvalue.toString();
                }
                else if (atname == "description")
                {
                    d.description = atvalue.toString();
                }
                else if (atname == "disctype")
                {
                    d.type = static_cast<Disc::DiscType>(atvalue.toInt());
                }
                else if (atname == "nrofdvds")
                {
                    d.nrOfDvds = atvalue.toInt();
                }
                else if (atname == "rating")
                {
                    d.rating = atvalue.toInt();
                }
                else if (atname == "nicam")
                {
                    d.nicam.parse(atvalue.toString());
                }
                else if (atname == "genre")
                {
                    d.genre.parse(atvalue.toString());
                }
                else if (atname == "rent")
                {
                    d.rent = atvalue.toString();
                }
                else if (atname == "bought")
                {
                    d.bought = QDateTime::fromString(atvalue.toString(), "d-m-yyyy HH:mm:ss");
                }
                else
                {
                    qDebug() << atname;
                }
            }
            discs.push_back(d);
        }
        s.readNext();
    }
    std::sort(discs.begin(), discs.end(), [](const Disc & a, const Disc b) {
        return a.nr < b.nr;
    });

    endInsertRows();


    file.close();

    QModelIndex top = createIndex(0, 0, nullptr);
    QModelIndex bottom = createIndex(discs.size() - 1, 3, nullptr);

    emit dataChanged(top, bottom);
}


void DiscModel::save()
{
    QString path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    path = path + QDir::separator() + "broerdb2.xml";
    qDebug() << "Save " << path;

    QFile file(path);
    if (!file.open(QIODevice::WriteOnly))
        return;

    QXmlStreamWriter s;
    s.setDevice(&file);
    s.setAutoFormatting(true);
    /* Writes a document start with the XML version number. */
    s.writeStartDocument();
    s.writeStartElement("dvdcollection");

    for (auto & d : discs)
    {
        s.writeStartElement("dvd");

        s.writeAttribute("nr",QString::number(d.nr));
        s.writeAttribute("disctype", QString::number(d.type));
        s.writeAttribute("title", d.title);
        s.writeAttribute("description", d.description);
        s.writeAttribute("nrofdvds", QString::number(d.nrOfDvds));
        s.writeAttribute("bought", d.bought.toString("d-m-yyyy HH:mm:ss"));
        s.writeAttribute("rating",QString::number(d.rating));
        s.writeAttribute("nicam", d.nicam.ToString());
        s.writeAttribute("genre",d.genre.ToString());
        s.writeAttribute("rent",d.rent);
        /*close tag student  */
        s.writeEndElement();
    }

    /*end tag students*/
    s.writeEndElement();
    /*end document */
    s.writeEndDocument();


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

void  DiscModel::deleteRows(std::vector<int> rows)
{
    // sort back to front, to avoid shuffling indexes of discs vector.
    std::sort(rows.begin(), rows.end(), [](int a, int b) {
        return a > b;
    });


    for (const auto & r: rows)
    {
        discs.erase(discs.begin() + r);
    }

    std::sort(discs.begin(), discs.end(), [](const Disc & a, const Disc b) {
        return a.nr < b.nr;
    });

    QModelIndex top = createIndex(discs.size() - 1, 0, nullptr);
    QModelIndex bottom = createIndex(discs.size() - 1, 3, nullptr);

    emit dataChanged(top, bottom);
}

