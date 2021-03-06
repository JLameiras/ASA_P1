#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
using namespace std::chrono;

void stringToVector(string line, vector<int>* sequence){
    int i, j;

    for(i = 0, j = 0; line[i] != '\0'; i++) {
        if (line[i] == ' ') {j++; (*sequence).push_back(0);}
        else (*sequence)[j] = 10 * (*sequence)[j] + (line[i] - '0');
    }
}

void p1(){
    auto start = high_resolution_clock::now();
    string line;
    getline(cin, line);
    vector<int> sequence(1);
    stringToVector(line, &sequence);

    int sequenceSize = static_cast<int>(sequence.size());
    vector<int> lengthByID (sequenceSize, 1);
    vector<int> countByID (sequenceSize, 1);

    int length = 0;
    int count = 0;
    for(int i = 1; i < sequenceSize; i++){
        for(int j = 0; j < i; j++){
            if(sequence[j] >= sequence[i]) continue;
            if(lengthByID[i] < lengthByID[j] + 1){
                lengthByID[i] = lengthByID[j] + 1;
                countByID[i] = countByID[j];
            } else if(lengthByID[i] == lengthByID[j] + 1)
                countByID[i] += countByID[j];
        }
    }

    for(int i = 0; i < sequenceSize; i++) {
        if(lengthByID[i] > length) {
            length = lengthByID[i], count = countByID[i];
        } else if(length == lengthByID[i])
            count += countByID[i];
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Time taken by p1: "
         << duration.count() << " microseconds. Sequence size:" << sequenceSize << endl;
    cout << length << ' ' << count << endl;
}

void p2() {
    auto start = high_resolution_clock::now();
    string line;
    //Obtain first sequence
    getline(cin, line);
    vector<int> sequence1(1);
    stringToVector(line, &sequence1);
    int m = static_cast<int>(sequence1.size());
    //Obtain second sequence
    getline(cin, line);
    vector<int> sequence2(1);
    stringToVector(line, &sequence2);
    int n = static_cast<int>(sequence2.size());
    set<int> values(sequence1.begin(), sequence1.end());
    //Get longest common sequence
    int aux = 0;
    for(int i = 0; i < n; i++)
        if(values.find(sequence2[i - aux]) == values.end())
            sequence2.erase(sequence2.begin() + i - aux++);

    n = static_cast<int>(sequence2.size());
    vector<int> lookup(n, 0);

    for(int i = 0, currentLength = 0; i < m; i++, currentLength = 0) {
        for(int j = 0; j < n; j++) {
            if(sequence1[i] == sequence2[j])
                if(currentLength + 1 > lookup[j])
                    lookup[j] = currentLength + 1;
            if(sequence1[i] > sequence2[j])
                if(lookup[j] > currentLength)
                    currentLength = lookup[j];
        }
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "\nTime taken by p2: "
         << duration.count() << " microseconds. S1 & S2 size: " << sequence1.size() + sequence2.size() << endl;
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