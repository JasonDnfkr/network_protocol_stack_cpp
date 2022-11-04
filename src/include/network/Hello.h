#ifndef __HELLO_H__
#define __HELLO_H__

#include <string>

class Hello {
private:
    int x;
    int y;
    std::string str;

public:
    void fun();
    void print();    
};

#endif