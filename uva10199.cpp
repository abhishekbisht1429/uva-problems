//
// Created by abhishek on 30/3/23.
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

//lrp[u] = least reachable position from subtree rooted at u
void find_articulation_points(map<int, set<int>> &adj_map,
                              _vec<int> &pos,
                              _vec<int> &lrp,
                              _vec<bool> &is_ap,
                              int &counter,
                              int u,
                              int root,
                              int parent=-1) {
    lrp[u] = pos[u] = counter++;
    int dag_children_count = 0;
    for(int v : adj_map[u]) {
        if(v == parent)
            continue;
        if(pos[v] == -1) {
            ++dag_children_count;
            find_articulation_points(adj_map, pos, lrp, is_ap, counter, v, u);
            if(lrp[v] >= pos[u]) {
                is_ap[u] = true;
            }
            lrp[u] = min(lrp[u], lrp[v]);
        } else {
            lrp[u] = min(lrp[u], pos[v]);
        }
    }
    if(u == root) {
        is_ap[u] = (dag_children_count > 1);
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
    map<int, set<int>> adj_map;
    _vec<int> pos, lrp;
    _vec<bool> is_ap;
    int tc = 0;
    while(1) {
        int n;
        cin>>n;
        if(n==0)
            break;
        adj_map.clear();
        pos.clear();
        lrp.clear();
        is_ap.clear();
        pos.resize(n, -1);
        lrp.resize(n, -1);
        is_ap.resize(n);

        vector<string> city_names(n);
        map<string, int> name_to_index;
        for(int i=0; i<n; ++i) {
            cin>>city_names[i];
            name_to_index[city_names[i]] = i;
            adj_map[i] = set<int>();
        }
        int r;
        cin>>r;
        for(int i=0; i<r; ++i) {
            string u_name, v_name;
            cin >> u_name >> v_name;
            int u = name_to_index[u_name];
            int v = name_to_index[v_name];
            adj_map[u].insert(v);
            adj_map[v].insert(u);
        }

        for(int u=0; u<n; ++u) {
            if(pos[u] == -1) {
                int counter = 0;
                find_articulation_points(adj_map, pos, lrp, is_ap, counter, u, u);
            }
        }

        int cam_count = 0;
        set<string> cam_locs;
        for(int u=0; u < n; ++u) {
            if(is_ap[u]) {
                ++cam_count;
                cam_locs.insert(city_names[u]);
            }
        }
        if(tc>0)
            cout<<"\n";
        cout<<"City map #"<<(++tc)<<": "<<cam_count<<" camera(s) found\n";
        for(string loc : cam_locs) {
                cout<<loc<<"\n";
        }

//        for(int i=0; i<n; ++i) {
//            cout<<i<<": ";
//            for(int v : adj_map[i]) {
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