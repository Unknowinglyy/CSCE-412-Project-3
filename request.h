#ifndef REQUEST_H
#define REQUEST_H
#include <string>

class request{
    public:
    request();
    std::string getIPIn();
    std::string getIPOut();
    int getProcessTime();

    private:
    std::string ipIn = "";
    std::string ipOut = "";
    int processTime = 0;
    void randomIP(std::string &ip);    
};

#endif