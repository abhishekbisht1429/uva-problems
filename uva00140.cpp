#include<bits/stdc++.h>

using namespace std;

#define DEBUG

#define _umap unordered_map
#define _uset unordered_set
#define _ll long long
#define _ull unsigned _ll
#define _vec vector
#define _tp tuple
#define _p pair

#define _ignore_lines(n) for(int i=0;i<n;++i) cin.ignore(numeric_limits<streamsize>::max(), '\n')

/* Bit Manipulation */
#define _isSet(n, i) (n & (1L<<i))
#define _set(n, i) n = (n | (1L<<i)) 
#define _reset(n, i) n = (n & (0xfffffffffffffffeL<<i))
#define _flip(n, i) n = (n ^ (1L<<i))

int findBW(string &ordering, _umap<char, _uset<char>> &adjMap) {
    int bw = 0;
    for(auto p : adjMap) {
        char v = p.first;
        for(char adj : p.second) {
            int pos_v = ordering.find(v);
            int pos_adj = ordering.find(adj);
            bw = max(bw, abs(pos_v - pos_adj));
        }
    }
    return bw;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef DEBUG
    ifstream _in("input.txt");
    ofstream _out("output.txt");
    streambuf* _in_backup = cin.rdbuf();
    streambuf* _out_backup = cout.rdbuf();
    cin.rdbuf(_in.rdbuf());
    cout.rdbuf(_out.rdbuf());
    auto _start = chrono::high_resolution_clock::now();
    #endif

    /* ######################CODE_START################################ */
    while(1) {
        _umap<char, _uset<char>> adjMap;
        string inp;
        getline(cin, inp);
        if(inp[0] == '#') break;

        inp.push_back(';');
        int i=0;
        while(i<inp.size()) {
            int pos = inp.find(';', i);
            string rec = inp.substr(i, pos-i);
            char v = rec[0];
            rec = rec.substr(2);
            for(char c : rec) {
                if(adjMap.find(v) == adjMap.end()) {
                    adjMap[v] = _uset<char>();
                }
                if(adjMap.find(c) == adjMap.end()) {
                    adjMap[c] = _uset<char>();
                }
                adjMap[v].insert(c);
                adjMap[c].insert(v);
            }
            i = pos+1;
        }

        string ordering;
        for(auto p : adjMap) {
            ordering.push_back(p.first);
        }
        sort(ordering.begin(), ordering.end());

        int min_bw = INT_MAX;
        string ans;
        do {
            int bw = findBW(ordering, adjMap);
            if(bw < min_bw) {
                min_bw = bw;
                ans = ordering;
            }
        } while(next_permutation(ordering.begin(), ordering.end()));

        for(int i=0; i<ans.size(); ++i) {
            cout<<ans[i]<<" ";
        }
        cout<<"-> "<<min_bw<<'\n';

    }


    /* #######################CODE_END############################### */
    #ifdef DEBUG
    auto _end = chrono::high_resolution_clock::now();
    auto _duration = chrono::duration_cast<chrono::nanoseconds>(_end - _start);
    _ll _ns = _duration.count();
    double _s = _ns / 1e9;
    cout<<"\nDuration: "<<_s<<" sec\n";
    cin.rdbuf(_in_backup);
    cout.rdbuf(_out_backup);
    #endif
    return 0;
}