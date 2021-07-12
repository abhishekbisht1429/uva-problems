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

_vec<_vec<_uset<string>>> store(20, _vec<_uset<string>>(20));
bool valid(int i, int j, int n) {
    if(i<0 || i>=n || j<0 || j>=n)
        return false;
    return true;
}
/* This solution makes use of dynamic programming */
void visit(_vec<string> &table, int i, int j, char prev = 0) {    
    /* size of store[i][j] is acting as visited flag in the line below.
        If size if not zero, it means that the chains starting from that letter 
        have been already computed and stored in 'store' */
    if(store[i][j].size()>0 || table[i][j] <= prev) {
        return;
    }

    string str = "";
    str.append(1, table[i][j]);
    store[i][j].insert(str);
    _vec<_ii> temp = {{i, j+1}, {i, j-1}, {i+1, j}, {i+1, j+1},
                      {i+1, j-1}, {i-1, j}, {i-1, j+1}, {i-1, j-1}};
    for(auto p : temp) {
        if(valid(p.first, p.second, table.size())) {

            visit(table, p.first, p.second, table[i][j]);

            if(table[p.first][p.second] > table[i][j]) {

                /* more work per call here */
                for(string str : store[p.first][p.second]) {
                    str.insert(0, 1, table[i][j]);
                    store[i][j].insert(str);
                }
            }
        }
    }
}
bool comp(string &s1, string &s2) {
    if(s1.size()<s2.size()) return true;
    else if(s1.size() == s2.size()) return s1<s2;
    else return false;
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
    int tc;
    cin>>tc;
    while(tc--) {
        int n;
        cin>>n;
        _vec<string> table(n);
        for(int i=0; i<n; ++i) {
            cin>>table[i];
        }
        
        /* Processing */
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                store[i][j].clear();
            }
        }

        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                visit(table, i, j);
            }
        }
        _uset<string> res;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                for(string str : store[i][j]) {
                    //cout<<str<<", ";
                    if(str.size() >= 3)
                        res.insert(str);
                }
                // cout<<"\n";
            }
        }
        _vec<string> res_vec(res.begin(), res.end());
        sort(res_vec.begin(), res_vec.end(), comp);
        for(string str : res_vec) {
            cout<<str<<"\n";
        }
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