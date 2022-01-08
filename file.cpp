#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


vector<int> stringToVector(string line){
    int i, j = 0;
    vector<int> sequence(1);
    cout << sequence[0];
    for(i = 0; line[i] != '\0'; i++) {
        if (line[i] == ' ') {j++; sequence.push_back(0);}
        else sequence[j] = 10 * sequence[j] + (line[i] - '0');
    }

    return sequence;
}


void p1(){
    string line;
    getline(cin, line);
    vector<int> sequence;
    sequence = stringToVector(line);

}

void p2() {
}

int main() {
    string line;
    int program;

    while(cin) {
        getline(cin, line);
        program = atoi(line.c_str());
        if(program == 1) p1();
        if(program == 2) p2();
    };
    return 0;
}