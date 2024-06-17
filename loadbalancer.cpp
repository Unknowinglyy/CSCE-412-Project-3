#include <iostream>
#include "loadbalancer.h"
#include "request.h"

loadbalancer::loadbalancer(std::vector<webserver*>& servers, std::queue<request>& q){
    webServers = servers;
    requestQueue = q;
}

void loadbalancer::distributeRequests(){
    //load the requests into the web servers
    for(auto& server: webServers){
        //only load requests if the server is not full and there are still requests in the queue
        while(server->getQueueSize() < 50 && !requestQueue.empty()){
            //load the request into the server
            server->loadRequest(requestQueue.front());
            //pop the request from the overall queue
            requestQueue.pop();
        }
    }
}

void loadbalancer::checkAndRemove(){
    //check if any of the servers are empty
    for(auto iterator = webServers.begin(); iterator != webServers.end();){
        if((*iterator)->getQueueSize() == 0){
            //delete the server
            delete *iterator;
            //remove the server from the vector
            iterator = webServers.erase(iterator);
            //print a message to the console
            std::cout << "Server removed." << std::endl;
        }
        else{
            //move to the next server
            iterator++;
        }
    }
}

void loadbalancer::checkAndAdd(){
    //check if all the servers are full
    bool full = false;
    for(auto& server: webServers){
        if(server->getQueueSize() < 50){
            full = false;
            break;
        }
        else{
            full = true;
        }
    }
    if(full){
        //add a new server
        webServers.push_back(new webserver());
        std::cout << "Server added." << std::endl;
        //distribute requests to the new server
        distributeRequests();
    } 
}