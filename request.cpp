/**
 * @file request.cpp
 * @brief This file contains the implementation of the request class.
 */

#include "request.h"
#include <string>
#include <ctime>
#include <cstdlib>


/**
 * @brief Getter for the input IP address of the request.
 * @return The input IP address as a string.
 */
std::string request::getIPIn(){
    return ipIn; //gets the input IP
}

/**
 * @brief Getter for the output IP address of the request.
 * @return The output IP address as a string.
 */
std::string request::getIPOut(){
    return ipOut; //gets the output IP
}

/**
 * @brief Getter for the processing time of the request.
 * @return The processing time as an integer.
 */
int request::getProcessTime(){
    return processTime; //gets the process time
}

/**
 * @brief Constructor for the request.
 *
 * Initializes a request with random input and output IP addresses and a random processing time.
 */
request::request(){
    //generate random ipIn
    randomIP(ipIn);
    //generate random ipOut
    randomIP(ipOut);
    //generate random time between 1 and 5
    processTime = rand() % 5 + 1;
}

/**
 * @brief Generates a random IP address.
 * @param ip Reference to a string where the generated IP address will be stored.
 *
 * This function generates a random IP address by concatenating four random numbers (each between 0 and 255) separated by periods. The generated IP address is stored in the string passed as the argument.
 */
void request::randomIP(std::string &ip){
    //generate random ip
    ip = ""; //clearing the ip
    for(int i = 0; i < 4; i++){
        ip += std::to_string(rand() % 256);
        if(i < 3){
            ip += ".";
        }
    }
}