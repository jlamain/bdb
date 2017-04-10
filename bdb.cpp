#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>
#include <QDebug>

#include "mainwindow.h" 

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTranslator qtTranslator;
    qtTranslator.load("qt_" + QLocale::system().name(),
                      QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    app.installTranslator(&qtTranslator);

    qDebug() <<  QLocale::system().name();


    QTranslator myappTranslator;
    myappTranslator.load("lang_nl");
    if (app.installTranslator(&myappTranslator))
    {
        qDebug() << "Load ok";
    } else
    {
        qDebug() << "Load not ok";
    }


    MainWindow w;;
    w.show();

    return app.exec();
}
