#include <network/Application.h>

int main (void) {
    Application* app = new Application("xnet running");
    app->run();

    return 0;
}