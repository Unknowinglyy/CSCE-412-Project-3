#ifndef LOADBALANCER_H
#define LOADBALANCER_H
#include <vector>
#include <queue>
#include "webserver.h"
#include <iostream>
class loadbalancer {
    public:
    void distributeRequests();
    void checkAndRemove();
    void checkAndAdd();
    loadbalancer(std::vector<webserver*>& servers, std::queue<request>& q);
    ~loadbalancer(){
        for(auto& server: webServers){
            std::cout << "Deleting server." << std::endl; 
            delete server;
        }
    }
    private:
    std::vector<webserver*> webServers;
    std::queue<request> requestQueue;

};

#endif