//
// Created by reckoner1429 on 29/12/21.
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

int lis(_vec<int> &vec) {
    /* dp[i] = smallest ending element of any lis of length i */
    _vec<int> dp(vec.size(), INT_MAX);

    for(int i=0; i<vec.size(); ++i) {
        /* x = pos in dp of lower bound of vec[i] */
        int x = upper_bound(dp.begin(), dp.end(), vec[i]) -
                dp.begin();
        dp[x] = vec[i];
    }

    int count = 0;
    for(int i=0; i<dp.size(); ++i) {
        if(dp[i] == INT_MAX)
            break;
        ++count;
    }

    return count;
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
        if(n==0) {
            cout<<"*"<<"\n";
            break;
        }

        _vec<_ii> vec(n);
        for(int i=0; i<n; ++i)
            cin>>vec[i].first>>vec[i].second;

        /* sort based on l */
        sort(vec.begin(), vec.end());
        _vec<int> temp(n);
        for(int i=0; i<n; ++i)
            temp[i] = vec[i].second;

        int v1 = lis(temp);

        /* swap l and m */
        for(int i=0; i<n; ++i)
            swap(vec[i].first, vec[i].second);

        /* sort based on m */
        sort(vec.begin(), vec.end());

        for(int i=0; i<n; ++i)
            temp[i] = vec[i].second;

        int v2 = lis(temp);

        cout<<max(v1, v2)<<"\n";
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