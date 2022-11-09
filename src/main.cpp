#include <network/Application.h>

int main(void) {
    debug_high("program started.\n");
    Application* app = new Application("xnet running");
    app->run();

    return 0;
}