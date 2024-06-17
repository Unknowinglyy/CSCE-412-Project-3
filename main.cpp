#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <chrono>
#include "request.h"
#include "webserver.h"
#include "loadbalancer.h"

using namespace std;

int main() {
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
    loadbalancer lb(webServers, q);
    //distribute the requests to the servers so that each server has 100 requests and can process them
    lb.distributeRequests(q);
    //simulate the processing of the requests
    for(int i = 0; i < simulateTime; i++){
        srand(time(0)); //seed the random number generator
        int random = rand() % 100 + 1; //generate a random number between 1 and 100
        if(random <= 5){
            //add a new request to the queue
            request r;
            q.push(r);
        }
        //process the requests
        for(auto& server: webServers){
            server->processRequest();
        }
        //check if any servers are empty and remove them
        lb.checkAndRemove();
        //distribute the requests to the servers
        lb.distributeRequests(q);
    }
    //finish the timer
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << std::endl << "Simulation took " << elapsed.count() << " seconds." << std::endl;
    return 0;
}