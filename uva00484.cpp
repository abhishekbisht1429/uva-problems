#include<bits/stdc++.h>
#define DEBUG

using namespace std;

void ignore_lines(int n) {
    while(n--)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
int main() {
    #ifdef DEBUG
    ifstream in("input.txt");
    ofstream out("output.txt");
    streambuf* in_backup = cin.rdbuf();
    streambuf* out_backup = cout.rdbuf();
    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf()); 
    #endif

    unordered_map<int, int> freq_map;
    unordered_set<int> printed;
    vector<int> seq;

    while(1) {
        int n;
        cin>>n;

        if(cin.fail()) break;

        seq.push_back(n);
        freq_map[n] = freq_map[n] + 1;
    }

    for(int i : seq) {
        if(printed.find(i) == printed.end()) {
            cout<<i<<" "<<freq_map[i]<<endl;
            printed.insert(i);
        }        
    }






    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}