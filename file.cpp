#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> stringToVector(string line){
    int i, j = 0;
    vector<int> sequence(1);
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
    int sequenceSize = static_cast<int>(sequence.size());
    vector<int> lengthByID (sequence.size(), 1);
    vector<int> countByID (sequence.size(), 1);
    int length = 0;
    int count = 0;

    for(int i = 0; i < sequenceSize; i++){
        for(int j = 0; j < i; j++){
            if(sequence[j] >= sequence[i]) continue;
            if(lengthByID[i] < lengthByID[j] + 1){
                lengthByID[i] = lengthByID[j] + 1;
                countByID[i] = countByID[j];
            } else if(lengthByID[i] == lengthByID[j] + 1)
                countByID[i] += countByID[j];
        }
    }

    for(int i : lengthByID) length = max(length, i);

    for(int i = 0; i < sequenceSize; i++)
        if (lengthByID[i] == length) count += countByID[i];

    cout << length << ' ' << count << endl;
}

void p2() {
    string line;
    getline(cin, line);
    vector<int> sequence1 = stringToVector(line);
    int n = static_cast<int>(sequence1.size());

    getline(cin, line);
    vector<int> sequence2 = stringToVector(line);
    int m = static_cast<int>(sequence2.size());

    vector<int> lookup(m, 0);

    for(int i = 0; i < n; i++) {
        int currentLength = 0; // Length of longest common increasing sequence

        for(int j = 0; j < m; j++) {
            if(sequence1[i] == sequence2[j])
                if(currentLength + 1 > lookup[j])
                    lookup[j] = currentLength + 1;
            if(sequence1[i] > sequence2[j])
                if(lookup[j] > currentLength)
                    currentLength = lookup[j];
        }
    }

    cout << *max_element(lookup.begin(), lookup.end()) << endl;
}

int main() {
    string line;
    int program;
    while(cin) {
        getline(cin, line);
        program = atoi(line.c_str());
        if(program == 1) p1();
        if(program == 2) p2();
    }
    return 0;
}