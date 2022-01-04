//
// Created by reckoner1429 on 30/12/21.
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

bool comp(const _ii &a, const _ii &b) {
    return a.second > b.second && a.first < b.first;
}

bool compare(_p<_ii, int> a, _p<_ii, int> b) {
    return a.first.second > b.first.second;
}

_vec<int> lis(_vec<_ii> &vec) {
    /* dp[i] = length of LIS ending at i */
    _vec<int> dp(vec.size());
    _vec<int> p(vec.size());

    int end = 0;
    int max_len = 0;
    dp[0] = 1;
    p[0] = -1;
    for(int i=1; i<vec.size(); ++i) {
        p[i] = -1;
        dp[i] = 1;
        for(int j=0; j<i; ++j) {
            if(comp(vec[j], vec[i]) && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                p[i] = j;
            }
        }
        if(dp[i] > max_len) {
            max_len = dp[i];
            end = i;
        }
    }

    /* vec of indices of LIS */
    _vec<int> res;
    while(p[end] != -1) {
        res.push_back(end);
        end = p[end];
    }
    res.push_back(end);

    reverse(res.begin(), res.end());

    return res;
}


/*
 * don't know why this isn't working - maybe the UVA judge does not accept
 * the solution given by this algo even though it is correct
 * */
//_vec<int> lis(_vec<_ii> &vec) {
//    _vec<_ii> dp(vec.size(), {INT_MIN, INT_MAX});
//    _vec<int> index(vec.size(), -1);
//
//    int end = 0;
//
//    /* parent vector */
//    _vec<int> p(vec.size(), -1);
//
//    for(int i=0; i<vec.size(); ++i) {
//        int x = lower_bound(dp.begin(), dp.end(), vec[i], comp) -
//                dp.begin();
//        _ii temp = {INT_MIN, INT_MAX};
//        if(dp[x] == temp) {
//            if(x>0)
//                p[i] = index[x-1];
//            index[x] = i;
//            end = i;
//        }
//        dp[x] = vec[i];
//    }
//
//
//    /* vec of indices of LIS */
//    _vec<int> res;
//    while(p[end] != -1) {
//        res.push_back(end);
//        end = p[end];
//    }
//    res.push_back(end);
//
//    reverse(res.begin(), res.end());
//
//    return res;
//}

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
    _vec<_p<_ii, int>> vec;
    int s, iq;
    int count = 0;
    while(cin>>s>>iq) {
        vec.push_back({{s, iq}, ++count});
    }

    /* sort based on iq */
    sort(vec.begin(), vec.end(), compare);

    _vec<_ii> elephants(vec.size());
    for(int i=0; i<vec.size(); ++i) {
//        cout<<vec[i].first.first<<" "<<vec[i].first.second<<" "<<vec[i]
//        .second<<"\n";
        elephants[i] = vec[i].first;
    }

    /* find the LIS */
    _vec<int> res = lis(elephants);

    /* Print result */
    cout<<res.size()<<"\n";
    for(int i : res) {
        cout<<vec[i].second<<"\n";
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