#ifndef _webserver_H_
#define _webserver_H_
#include "request.h"
#include <queue>

class webserver{
    public:
    void processRequest();
    void loadRequest(request r);
    int getQueueSize(){
        return personalQueue.size();
    }

    private:
    std::queue<request> personalQueue;
};

#endif