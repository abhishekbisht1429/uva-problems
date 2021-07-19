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

int dest;
_uint visited, reachable;
_vec<int> trace;
_vec<_vec<int>> routes;
_umap<int, _vec<int>> adj_map;
void init_tc() {
    adj_map.clear();
    visited = 0;
    reachable = 0;
    trace.clear();
    routes.clear();
}

void findRoute(int v = 0) {
    if(!_isSet(reachable, v) || _isSet(visited, v))
        return;

    _set(visited, v);
    trace.push_back(v);
    if(v == dest) {
        routes.push_back(trace);
    } else {
        for(int adj : adj_map[v])
            findRoute(adj);
    }
    trace.pop_back();
    _reset(visited, v);
}

void setReachable(int v) {
    _set(reachable, v);
    for(int adj : adj_map[v]) {
        if(!_isSet(reachable, adj)) {
            setReachable(adj);
        }
    }
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
        cin>>dest;
        if(cin.fail()) break;
        dest--;
        init_tc();
        adj_map[dest] = _vec<int>();
        while(1) {
            int u, v;
            cin>>u>>v;
            if(u==0 && v==0) break;
            u--; v--;
            if(adj_map.find(u) == adj_map.end())
                adj_map[u] = _vec<int>();
            if(adj_map.find(v) == adj_map.end())
                adj_map[v] = _vec<int>();
            adj_map[u].push_back(v);
            adj_map[v].push_back(u);
        }
        setReachable(dest);

        cout<<"CASE "<<(++tc)<<":\n";
        findRoute();
        sort(routes.begin(), routes.end());
        for(auto route : routes) {
            cout<<route[0]+1;
            for(int i=1; i<route.size(); ++i) {
                cout<<" "<<route[i]+1;
            }
            cout<<"\n";
        }
        cout<<"There are "<<routes.size()<<" routes from the firestation to streetcorner "<<dest+1<<".\n";
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