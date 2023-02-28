//
// Created by abhishek on 28/2/23.
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

bool is_bipartite(map<int, set<int>> adj_list) {
    _vec<int> color(adj_list.size(), -1);
    queue<int> q;
    q.push(0);
    color[0] = 0;
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        for(int adj : adj_list[front]) {
            if(color[adj] == -1) {
                color[adj] = (color[front] + 1) % 2;
                q.push(adj);
            } else if (color[adj] == color[front]) {
                return false;
            }
        }
    }
    return true;
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
    map<int, set<int>> adj_list;
    while(true) {
        int n;
        cin>>n;
        if(n==0)
            break;
        adj_list.clear();
        for(int i=0; i<n; ++i)
            adj_list[i] = set<int>();
        while(true) {
            int u, v;
            cin>>u>>v;
            if(u==0 && v==0)
                break;
            --u; --v;
            adj_list[u].insert(v);
            adj_list[v].insert(u);
        }
        if(is_bipartite(adj_list)) {
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
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