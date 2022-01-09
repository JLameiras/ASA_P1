#include <iostream>
#include <fstream>
#include <vector>

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

    if(sequenceSize == 0 || sequenceSize == 1){
        cout << sequenceSize << ' ' << sequenceSize;
        return;
    }

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

    int A [n+1][m+1];

    for(int i = 0; i < n + 1; i++) A[i][0] = 0;
    for(int j = 0; j < m + 1; j++) A[0][j] = 0;

    for(int k = 1; k <= n; k++){
        for(int l = 1; l <= m; l++) {
            if (sequence1[k] == sequence2[l]) A[k][l] = A[k - 1][l - 1] + 1;
            else if (A[k - 1][l] >= A[k][l - 1]) A[k][l] = A[k - 1][l];
            else A[k][l] = A[k][l - 1];
        }
    }
    cout << A[n][m] << endl;
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