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
    _vec<tuple<double, double, double, double>> res;
    for(_ll a=1; 4*a<=2000; ++a) {
        for(_ll b=a; 3*a+b<=2000; ++b) {
            for(_ll c=b; 2*a+b+c<=2000; ++c) {
                _ll num = (a+b+c)*1000000;
                _ll den = a*b*c - 1000000;
                if(den > 0 && num % den == 0) {
                    _ll d = num/den;
                    if(d>=c) {
                        _ll s = a+b+c+d;
                        _ll p = a*b*c*d;
                        if(p = s*1000000 && s <= 2000) {
                            res.push_back(make_tuple(a/100.0, b/100.0, c/100.0, d/100.0));
                        }
                    }
                }
            }
        }
    }

    for(auto tp : res) {
        cout<<fixed<<setprecision(2)<<get<0>(tp)<<" "<<get<1>(tp)<<" "<<get<2>(tp)<<" "<<get<3>(tp)<<"\n";
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