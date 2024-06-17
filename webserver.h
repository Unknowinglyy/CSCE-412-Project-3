/**
 * @file webserver.h
 * @brief This file contains the webserver class.
 */

#ifndef _webserver_H_
#define _webserver_H_
#include "request.h"
#include <queue>

/**
 * @class webserver
 * @brief Class representing a web server.
 *
 * This class is responsible for processing and loading requests, and getting the size of the personal queue of requests.
 */
class webserver{
    public:
    /**
     * @brief Processes a request from the web server's personal queue.
     *
     * This function pops the request from the queue and simulates processing time.
     */
    void processRequest();

    /**
     * @brief Loads a request into the web server's personal queue.
     * @param r The request to be loaded.
     */
    void loadRequest(request r);

    /**
     * @brief Getter for the queue size.
     * @return The size of the personal queue.
     */
    int getQueueSize(){
        return personalQueue.size();
    }

    private:
    /**
     * @brief The web server's personal queue of requests.
     *
     * This queue has a maximum size of 50. Handle the size of the queue in the loadbalancer class.
     */
    std::queue<request> personalQueue;
};

#endif