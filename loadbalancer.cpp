#include <iostream>
#include "loadbalancer.h"
#include "request.h"

loadbalancer::loadbalancer(std::vector<webserver*> servers, std::queue<request> q){
    webServers = servers;
    requestQueue = q;
}

void loadbalancer::distributeRequests(std::queue<request> q){
    //load the requests into the web servers
    for(auto& server: webServers){
        //only load requests if the server is not full and there are still requests in the queue
        while(server->getQueueSize() < 100 && !q.empty()){
            //load the request into the server
            server->loadRequest(q.front());
            //pop the request from the overall queue
            q.pop();
        }
    }
    //if all servers are full and there are still requests in the queue, create a new server
    if(!q.empty()){
        webServers.push_back(new webserver());
        //print a message to the console
        std::cout << "Server added." << std::endl;
        //load the requests into the new server
        while(webServers.back()->getQueueSize() < 100 && !q.empty()){
            //load the request into the server
            webServers.back()->loadRequest(q.front());
            //pop the request from the overall queue
            q.pop();
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
