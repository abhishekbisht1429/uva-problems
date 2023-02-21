//
// Created by abhishek on 21/2/23.
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

void find_order(map<int, set<int>> &adj_list, _vec<bool> &visited, _vec<int> &order, int task) {
    visited[task] = true;
    for(int next_task : adj_list[task]) {
        if(!visited[next_task])
            find_order(adj_list, visited, order, next_task);
    }
    order.push_back(task);
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
    set<int> not_starting_tasks;
    while(1) {
        int n, m;
        cin>>n>>m;
        if(n == 0 && m == 0)
            break;
        adj_list.clear();
        not_starting_tasks.clear();
        for(int task=1; task<=n; ++task)
            adj_list[task] = set<int>();
        for(int i=0; i<m; ++i) {
            int u, v;
            cin>>u>>v;
            adj_list[u].insert(v);
            not_starting_tasks.insert(v);
        }
        set<int> starting_tasks;
        for(int task=1; task<=n; ++task) {
            if(not_starting_tasks.find(task) == not_starting_tasks.end()) {
                starting_tasks.insert(task);
            }
        }

        _vec<bool> visited(n+1);
        _vec<int> order;
        for(int start : starting_tasks) {
            find_order(adj_list, visited, order, start);
        reverse(order.begin(), order.end());
        for(int i=0; i<order.size(); ++i) {
            if(i!=0)
                cout<<" ";
            cout<<order[i];
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