#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include <network/Driver.h>
#include <string>

class Application {
private:
    Driver* driver;
    std::string info;

    void init_constructor();
    /* data */
public:
    Application(/* args */);
    Application(std::string info);
    ~Application();

    void run();
};

#endif