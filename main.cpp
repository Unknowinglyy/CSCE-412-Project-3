#include <iostream>
#include <queue>
#include <string>
#include "request.h"
#include "webserver.h"
#include "loadbalancer.h"

using namespace std;

int main() {
    int servers;
    int time;

    cout << "Enter the number of servers: ";
    cin >> servers;
    cout  << endl;

    cout << "Enter the time you want to simulate: ";
    cin >> time;
    cout << endl;

    cout << "testing random ip generation" << endl;
    request r;
    cout << "input ip: " << r.getIPIn() << endl;
    cout << "output ip: " << r.getIPOut() << endl;
    cout << "process time: " << r.getProcessTime() << endl;
    return 0;
}