#include "GUI/FormMain.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    try
    {
        QApplication a(argc, argv);
        Widget w;
        w.show();

        return a.exec();
    }
    catch(std::exception &e)
    {
        qFatal(e.what());
    }
    catch(...)
    {
        qFatal("Unknown fatal error.");
    }
}
