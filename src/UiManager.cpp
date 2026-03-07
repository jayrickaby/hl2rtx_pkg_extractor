//
// Created by jay on 07/03/2026.
//

#include "UiManager.h"

#include <iostream>

#include "GameLocator.h"


UiManager::UiManager(int& argc, char *argv[]) :
app(argc, argv),
ui(),
initialised(false)
{
    ui.setupUi(&window);
}

void UiManager::initialise() {
    setupUi();

    initialised = true;
}
void UiManager::display() {
    if (!isInitialised()) {
        throw std::runtime_error("Tried to display Ui, but it has not been initialised!");
    }
    window.show();
}
bool UiManager::execute() {
    if (!isInitialised()) {
        throw std::runtime_error("Tried to execute program, but Ui has not been initialised!");
    }

    // InputType Switcher. Shows/hides elements between Game, File & Folder.
    connect(ui.inputType, QOverload<int>::of(&QComboBox::currentIndexChanged),
    [=, this](const int index) {
        updateUserInput(index);
    });

    return app.exec();
}

void UiManager::setupUi() {
    window.setWindowTitle("HL2RTX PKG Extractor");
    updateUserInput(ui.inputType->currentIndex());

    ui.inputGame->addItem(QString::fromStdString(GameLocator::getGame()->name));

    std::filesystem::path icoPath{GameLocator::getSteamPath() / GameLocator::getGame()->path / "hl2" / "resource" / "game.ico"};
    ui.inputGame->setItemIcon(0, QIcon(icoPath.c_str()));
}

bool UiManager::isInitialised() const {
    return initialised;
}

void UiManager::updateUserInput(const int& index) {
    currentInputType = static_cast<InputType>(index);

    if (currentInputType == InputType::Game) {
        ui.inputGame->setEnabled(true);
        ui.inputGame->show();
        ui.inputPathDirectory->setDisabled(true);
        ui.inputPathDirectory->hide();
        ui.inputPathDialogue->setDisabled(true);
        ui.inputPathDialogue->hide();
    }
    else {
        ui.inputGame->setEnabled(false);
        ui.inputGame->hide();
        ui.inputPathDirectory->setEnabled(true);
        ui.inputPathDirectory->show();
        ui.inputPathDialogue->setEnabled(true);
        ui.inputPathDialogue->show();
    }
}
