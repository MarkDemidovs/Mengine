#include "./Mengine.h"
#include "./Square.h"
#include "./Triangle.h"

int main() {
    Mengine window(800, 800, "Shapes");

    Square square;
    Triangle triangle;

    square.init();
    triangle.init();

    while (!window.shouldClose()) {
        window.clear();
        window.colorBackground(0.1f, 0.1f, 0.1f);

        square.draw();
        triangle.draw();

        window.update();
    }
}
