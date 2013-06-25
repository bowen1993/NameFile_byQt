#include "namefile.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NameFile w;
    w.show();
    
    return a.exec();
}
