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
#define _isSet(n, i) ((n) & (1u<<(i)))
#define _set(n, i) n = (n | (1u<<(i))) 
#define _reset(n, i) n = (n & (~(1u<<(i))))
#define _flip(n, i) n = (n ^ (1u<<(i)))
#define _rset(n, i, cnt) n = n | (((1u<<(cnt))-1)<<i)
#define _rreset(n, i, cnt) n = n & ~(((1u<<(cnt))-1)<<i)
#define _ffzi(n, i) __builtin_ffs(~(((1u<<i+1)-1) | n))

#define _isSetl(n, i) ((n) & (1ull<<(i)))
#define _setl(n, i) n = ((n) | (1ull<<(i))) 
#define _resetl(n, i) n = (n & (~(1ull<<(i))))
#define _flipl(n, i) n = ((n) ^ (1ull<<(i)))
#define _rsetl(n, i, cnt) n = n | (((1ull<<(cnt))-1)<<i)
#define _rresetl(n, i, cnt) n = n & ~(((1ull<<(cnt))-1)<<i)
#define _ffzil(n, i) __builtin_ffs(~(((1ull<<i+1)-1) | n))

typedef _p<int, int> _ii;

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
    _ll tc;
    cin>>tc;
    while(tc--) {
        _ll a, b, c;
        cin>>a>>b>>c;
        _vec<_vec<_vec<_ll>>> vec(a, _vec<_vec<_ll>>(b, _vec<_ll>(c)));
        for(_ll i=0; i<a; ++i) {
            for(_ll j=0; j<b; ++j) {
                for(_ll k=0; k<c; ++k) {
                    cin>>vec[i][j][k];

                    if(i>0) vec[i][j][k] += vec[i-1][j][k];
                    if(j>0) vec[i][j][k] += vec[i][j-1][k];
                    if(i>0 && j>0) vec[i][j][k] -= vec[i-1][j-1][k];
                }
            }
        }

        _ll max_sum = LLONG_MIN;
        _vec<_ll> sum_2d(c);
        for(_ll i1=0; i1<a; ++i1) for(_ll j1=0; j1<b; ++j1) {
            for(_ll i2=i1; i2<a; ++i2) for(_ll j2=j1; j2<b; ++j2) {
                for(_ll k=0; k<c; ++k) {
                    sum_2d[k] = vec[i2][j2][k];

                    if(j1>0) sum_2d[k] -= vec[i2][j1-1][k];
                    if(i1>0) sum_2d[k] -= vec[i1-1][j2][k];
                    if(i1>0 && j1>0) sum_2d[k] += vec[i1-1][j1-1][k];
                }

                _ll sub_max_sum = LLONG_MIN, sum = 0;
                for(_ll k=0; k<c; ++k) {
                    sum += sum_2d[k];
                    sub_max_sum = max(sub_max_sum, sum);
                    if(sum < 0)
                        sum = 0;
                }
                max_sum = max(max_sum, sub_max_sum);
            }
        }

        cout<<max_sum<<"\n";
        if(tc) cout<<"\n";
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