#include "request.h"
#include <string>
#include <ctime>
#include <cstdlib>

std::string request::getIPIn(){
    return ipIn; //gets the input IP
}

std::string request::getIPOut(){
    return ipOut; //gets the output IP
}

int request::getProcessTime(){
    return processTime; //gets the process time
}

request::request(){
    srand(time(0)); //seed random number generator
    //generate random ipIn
    randomIP(ipIn);
    //generate random ipOut
    randomIP(ipOut);
    //generate random time between 1 and 5
    processTime = rand() % 5 + 1;
}

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