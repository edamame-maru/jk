#include "jk.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    jk w;
    w.setWindowIcon(QIcon()); // Clear the icon
    w.show();
    return a.exec();
}
