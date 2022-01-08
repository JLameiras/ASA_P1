#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void p1(){
    string line;
    getline(cin, line);
    int ** sequence;
    sequence = stringtToArray(line);

}

void p2(){


}

int ** stringToArray(string line){
    int ** sequence;
    for(int i = 0, int h = 0; line[i] != '\0'; i++) {
        if (str[i] == ' ') j++;
        else sequence[h] = 10 * sequence[h] + atoi(str[i]);
    }
}

int main() {
    string line;
    int program;

    while(cin) {
        getline(cin, line);
        program = atoi(line);
        if(program == 1) p1();
        if(program == 2) p2();
    };
    return 0;
}