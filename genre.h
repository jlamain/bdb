//
// Created by Jeroen Lamain on 01-04-17.
//

#ifndef BDB_GENRE_H
#define BDB_GENRE_H

struct Genre {
    boolean Actie;
    boolean Animatie;
    boolean Avontuur;
    boolean Komedie;
    boolean Kinder;
    boolean Documentaire;
    boolean Drama;
    boolean Erotisch;
    boolean Fantasy;
    boolean Historisch;
    boolean Horror;
    boolean Melodrama;
    boolean Misdaad;
    boolean Muziek;
    boolean Rampen;
    boolean Romantisch;
    boolean Sciencefiction;
    boolean Thriller;
    boolean Oorlog;
    boolean Western;


    QString ToString() const
    {
        uint32_t nr = 0;
        if (Actie)          nr |= 1 << 0;
        if (Animatie)       nr |= 1 << 1;
        if (Avontuur)       nr |= 1 << 2;
        if (Komedie)        nr |= 1 << 3;
        if (Kinder)         nr |= 1 << 4;
        if (Documentaire)   nr |= 1 << 5;
        if (Drama)          nr |= 1 << 6;
        if (Erotisch)       nr |= 1 << 7;
        if (Fantasy)        nr |= 1 << 8;
        if (Historisch)     nr |= 1 << 8;
        if (Horror)         nr |= 1 << 10;
        if (Melodrama)      nr |= 1 << 11;
        if (Misdaad)        nr |= 1 << 12;
        if (Muziek)         nr |= 1 << 13;
        if (Rampen)         nr |= 1 << 14;
        if (Romantisch)     nr |= 1 << 15;
        if (Sciencefiction) nr |= 1 << 16;
        if (Thriller)       nr |= 1 << 17;
        if (Oorlog)         nr |= 1 << 18;
        if (Western)        nr |= 1 << 19;
        return QString::number(nr);
    }

    void parse(QString s)
    {
        uint32_t nr = s.toInt();

        if (pop(nr) > 10)
        {
            nr = ~nr;
        }

        Actie =         (nr & (1UL << 0)) != 0;
        Animatie =      (nr & (1UL << 1)) != 0;
        Avontuur =      (nr & (1UL << 2)) != 0;
        Komedie =       (nr & (1UL << 3)) != 0;
        Kinder =        (nr & (1UL << 4)) != 0;
        Documentaire =  (nr & (1UL << 5)) != 0;
        Drama =         (nr & (1UL << 6)) != 0;
        Erotisch =      (nr & (1UL << 7)) != 0;
        Fantasy =       (nr & (1UL << 8)) != 0;
        Historisch =    (nr & (1UL << 9)) != 0;
        Horror =        (nr & (1UL << 10)) != 0;
        Melodrama =     (nr & (1UL << 11)) != 0;
        Misdaad =       (nr & (1UL << 12)) != 0;
        Muziek =        (nr & (1UL << 13)) != 0;
        Rampen =        (nr & (1UL << 14)) != 0;
        Romantisch =    (nr & (1UL << 15)) != 0;
        Sciencefiction = (nr & (1UL << 16)) != 0;
        Thriller =      (nr & (1UL << 17)) != 0;
        Oorlog =        (nr & (1UL << 18)) != 0;
        Western =       (nr & (1UL << 19)) != 0;
    }

    uint32_t pop(uint32_t x) const
    {
        x = x - ((x >> 1) & 0x55555555);
        x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
        x = (x + (x >> 4)) & 0x0F0F0F0F;
        x = x + (x >> 8);
        x = x + (x >> 16);
        return x & 0x0000003F;
    }
};

#endif //BDB_GENRE_H
