#include <QApplication>
#include <QMainWindow>

#include "GameLocator.h"
#include "ui/ui_main.h"

int main (int argc, char *argv[]) {
    GameLocator::initialise();

    QApplication app (argc, argv);

    QMainWindow window;
    Ui::MainWindow ui;
    ui.setupUi(&window);

    window.setWindowTitle("HL2RTX PKG Extractor");

    ui.gamesBox->addItem(QString::fromStdString(GameLocator::getGame()->name));

    window.show();
    return app.exec();
}