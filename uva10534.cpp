//
// Created by reckoner1429 on 04/01/22.
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

int wavio(_vec<int> &vec) {
    /* dp1[i] = len of lis ending at i */
    _vec<int> dp1(vec.size());
    _vec<int> l1(vec.size(), INT_MAX);

    _vec<int> dp2(vec.size());
    _vec<int> l2(vec.size(), INT_MAX);
    int n = vec.size();

    /* for lis */
    for(int i=0; i<n; ++i) {
        int pos = lower_bound(l1.begin(), l1.end(), vec[i]) -
                l1.begin();
        l1[pos] = vec[i];
        dp1[i] = pos+1;
    }

    /* for lds */
    for(int i=n-1; i>=0; --i) {
        int pos = lower_bound(l2.begin(), l2.end(), vec[i]) -
                l2.begin();
        l2[pos] = vec[i];
        dp2[i] = pos+1;
    }

    /* find wavio len */
    int max_len = 0;
    for(int i=0; i<n; ++i) {
        max_len = max(max_len, 2 * min(dp1[i], dp2[i]) - 1);
    }

    return max_len;
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
        int n;
        cin>>n;
        if(cin.fail()) break;

        _vec<int> vec(n);
        for(int i=0; i<n; ++i)
            cin>>vec[i];

        cout<<wavio(vec)<<"\n";
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
