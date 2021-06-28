#include<bits/stdc++.h>

using namespace std;

#define DEBUG

#define _umap unordered_map
#define _uset unordered_set
#define _uint unsigned int
#define _ll long long
#define _ull unsigned _ll
#define _vec vector
#define _tp tuple
#define _p pair

#define _ignore_lines(n) for(int i=0;i<n;++i) cin.ignore(numeric_limits<streamsize>::max(), '\n')

/* Bit Manipulation */
#define _isSet(n, i) ((n) & (1<<(i)))
#define _set(n, i) n = ((n) | (1<<(i))) 
#define _reset(n, i) n = ((n) & (0xfffffffeL<<(i)))
#define _flip(n, i) n = ((n) ^ (1<<(i)))

#define _isSetl(n, i) ((n) & (1L<<(i)))
#define _setl(n, i) n = ((n) | (1L<<(i))) 
#define _resetl(n, i) n = ((n) & (0xfffffffffffffffeL<<(i)))
#define _flipl(n, i) n = ((n) ^ (1L<<(i)))

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
    int case_n = 0;
    while(1) {
        int n, x;
        cin>>n>>x;
        if(n==0 && x==0) break;

        _vec<int> customer(n);
        for(int i=0; i<n; ++i) {
            cin>>customer[i];
        }
        int m;
        cin>>m;
        _vec<_p<int, int>> common(m);
        for(int i=0; i<m; ++i) {
            int t;
            cin>>t;
            int ca = 0;
            int temp;
            while(t--) {
                cin>>temp;
                _set(ca, temp-1);
            }
            cin>>temp;
            common[i] = {ca, temp};
        }

        int opt_total = INT_MIN;
        int opt_s;
        for(int s = 0; s <= (1<<n); ++s) {
            if(__builtin_popcount(s) == x) {
                int total = 0;
                for(int i=0; i<n; ++i) {
                    if(_isSet(s, i)) {
                        total += customer[i];
                    }
                }

                for(auto p : common) {
                    int count = __builtin_popcount(s & p.first);
                    total -= max(0, count-1)*p.second;
                }
                if(total > opt_total) {
                    opt_total = total;
                    opt_s = s;
                } else if(total == opt_total) {
                    for(int i=0; i<n; ++i) {
                        if(_isSet(s, i) ==_isSet(opt_s, i)) continue;
                        
                        if(_isSet(s, i) > _isSet(opt_s, i)) {
                            opt_s = s;
                        }
                        break;
                    }
                }
            }
        }

        cout<<"Case Number  "<<(++case_n)<<"\n";
        cout<<"Number of Customers: "<<opt_total<<"\n";
        cout<<"Locations recommended:";
        for(int i = 0; i<n; ++i) {
            if(_isSet(opt_s, i)) cout<<" "<<i+1;
        }
        cout<<"\n\n";
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