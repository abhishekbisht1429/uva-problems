//
// Created by reckoner1429 on 07/01/22.
//

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


int longest_train(_vec<int> &vec) {
    int n = vec.size();
    /* lis[i] = lis starting at i
     * lds[i] = lds starting at i
     * */
    _vec<int> lis(n), lds(n);
    _vec<int> l;

    /* lds */
    for(int i=n-1; i>=0; --i) {
        int pos = lower_bound(l.begin(), l.end(), vec[i]) -
                l.begin();
        if(pos == l.size())
            l.push_back(vec[i]);
        else
            l[pos] = vec[i];
        lds[i] = pos+1;
    }

    l.clear();

    /* lis */
    for(int i=n-1; i>=0; --i) {
        int pos = lower_bound(l.begin(), l.end(), vec[i], greater<int>()) -
                  l.begin();
        if(pos == l.size())
            l.push_back(vec[i]);
        else
            l[pos] = vec[i];
        lis[i] = pos+1;
    }

    int max_len = 0;
    for(int i=0; i<n; ++i)
        max_len = max(max_len, lis[i] + lds[i] - 1);

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
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        _vec<int> vec(n);
        for(int i=0; i<n; ++i)
            cin>>vec[i];

        cout<<longest_train(vec)<<"\n";
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

