#include<bits/stdc++.h>
#define DEBUG

using namespace std;

void ignore_lines(int n) {
    while(n--)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

unordered_map<char, int> code = {{'B',1},
                                     {'F', 1},
                                     {'P', 1},
                                     {'V', 1},
                                     {'C', 2},
                                     {'G', 2},
                                     {'J', 2},
                                     {'K', 2},
                                     {'Q', 2},
                                     {'S', 2},
                                     {'X', 2},
                                     {'Z', 2},
                                     {'D', 3},
                                     {'T', 3},
                                     {'L', 4},
                                     {'M', 5},
                                     {'N', 5},
                                     {'R', 6}};
int main() {
    #ifdef DEBUG
    ifstream in("input.txt");
    ofstream out("output.txt");

    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());
    #endif

    while(true) {
        string s;
        cin>>s;

        if(cin.fail()) break;
        string output;
        if(code[s[0]] != 0)
            output.append(to_string(code[s[0]]));
        for(int i=1;i<s.size();++i) {
            if(code[s[i]] != code[s[i-1]] && code[s[i]] != 0) {
                output.append(to_string(code[s[i]]));
            }
        }
        cout<<output<<endl;
    }
    return 0;
}