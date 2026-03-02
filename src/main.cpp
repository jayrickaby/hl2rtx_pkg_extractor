#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWidget window;
    window.resize(640, 480);
    window.show();
    window.setWindowTitle(
        QApplication::translate("mainWindowTitle", "HL2RTX PKG Extractor"));

    return QApplication::exec();
}