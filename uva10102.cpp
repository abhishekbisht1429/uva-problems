#include<bits/stdc++.h>

using namespace std;

#define DEBUG

#define _umap unordered_map
#define _uset unordered_set
#define _ll long long
#define _ull unsigned _ll
#define _vec vector

#define _max3(a, b, c) max(a, max(b, c))
#define _max4(a, b, c, d) max(max(a, b), max(c, d))
#define _min3(a, b, c) min(a, min(b, c))
#define _min4(a, b, c, d) min(min(a, b), min(c, d))
#define _ignore_lines(n) for(int i=0;i<n;++i) cin.ignore(numeric_limits<streamsize>::max(), '\n')

/* Bit Manipulation */
#define _isSet(n, i) (n & (1L<<i))
#define _set(n, i) n = (n | (1L<<i)) 
#define _reset(n, i) n = (n & (0xfffffffffffffffeL<<i))
#define _flip(n, i) n = (n ^ (1L<<i))

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
        int m;
        cin>>m;
        if(cin.fail()) break;
        _vec<pair<int, int>> pos_1, pos_3;
        for(int i=0; i<m; ++i) {
            string temp;
            cin>>temp;
            for(int j=0; j<m; ++j) {
                if(temp[j] == '1') pos_1.push_back({i, j});
                else if(temp[j] == '3') pos_3.push_back({i, j});
            }
        }
        /* Processing */
        int max_d = INT_MIN;
        for(auto p1 : pos_1) {
            int i1 = p1.first;
            int j1 = p1.second;
            int min_d = INT_MAX;

            for(auto p3 : pos_3) {
                int i3 = p3.first;
                int j3 = p3.second;
                int dist = abs(j3 - j1) + abs(i3 - i1);
                min_d = min(min_d, dist);
            }
            max_d = max(max_d, min_d);
        }
        cout<<max_d<<"\n";
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