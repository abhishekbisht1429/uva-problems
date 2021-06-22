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

#define MAX_VAL 536870911
#define MIN_VAL -536870912
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
        int n;
        cin>>n;
        if(n==0) break;

        _vec<int> vec(n);
        for(int i=0; i<n; ++i) {
            cin>>vec[i];
        }

        /*Processing*/
        sort(vec.begin(), vec.end());
        _umap<int, _vec<pair<int, int>>> umap_ab;
        for(int i=0; i<n; ++i) {

            for(int j=i+1; j<n; ++j) {
                int sum_ab = vec[i] + vec[j];
                if(umap_ab.find(sum_ab) == umap_ab.end())
                    umap_ab[sum_ab] = _vec<pair<int, int>>();
                umap_ab[sum_ab].push_back({i, j});
            }
        }

        int d = INT_MAX;
        for(int di=n-1; di>=0; --di) {

            for(int ci=0; ci<n; ++ci) {
                if(ci == di) continue;
                
                int diff = vec[di] - vec[ci];
                if(umap_ab.find(diff) != umap_ab.end()) {
                    for(auto p : umap_ab[diff]) {
                        int ai = p.first;
                        int bi = p.second;
                        if(ci!=ai && ci!=bi && di!=ai && di!=bi) {
                            d = vec[di];
                            break;
                        }
                    }
                }
                if(d != INT_MAX) break;
            }
            if(d != INT_MAX) break;
        }

        /* OUTPUT */
        if(d != INT_MAX) {
            cout<<d<<"\n";
        } else {
            cout<<"no solution\n";
        }
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