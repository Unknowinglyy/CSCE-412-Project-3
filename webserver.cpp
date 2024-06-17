#include "webserver.h"
#include <iostream>
#include <chrono>
#include <thread>
void webserver::processRequest(){
    std::cout << "Processing request..." << std::endl;
    std::cout << "Input IP: " << personalQueue.front().getIPIn() << std::endl;
    std::cout << "Output IP: " << personalQueue.front().getIPOut() << std::endl;
    //get the process time
    int time = personalQueue.front().getProcessTime();
    //simulate the process time by sleeping for time milliseconds
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    //pop the request from the queue
    personalQueue.pop();
    std::cout << "Request processed." << std::endl;
    std::cout << "Request took " << time << " milliseconds." << std::endl << std::endl;
}
void webserver::loadRequest(request r){
    //load the request into the queue
    personalQueue.push(r);
}