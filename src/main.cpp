#include "GameLocator.h"
#include "UiManager.h"

int main (int argc, char *argv[]) {
    GameLocator::initialise();
    UiManager ui(argc, argv);
    ui.initialise();
    ui.display();

    return ui.execute();
}
