#include<bits/stdc++.h>

using namespace std;

#define DEBUG

#define _umap unordered_map
#define _uset unordered_set
#define _ll long long
#define _ull unsigned _ll
#define _vec vector

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
    while(1) {
        double n1, n2;
        cin>>n1>>n2;
        if(cin.fail()) break;

        _ll l = (_ll)(n1*100);
        _ll r = (_ll)(n2*100);

        _vec<tuple<double, double, double, double>> res_vec;
        for(_ll a=1; 3*a<=r; ++a) {
            for(_ll b=a; a+2*b<=r; ++b) {
                if(a+b > r) break;

                _ll num = 10000*(a+b);
                _ll den = a*b - 10000;
                if(den > 0 && num % den == 0) {
                    _ll c = num/den;
                    _ll s = a+b+c;
                    _ll p = a*b*c;
                    if(p == s*10000 && s>=l && s<=r && c>=b) {
                        res_vec.push_back(make_tuple(s/100.0, a/100.0, b/100.0, c/100.0));
                    }
                }
            }
        }
        sort(res_vec.begin(), res_vec.end());

        for(auto tp : res_vec) {
            cout<<fixed<<setprecision(2)<<get<0>(tp)<<" = "<<get<1>(tp)<<" + "<<get<2>(tp)<<" + "<<get<3>(tp)<<" = "
                <<get<1>(tp)<<" * "<<get<2>(tp)<<" * "<<get<3>(tp)<<"\n";
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