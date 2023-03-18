//
// Created by abhishek on 18/3/23.
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

void find_bridges(map<int, set<int>> &adj_list,
                  _vec<int> &pos,
                  _vec<int> &lrp,
                  int &counter,
                  set<_ii> &bridge_set,
                  int u,
                  int parent=-1) {
    pos[u] = lrp[u] = counter++;
    for(int v : adj_list[u]) {
        if(v == parent)
            continue;
        if(pos[v] == -1) {
            find_bridges(adj_list, pos, lrp, counter, bridge_set, v, u);
            lrp[u] = min(lrp[u], lrp[v]);
            if(lrp[v] > pos[u]) {
                int min_vtx = min(u, v);
                int max_vtx = max(u, v);
                bridge_set.insert({min_vtx, max_vtx});
            }
        } else {
            lrp[u] = min(lrp[u], pos[v]);
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
    map<int, set<int>> adj_list;
    set<_ii> bridge_set;
    _vec<int> pos, lrp;
    while(1) {
        int n;
        cin>>n;
        if(cin.fail())
            break;
        adj_list.clear();
        bridge_set.clear();
        pos.clear();
        lrp.clear();
        for(int i=0; i<n; ++i) {
            adj_list[i] = set<int>();
        }
        pos.resize(n, -1);
        lrp.resize(n, -1);

        for(int i=0; i<n; ++i) {
            int u;
            cin>>u;
            char temp_c;
            int m;
            cin>>temp_c>>m>>temp_c;
            for(int j=0; j<m; ++j) {
                int v;
                cin>>v;
                adj_list[u].insert(v);
                adj_list[v].insert(u);
            }
        }

        for(int u=0; u<n; ++u) {
            int counter = 0;
            if(pos[u] == -1)
                find_bridges(adj_list, pos, lrp, counter, bridge_set, u);
        }

        cout<<bridge_set.size()<<" critical links\n";
        for(auto &edge : bridge_set) {
            cout<<edge.first<<" - "<<edge.second<<"\n";
        }
        cout<<"\n";

//        for(int u=0; u<n; ++u) {
//            cout<<u<<": ";
//            for(int v : adj_list[u]) {
//                cout<<v<<" ";
//            }
//            cout<<"\n";
//        }
//        cout<<"\n";


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