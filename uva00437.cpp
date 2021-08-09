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
typedef _tp<int, int, int> _iii;

bool canBuild(_iii &tp1, _iii &tp2) {
    return ((get<0>(tp1) < get<0>(tp2)) && (get<1>(tp1) < get<1>(tp2)));
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
    int tc = 0;
    while(1) {
        int n;
        cin>>n;
        if(n==0) break;
        _vec<_iii> blocks;
        for(int i=0; i<n; ++i) {
            int x, y, z;
            cin>>x>>y>>z;
            blocks.push_back(make_tuple(x, y, z));
            blocks.push_back(make_tuple(x, z, y));
            blocks.push_back(make_tuple(y, x, z));
            blocks.push_back(make_tuple(y, z, x));
            blocks.push_back(make_tuple(z, x, y));
            blocks.push_back(make_tuple(z, y, x));
        }
        sort(blocks.begin(), blocks.end());

        _vec<int> lh(blocks.size());
        lh[0] = get<2>(blocks[0]);
        for(int i=1; i<blocks.size(); ++i) {
            lh[i] = get<2>(blocks[i]);
            for(int j=i-1; j>=0; --j) {
                if(canBuild(blocks[j], blocks[i]))
                    lh[i] = max(lh[i], get<2>(blocks[i]) + lh[j]);
            }
        }
        int max_h = 0;
        for(int i=0; i<lh.size(); ++i)
            max_h = max(max_h, lh[i]);
        
        cout<<"Case "<<(++tc)<<": maximum height = "<<max_h<<"\n";

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