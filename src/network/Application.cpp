#include <network/Application.h>

#include <iostream>

void Application::init_constructor() {
    driver = new Driver();
}


Application::Application(/* args */) {
    init_constructor();
} 


Application::Application(std::string info) {
    this->info = info;
    std::cout << info << std::endl;
    init_constructor();
}

Application::~Application() {  }

void Application::run() {
    driver->driver_open();
    driver->driver_init();

    while (true) {
        driver->poll();
    }
}