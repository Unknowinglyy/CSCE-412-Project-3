/**
 * @file loadbalancer.cpp
 * @brief This file contains the implementation of the loadbalancer class.
 */

#include <iostream>
#include "loadbalancer.h"
#include "request.h"

/**
 * @brief Constructor for the load balancer.
 * @param servers Vector of pointers to webserver objects.
 * @param q Queue of request objects.
 */
loadbalancer::loadbalancer(std::vector<webserver*>& servers, std::queue<request>& q){
    webServers = servers;
    requestQueue = q;
}

/**
 * @brief Distributes requests to the web servers when they are first created. Only lets 50 requests into each server. Also makes sure that the request queue is not empty before distributing requests.
 */
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

/**
 * @brief Checks for any empty servers and removes them. Does this through the use of an iterator. If any server is found to be empty, it is deleted and removed from the vector. The function continues this check for all servers in the vector.
 */
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

/**
 * @brief Checks if all servers are full and adds a new server if they are.
 *
 * This function iterates through all the servers in the webServers vector. If it finds a server that is not full (i.e., its queue size is less than 50), it sets the 'full' flag to false and breaks out of the loop. If it doesn't find any such server, the 'full' flag remains true, and a new server is added to the webServers vector.
 */
void loadbalancer::checkAndAdd(){
    //no need to add a server if there are no requests
    if(requestQueue.empty()){
        return;
    }
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