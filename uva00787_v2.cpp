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
int n;
_vec<_vec<int>> cum_mat;
void init_tc() {
    cum_mat = _vec<_vec<int>>(n, _vec<int>(n));
}
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
        cin>>n;
        if(cin.fail()) break;
        init_tc();

        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                cin>>cum_mat[i][j];

                if(i>0) cum_mat[i][j] += cum_mat[i-1][j];
            }
        }

        int max_sum = INT_MIN;
        _vec<int> squashed_col(n);
        for(int i1 = 0; i1<n; ++i1) {
            for(int i2 = i1; i2<n; ++i2) {
                for(int j=0; j<n; ++j)
                    squashed_col[j] = cum_mat[i2][j] - cum_mat[i1][j];
                
                int max_sqs_sum = INT_MIN, sum = 0;
                for(int j=0; j<n; ++j) {
                    sum += squashed_col[j];
                    max_sqs_sum = max(max_sqs_sum, sum);
                    if(sum < 0) sum = 0;
                }

                max_sum = max(max_sum, max_sqs_sum);
            }
        }

        cout<<max_sum<<"\n";
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