#include <QApplication>
#include "cellulut.hpp"
#include "Classes.hpp"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    cellulut fenetre;
    fenetre.show();

    return app.exec();
}
