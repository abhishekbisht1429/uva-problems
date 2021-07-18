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

int n, k;
_umap<int, _uset<int>> adj_map;
_uset<int> selected, max_selected;
void init_tc() {
    adj_map.clear();
    selected.clear();
    max_selected.clear();
}
bool check(int v) {
    for(int u : selected) {
        if(adj_map[u].find(v) != adj_map[u].end())
            return false;
    }
    return true;
} 
void find(int v=0) {
    if(v==n) {
        if(selected.size() > max_selected.size()) {
            max_selected = selected;
        }
        return;
    }

    if(check(v)) {
        selected.insert(v);
        find(v+1);
        selected.erase(v);
    }
    find(v+1);
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
    int m;
    cin>>m;
    while(m--) {
        cin>>n>>k;
        init_tc();

        for(int i=0; i<k; ++i) {
            int u, v;
            cin>>u>>v;
            u--; v--;
            if(adj_map.find(u) == adj_map.end())
                adj_map[u] = _uset<int>();
            if(adj_map.find(v) == adj_map.end())
                adj_map[v] = _uset<int>();
            
            adj_map[u].insert(v);
            adj_map[v].insert(u);
        }

        find();
        _vec<int> res(max_selected.begin(), max_selected.end());
        sort(res.begin(), res.end());

        cout<<res.size()<<"\n";
        cout<<res[0]+1;
        for(int i=1; i<res.size(); ++i) {
            cout<<" "<<res[i]+1;
        }
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