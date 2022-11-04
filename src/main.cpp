#include <iostream>
#include <network/Hello.h>
#include <network/xnet_tiny.h>
#include <network/Driver.h>

int main (void) {
    std::cout << "xnet running\n";

    Driver* driver = new Driver();

    xnet_init();
    while (1) {
        xnet_poll();
    }

    Hello hi;
    hi.fun();
    hi.print();

    return 0;
}