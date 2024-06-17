/**
 * @file request.h
 * @brief This file contains the request class.
 */

#ifndef REQUEST_H
#define REQUEST_H
#include <string>

/**
 * @class request
 * @brief Class representing a request.
 *
 * This class is responsible for storing and providing access to the details of a request, including input and output IP addresses and processing time.
 */
class request{
    public:
    /**
     * @brief Constructor for the request.
     *
     * Initializes a request with random input and output IP addresses and a random processing time.
     */
    request();

    /**
     * @brief Getter for the input IP address of the request.
     * @return The input IP address as a string.
     */
    std::string getIPIn();

    /**
     * @brief Getter for the output IP address of the request.
     * @return The output IP address as a string.
     */
    std::string getIPOut();

    /**
     * @brief Getter for the processing time of the request.
     * @return The processing time as an integer.
     */
    int getProcessTime();

    private:
    /**
     * @brief Input IP address for the request.
     */
    std::string ipIn = "";

    /**
     * @brief Output IP address for the request.
     */
    std::string ipOut = "";

    /**
     * @brief Processing time for the request.
     */
    int processTime = 0;

    /**
     * @brief Function to generate a random IP address.
     * @param ip Reference to the string to store the generated IP address.
     */
    void randomIP(std::string &ip);    
};

#endif