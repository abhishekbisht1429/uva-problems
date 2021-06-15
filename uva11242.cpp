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

// bool comp(pair<int, int> &p1, pair<int, int> &p2) {
//     double d1 = p1.first/(double)p1.second;
//     double d2 = p2.first/(double)p2.second;

//     return d1 < d2;
// }
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
        int f, r;
        cin>>f>>r;

        if(f==0) break;

        _vec<int> tf(f), tr(r);
        for(int i=0; i<f; ++i) {
            cin>>tf[i];
        }
        for(int i=0; i<r; ++i) {
            cin>>tr[i];
        }

        _vec<double> d;
        for(int i=0; i<f; ++i) {
            for(int j=0; j<r; ++j) {
                d.push_back(tr[j]/(double)tf[i]);
            }
        }
        sort(d.begin(), d.end());

        double max_sp = 0;
        for(int i=0; i<d.size()-1; ++i) {
            max_sp = max(max_sp, d[i+1] / d[i]);
        }
        max_sp = round(max_sp*100)/100;
        cout<<fixed<<setprecision(2)<<max_sp<<"\n";
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