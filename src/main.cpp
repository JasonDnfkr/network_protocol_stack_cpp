#include <network/Application.h>

int main (void) {
    // std::cout << "xnet running\n";
    Application* app = new Application("xnet running");
    app->run();


    // xnet_init();
    // while (1) {
    //     xnet_poll();
    // }

    // Hello hi;
    // hi.fun();
    // hi.print();

    return 0;
}