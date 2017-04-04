//
// Created by Jeroen Lamain on 01-04-17.
//

#ifndef BDB_NICAM_H
#define BDB_NICAM_H

#include <jmorecfg.h>

struct Nicam
{
    boolean Geweld;
    boolean Angst;
    boolean Seks;
    boolean Discriminatie;
    boolean AlcoholDrugs;
    boolean Grof;

    QString ToString() const
    {
        uint32_t nr = 0;
        if (Geweld)         nr |= 1 << 0;
        if (Angst)          nr |= 1 << 1;
        if (Seks)           nr |= 1 << 2;
        if (Discriminatie)  nr |= 1 << 3;
        if (AlcoholDrugs)   nr |= 1 << 4;
        if (Grof)           nr |= 1 << 5;

        return QString::number(nr);
    }

    void parse(QString s)
    {
        uint32_t nr = s.toInt();

        if (Geweld)         nr |= 1 << 0;
        if (Angst)          nr |= 1 << 1;
        if (Seks)           nr |= 1 << 2;
        if (Discriminatie)  nr |= 1 << 3;
        if (AlcoholDrugs)   nr |= 1 << 4;
        if (Grof)           nr |= 1 << 5;
    }


};

#endif //BDB_NICAM_H
