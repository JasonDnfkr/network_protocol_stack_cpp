#include <network/Application.h>

#include <iostream>

void Application::init() {
    driver = new Driver();
}


Application::Application(/* args */) {
    init();
} 


Application::Application(std::string info) {
    this->info = info;
    std::cout << info << std::endl;
    init();
}

Application::~Application() {  }

void Application::run() {
    driver->driver_open();

    while (true) {
        driver->ethernet_poll();
    }
}