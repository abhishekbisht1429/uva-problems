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
#define _reset(n, i) n = (n & ((-1u<<1)<<(i)))
#define _flip(n, i) n = (n ^ (1u<<(i)))
#define _rset(n, i, cnt) n = n | (((1u<<(cnt))-1)<<i)
#define _rreset(n, i, cnt) n = n & ~(((1u<<(cnt))-1)<<i)
#define _ffzi(n, i) __builtin_ffs(~(((1u<<i+1)-1) | n))

#define _isSetl(n, i) ((n) & (1ull<<(i)))
#define _setl(n, i) n = ((n) | (1ull<<(i))) 
#define _resetl(n, i) n = ((n) & ((-1ull<<1)<<(i)))
#define _flipl(n, i) n = ((n) ^ (1ull<<(i)))
#define _rsetl(n, i, cnt) n = n | (((1ull<<(cnt))-1)<<i)
#define _rresetl(n, i, cnt) n = n & ~(((1ull<<(cnt))-1)<<i)
#define _ffzil(n, i) __builtin_ffs(~(((1ull<<i+1)-1) | n))

int longestPath(_umap<int, _vec<int>> &adj_map, int s, _vec<_vec<int>> &not_visited) {
    int max_len = 0;
    for(int adj : adj_map[s]) {
        if(not_visited[s][adj]) {
            not_visited[s][adj]--;
            not_visited[adj][s]--;
            max_len = max(max_len, 1 + longestPath(adj_map, adj, not_visited));
            not_visited[s][adj]++;
            not_visited[adj][s]++;
        }
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
    _umap<int, _vec<int>> adj_map;
    while(1) {
        adj_map.clear();
        int n, m;
        cin>>n>>m;
        if(n==0 && m==0) break;

        _vec<_vec<int>> not_visited(n, _vec<int>(n));
        for(int i=0; i<m; ++i) {
            int u, v;
            cin>>u>>v;
            if(adj_map.find(u) == adj_map.end()) adj_map[u] = _vec<int>();
            if(adj_map.find(v) == adj_map.end()) adj_map[v] = _vec<int>();

            adj_map[u].push_back(v);
            adj_map[v].push_back(u);
            not_visited[u][v]++;
            not_visited[v][u]++;
        }

        int max_len = 0;
        for(int i=0; i<n; ++i) {
            max_len = max(max_len, longestPath(adj_map, i, not_visited));
        }
        cout<<max_len<<"\n";
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