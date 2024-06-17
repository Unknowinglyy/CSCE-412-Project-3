/**
 * @file webserver.cpp
 * @brief This file contains the implementation of the webserver class.
 */
#include "webserver.h"
#include <iostream>
#include <chrono>
#include <thread>

/**
 * @brief Processes a request from the web server's personal queue.
 *
 * This function pops the request from the queue, prints the input and output IP addresses, simulates processing time by sleeping for a duration equal to the processing time of the request (in miliseconds), and then prints a message indicating that the request has been processed and the time it took.
 */
void webserver::processRequest(){
    if(!personalQueue.empty()){
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
    else{
        std::cout << "No requests to process for this server." << std::endl;
    }
}

/**
 * @brief Loads a request into the web server's personal queue.
 * @param r The request to be loaded.
 *
 * This function adds a request to the web server's personal queue.
 */
void webserver::loadRequest(request r){
    //load the request into the queue
    personalQueue.push(r);
}