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
    vector<int> sequence = stringToVector(line);
    vector<int> lengthByID (sequence.size());
    vector<int> countByID (sequence.size());
    for(int i = 0; i < sequence.size(); i++){
        lengthByID[i] = 0;
        countByID[i] = 0;
    }
    int length = 0;
    int count = 0;

    for(int i = 1; i < sequence.size(); i++){
        for(int j = 0; j < i; j++){
            if(sequence[j] < sequence[i]){
                if(lengthByID[i] < lengthByID[j] + 1){
                    lengthByID[i] = lengthByID[j];
                    countByID[i] = countByID[j];
                } else if(lengthByID[i] == lengthByID[j] + 1)
                    countByID[i] = countByID[i] + countByID[j];
            }
        }
    }

    for(int id = 0; id < sequence.size(); id++){
        if(length < lengthByID[id]){
            length = lengthByID[id];
            count = id;
        }
    }
    cout<<count<<length;
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