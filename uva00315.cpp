//
// Created by abhishek on 6/3/23.
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

/* pos[u] - position of the node u in the sequence of visit to each node */
/* lrp[u] - lowest reachable pos from the current dfs subtree of u */
void find_articulation_points(map<int, set<int>> &adj_list,
                              _vec<int> &pos,
                              _vec<int> &lrp,
                              _vec<bool> &is_ap,
                              int &counter,
                              int root,
                              int u,
                              int parent=-1) {
    pos[u] = counter++;
    lrp[u] = pos[u];
    is_ap[u] = false;
    /* this is count of children in the dfs spanning tree and not the graph */
    int children = 0;
    for(int v : adj_list[u]) {
        if(v == parent)
            continue;
        if(pos[v] == -1) {
            ++children;
            find_articulation_points(adj_list, pos, lrp, is_ap, counter, root, v, u);
            lrp[u] = min(lrp[u], lrp[v]);
            if(lrp[v] >= pos[u])
                is_ap[u] = true;
        } else {
            /* if a node is already visited, then it is not part of the subtree with root u */
            /* Since the visited node is reachable from the subtree with root u, we check if */
            /* the pos of this visited node is lower than the current lrp value for u */
            lrp[u] = min(lrp[u], pos[v]);
        }
    }
    if(u == root)
        is_ap[u] = (children > 1);
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
    _vec<int> pos, lrp, parent;
    _vec<bool> is_ap;
    while(1) {
        int n;
        cin>>n;
        if(n==0)
            break;
        adj_list.clear();
        pos.clear();
        lrp.clear();
        parent.clear();
        is_ap.clear();

        for(int i=0; i<n; ++i) {
            adj_list[i] = set<int>();
        }
        pos.resize(n, -1);
        lrp.resize(n, -1);
        parent.resize(n, -1);
        is_ap.resize(n);

        while(1) {
            string line;
            getline(cin, line);
            if(line == "0")
                break;
            istringstream iss(line);
            int u;
            iss>>u;
            --u;
            while(1) {
                int v;
                iss >> v;
                if(iss.fail())
                    break;
                --v;
                adj_list[u].insert(v);
                adj_list[v].insert(u);
            }
        }

        for(int i=0; i<n; ++i) {
            if(pos[i] == -1) {
                int rc_count = 0, counter = 0, root = i;
                find_articulation_points(adj_list, pos, lrp, is_ap,
                                         counter, root, root);
            }
        }

        int count = 0;
        for(int i=0; i<n; ++i)
            count += is_ap[i];
        cout<<count<<"\n";

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