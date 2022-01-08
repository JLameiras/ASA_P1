#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string line;
    int programNumber;

    while(cin) {
        getline(cin, line);
        programNumber = atoi(line);
        if(programNumber == 1) p1();
        else p2();
    };
    return 0;
}