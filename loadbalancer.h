/**
 * @file loadbalancer.h
 * @brief This file contains the loadbalancer class.
 */
#ifndef LOADBALANCER_H
#define LOADBALANCER_H
#include <queue>
#include <vector>
#include "webserver.h"
#include <iostream>

/**
 * @class loadbalancer
 * @brief Class representing a load balancer.
 *
 * This class is responsible for distributing requests to web servers,
 * checking for any empty servers and removing them, and checking if all servers are full and adding a new server if they are.
 */
class loadbalancer {
public:
    /**
     * @brief Distributes requests to the web servers when they are first created.
     */
    void distributeRequests();

    /**
     * @brief Checks for any empty servers and removes them.
     */
    void checkAndRemove();

    /**
     * @brief Checks if all servers are full and adds a new server if they are.
     */
    void checkAndAdd();

    /**
     * @brief Constructor for the load balancer.
     * @param servers Vector of pointers to webserver objects.
     * @param q Queue of request objects.
     */
    loadbalancer(std::vector<webserver*>& servers, std::queue<request>& q);

    /**
     * @brief Destructor for the load balancer.
     *
     * Deletes all webserver objects pointed to by the pointers in the webServers vector.
     */
    ~loadbalancer(){
        for(auto& server: webServers){
            std::cout << "Deleting server." << std::endl; 
            delete server;
        }
    }

private:
    /**
     * @brief Vector of pointers to webserver objects.
     */
    std::vector<webserver*> webServers;
    /**
     * @brief Queue of request objects.
     * 
     */
    std::queue<request> requestQueue;
};

#endif