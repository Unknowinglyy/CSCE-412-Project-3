/**
 * @file main.cpp
 * @brief This file contains the main function for the load balancer simulation.
 */

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include "request.h"
#include "webserver.h"
#include "loadbalancer.h"


using namespace std;

int main() {
    srand(time(0)); //seed the random number generator
    int servers;
    int simulateTime;

    cout << "Enter the number of servers: ";
    cin >> servers;
    cout  << endl;

    cout << "Enter the time you want to simulate: ";
    cin >> simulateTime;
    cout << endl;
    //start the timer
    auto start = std::chrono::high_resolution_clock::now();
    //create a queue of requests (servers * 100)
    queue<request> q;
    for(int i = 0; i < servers * 100; i++){
        request r;
        q.push(r);
    }

    //dynamically allocate the user specified number of web servers
    vector<webserver*> webServers;
    for(int i = 0; i < servers; i++){
        webServers.push_back(new webserver());
    }
    //create a load balancer
    loadbalancer lb (webServers, q);
    //distribute the requests to the servers so that each server has 100 requests and can process them
    lb.distributeRequests();
    //simulate the processing of the requests
    for(int i = 0; i < simulateTime; i++){
        srand(time(0)); //seed the random number generator
        int random = rand() % 100 + 1; //generate a random number between 1 and 100
        int count = 1;

        //add a new request to the queue 5% of the time
        if(random <= 5){
            //add a new request to the queue
            request r;
            q.push(r);
        }
        //check if all servers are full and add a new server if they are
        lb.checkAndAdd();
        //process the requests
        for(auto& server: webServers){
            server->processRequest();
            count++;
        }
        //check if any servers are empty and remove them
        lb.checkAndRemove();
        //break the loop if there are no more requests in the queue
        if(q.empty()){
            cout << "All requests have been processed." << endl;
            break;
        }
    }
    //finish the timer
    auto end = std::chrono::high_resolution_clock::now();
    //calculate the elapsed time
    std::chrono::duration<double> elapsed = end - start;
    //print the elapsed time
    std::cout << std::endl << "Simulation took " << elapsed.count() << " seconds." << std::endl;
    return 0;
}