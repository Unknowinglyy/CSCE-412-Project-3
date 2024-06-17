#ifndef LOADBALANCER_H
#define LOADBALANCER_H
#include <vector>
#include <queue>
#include "webserver.h"

class loadbalancer {
    public:
    void distributeRequests(std::queue<request> q);
    void checkAndRemove();
    loadbalancer(std::vector<webserver*> servers, std::queue<request> q);
    ~loadbalancer(){
        for(auto& server: webServers){
            delete server;
        }
    }
    private:
    std::vector<webserver*> webServers;
    std::queue<request> requestQueue;

};

#endif