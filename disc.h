#ifndef BDB_DISC_H
#define BDB_DISC_H

#include <QString>
#include <QDate>

#include "nicam.h"
#include "genre.h"

struct Disc
{
    int nr;
    enum {
        Dvd,
        Cd,
        Bluray
    } type;

    QString title;
    QString description;

    int _nrOfDvds;
    QDate bought;
    int _rating;
    Nicam _nicam;
    Genre _genre;
    QString _rent;
};

#endif //BDB_DISC_H
