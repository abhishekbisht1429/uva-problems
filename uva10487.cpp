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
#define _ignore_lines(n) for(_ll i=0;i<n;++i) cin.ignore(numeric_limits<streamsize>::max(), '\n')

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
    _ll t = 0;
    while(1) {
        _ll n;
        cin>>n;

        if(n==0) break;

        _uset<_ll> num_set(n);

        for(_ll i=0; i<n; ++i) {
            _ll temp;
            cin>>temp;
            num_set.insert(temp);
        }

        cout << "Case "<< t+1 << ":\n";
        _ll m;
        cin>>m;
        while(m--) {
            _ll q;
            cin>>q;
            _ll min_sum = *(num_set.begin()) + *(++num_set.begin());
            for(auto i=num_set.begin(); i!=num_set.end(); ++i) {
                auto j = i;
                ++j;
                for(; j!=num_set.end(); ++j) {
                    _ll temp = *i + *j;
                    if(abs(temp - q) < abs(min_sum - q)) {
                        min_sum = temp;
                    }
                }
            }
            cout<<"Closest sum to " << q << " is " << min_sum << ".\n";
        }
        ++t;
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