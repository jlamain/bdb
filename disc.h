#ifndef BDB_DISC_H
#define BDB_DISC_H

#include <QString>
#include <QDate>

#include "nicam.h"
#include "genre.h"

struct Disc
{
    int nr;
    enum DiscType {
        Dvd,
        Cd,
        Bluray
    } type;

    QString title;
    QString description;

    int   nrOfDvds;
    QDate bought;
    int   rating;
    Nicam nicam;
    Genre genre;
    QString rent;
};

#endif //BDB_DISC_H
