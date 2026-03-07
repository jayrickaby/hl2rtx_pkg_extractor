//
// Created by jay on 07/03/2026.
//
#include "ui/ui_main.h"

#ifndef HL2RTX_PKG_EXTRACTOR_UIMANAGER_H
#define HL2RTX_PKG_EXTRACTOR_UIMANAGER_H

enum class InputType {
    Game,
    File,
    Folder
};

class UiManager : public QObject {
    Q_OBJECT
public:
    UiManager(int& argc, char *argv[]);

    void initialise();
    void display();
    bool execute();

    // Validators
    bool isInitialised() const;

private:
    QApplication app;
    QMainWindow window;
    Ui::MainWindow ui;

    void setupUi();
    void updateUserInput(const int& index);

    bool initialised;
    InputType currentInputType = InputType::Game;
};


#endif //HL2RTX_PKG_EXTRACTOR_UIMANAGER_H