//
// Created by abhishek on 1/3/23.
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

int min_guards(map<int, set<int>> adj_list, _vec<int> &color, set<int> &not_colored, int s) {
    queue<int> q;
    q.push(s);
    color[s] = 1;
    not_colored.erase(s);

    // vertex count
    int v_count = 1;

    // no. of 1s
    int one_count = 1;
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        for(int adj : adj_list[front]) {
            if(color[adj] == -1) {
                color[adj] = (color[front] + 1) % 2;
                q.push(adj);
                not_colored.erase(adj);

                ++v_count;
                one_count += color[adj];
            } else if(color[adj] == color[front]) {
                return -1;
            }
        }
    }
    return max(1, min(one_count, v_count - one_count));
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
    int t;
    cin>>t;
    map<int, set<int>> adj_map;
    while(t--) {
        int v, e;
        cin>>v>>e;
        adj_map.clear();
        for(int i=0; i<v; ++i) {
            adj_map[i] = set<int>();
        }

        for(int i=0; i<e; ++i) {
            int x, y;
            cin>>x>>y;
            adj_map[x].insert(y);
            adj_map[y].insert(x);
        }

        _vec<int> color(v, -1);
        set<int> not_colored;
        for(int i=0; i<v; ++i) {
            not_colored.insert(i);
        }
        int count = 0;
        while(!not_colored.empty()) {
            int temp = min_guards(adj_map, color, not_colored, *not_colored.begin());
            if(temp == -1) {
                count = -1;
                break;
            } else {
                count += temp;
            }
        }
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