//
// Created by abhishek on 17/3/23.
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
                  set<_ii> &ans_set,
                  int &counter,
                  int root,
                  int u,
                  int parent=-1) {
    lrp[u] = pos[u] = counter++;
    for(int v : adj_list[u]) {
        if(v == parent)
            continue;
        if(pos[v] == -1) {
            find_bridges(adj_list, pos, lrp, ans_set, counter, root, v, u);
            lrp[u] = min(lrp[u], lrp[v]);
            if(lrp[v] > pos[u]) { // bridge
                ans_set.insert({u, v});
                ans_set.insert({v, u});
            } else {
                ans_set.insert({u, v});
            }
        } else {
            lrp[u] = min(lrp[u], pos[v]);
            if(ans_set.find({u, v}) == ans_set.end() &&
               ans_set.find({v, u}) == ans_set.end()) {
                ans_set.insert({u, v});
            }
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
    _vec<int> pos, lrp;
    set<_ii> ans_set;
    set<_ii> edges;
    int tc = 0;
    while(1) {
        int n, m;
        cin>>n>>m;
        if(n==0 && m==0)
            break;
        adj_list.clear();
        pos.clear();
        lrp.clear();
        ans_set.clear();
        edges.clear();

        for(int i=0; i<n; ++i)
            adj_list[i] = set<int>();
        pos.resize(n, -1);
        lrp.resize(n, -1);

        for(int i=0; i<m; ++i) {
            int u, v;
            cin>>u>>v;
            --u; --v;
            adj_list[u].insert(v);
            adj_list[v].insert(u);
            edges.insert({u, v});
        }

        int counter = 0;
        find_bridges(adj_list, pos, lrp, ans_set, counter, 0, 0);
//        set<_ii> ans;
//        for(auto &edge : edges) {
//            if(ans_set.find(edge) == ans_set.end()) {
//                ans.insert(edge);
//            } else {
//                ans.insert(edge);
//                ans.insert({edge.second, edge.first});
//            }
//        }

        cout<<(++tc)<<"\n\n";
        for(auto &edge : ans_set) {
            cout<<edge.first+1<<" "<<edge.second+1<<"\n";
        }
        cout<<"#"<<"\n";

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