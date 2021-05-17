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
    /* ######################CODE_START################################ */
    while(1) {
        int n, m;
        cin>>n>>m;

        if(cin.fail()) break;

        unordered_map<int, vector<int>> adjMap;
        for(int i=1;i<=n;++i) {
            int val;
            cin>>val;
            if(adjMap.find(val) == adjMap.end()) {
                adjMap[val] = vector<int>();
            }
            adjMap[val].push_back(i);
        }

        for(int i=0; i<m; ++i) {
            int k, v;
            cin>>k>>v;
            if(adjMap.find(v) != adjMap.end() && k <= adjMap[v].size()) {
                cout<<adjMap[v][k-1]<<endl;
            } else {
                cout<<0<<endl;
            }
        }
    }

    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}