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
    for(_ll n_tc = 1; n_tc <= tc; ++n_tc) {
        cout<<"Case #"<<n_tc<<": ";
        _ll n, m, k;
        cin>>n>>m>>k;
        _vec<_vec<_ll>> mat(n, _vec<_ll>(m));
        for(_ll i=0; i<n; ++i)
            for(_ll j=0; j<m; ++j)
                cin>>mat[i][j];

        _vec<_ll> squash(m);
        _ll p = 0, max_a = 0;
        for(_ll i1=0; i1<n; ++i1) {
            squash.assign(m, 0);
            for(_ll i2=i1; i2<n; ++i2) {
                bool plots_available = false;
                for(_ll j=0; j<m; ++j) {
                    squash[j] += mat[i2][j];
                    if(squash[j] <= k) plots_available = true;
                }
                if(!plots_available) break;
                
                _ll st = 0, sum = 0, a = 0;
                for(_ll j=0; j<m; ++j) {
                    sum += squash[j];
                    while(sum>k) sum -= squash[st++];

                    a = (i2-i1+1) * (j-st+1);
                    if(a > max_a) {
                        p = sum;
                        max_a = a;
                    } else if(a == max_a) {
                        p = min(p, sum);
                    }   
                }
            }
        }
        cout<<max_a<<" "<<p<<"\n";
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