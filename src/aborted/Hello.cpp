#include <network/Hello.h>
#include <iostream>

void Hello::print() {
    std::cout << "hello world!" << std::endl;
}

void Hello::fun() {
    str = "test";
    x = 0;
    y = 0;
    x++;
    y++;
    for (int i = 0; i < 10; i++) {
        x++;
        str.insert(str.begin(), x + '0');
    }
    std::cout << str << std::endl;
}