//
// Created by reckoner1429 on 11/01/22.
//

#include <bits/stdc++.h>

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
    int tc;
    cin>>tc;
    for(int tcn = 1; tcn<=tc; ++tcn) {
        cout<<"Case "<<tcn<<". ";
         int n;
         cin>>n;
         _vec<int> heights(n), widths(n);

         for(int i=0; i<n; ++i)
             cin>>heights[i];
         for(int i=0; i<n; ++i)
             cin>>widths[i];

         /* processing */

         /* lis */
         _vec<int> lis(n);
         int max_inc_len = 0;
         for(int i=0; i<n; ++i) {
             lis[i] = widths[i];
             for(int j=0; j<i; ++j) {
                 if(heights[j] < heights[i] && lis[j] + widths[i] > lis[i])
                     lis[i] = lis[j] + widths[i];
             }
             max_inc_len = max(max_inc_len, lis[i]);
         }

         /* lds */
         _vec<int> lds(n);
         int max_dec_len = 0;
         for(int i=0; i<n; ++i) {
             lds[i] = widths[i];
             for(int j=0; j<i; ++j) {
                 if(heights[j] > heights[i] && lds[j] + widths[i] > lds[i])
                     lds[i] = lds[j] + widths[i];
             }
             max_dec_len = max(max_dec_len, lds[i]);
         }

         if(max_inc_len >= max_dec_len)
             cout<<"Increasing ("<<max_inc_len<<"). Decreasing "
                                              "("<<max_dec_len<<").";
         else
             cout<<"Decreasing ("<<max_dec_len<<"). Increasing "
                                                "("<<max_inc_len<<").";
         cout<<"\n";
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