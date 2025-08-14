#include "./Mengine.h"

int main() {
    Mengine window(800, 800, "Title");

    while (!window.shouldClose()) {

        window.clear();

        window.colorBackground(1.0f, 0.3f, 1.0f); // set color

        window.update();
    }
}
