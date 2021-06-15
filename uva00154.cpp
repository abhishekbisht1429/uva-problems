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
    bool end = false;
    while(!end) {
        _vec<_umap<char ,char>> cityM;
        while(1) {
            string str;
            cin>>str;

            if(str[0] == 'e' || (end = (str[0] == '#'))) break;

            //str.append(",");
            cityM.push_back(_umap<char, char>());
            for(int i=0; i<str.size(); i+=4) {
                cityM[cityM.size()-1][str[i]] = str[i+2];
            }
        }

        int ans, min_changes = INT_MAX;
        for(int i=0; i<cityM.size(); ++i) {
            int changes = 0;
            for(int j=0; j<cityM.size(); ++j) {
                for(auto p : cityM[j]) {
                    changes += (cityM[i][p.first] != p.second);
                }
            }
            if(changes < min_changes) {
                ans = i+1;
                min_changes = changes;
            }
        }
        if(end) break;

        cout<<ans<<"\n";
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