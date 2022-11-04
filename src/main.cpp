#include <iostream>
#include <network/Hello.h>
#include <network/xnet_tiny.h>

int main (void) {
    std::cout << "xnet running\n";
    xnet_init();
    while (1) {
        xnet_poll();
    }

    Hello hi;
    hi.fun();
    hi.print();

    return 0;
}