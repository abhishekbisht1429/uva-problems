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
        unordered_map<int, vector<pair<int, int>>> adjMap, adjMapTp;
        int m, n;
        cin>>m>>n;

        if(cin.fail()) break;

        for(int i=1;i<=m;++i) {
            if(adjMap.find(i) == adjMap.end()) {
                adjMap[i] = vector<pair<int, int>>();
            }
            int c;
            cin>>c;
            vector<int> col_idx(c);
            for(int j=0;j<c;++j) {
                cin>>col_idx[j];
            }
            for(int j=0;j<c;++j) {
                int val;
                cin>>val;
                adjMap[i].push_back({col_idx[j], val});
            }
        }

        //find transpose
        for(int i=1; i<=m; ++i) {
            for(auto p : adjMap[i]) {
                if(adjMapTp.find(p.first) == adjMapTp.end()) {
                    adjMapTp[p.first] = vector<pair<int, int>>();
                }
                adjMapTp[p.first].push_back({i, p.second});
            }
        }

        //output
        cout<<n<<" "<<m<<endl;
        for(int i=1;i<=n;++i) {
            cout<<adjMapTp[i].size();
            vector<int> idx;
            for(auto p : adjMapTp[i]) {
                idx.push_back(p.first);
            }
            for(int j=0;j<idx.size();++j) {
                cout<<" "<<idx[j];
            }
            cout<<endl;
            for(int j=0; j<adjMapTp[i].size(); ++j) {
                if(j!=0) cout<<" ";
                cout<<adjMapTp[i][j].second;
            }
            cout<<endl;
        }
    }
    

    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}