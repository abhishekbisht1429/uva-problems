//
// Created by abhishek on 12/6/23.
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

void find_scc(vector<vector<char>>& res,
              stack<int>& s,
              vector<bool>& in_stack,
              vector<vector<int>>& adj_list,
              vector<int>& lrp,
              vector<int>& pos,
              vector<char>& options,
              int& count,
              int u) {
    lrp[u] = pos[u] = count++;
    s.push(u);
    in_stack[u] = true;
    for(int v : adj_list[u]) {
        if(pos[v] == -1) {
            find_scc(res, s, in_stack, adj_list, lrp, pos, options, count, v);
        }
        if(in_stack[v])
            lrp[u] = min(lrp[u], lrp[v]);
    }

    if(lrp[u] == pos[u]) {
        vector<char> scc;
        while(1) {
            int x = s.top();
            s.pop();
            in_stack[x] = false;
            scc.push_back(options[x]);
            if(x == u)
                break;
        }
        sort(scc.begin(), scc.end());
        res.push_back(scc);
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
        int n;
        cin>>n;
        if(n == 0)
            break;
        vector<vector<int>> adj_list;
        vector<char> options;
        unordered_map<char, int> indices;
        int index = 0;
        for(int i=0; i<n; ++i) {
            vector<char> vec;
            for(int j=0; j<6; ++j) {
                char c;
                cin >> c;
                if (indices.find(c) == indices.end()) {
                    indices[c] = index++;
                    options.push_back(c);
                    adj_list.push_back(vector<int>());
                }
                vec.push_back(c);
            }
            char c = vec[vec.size()-1];
            for(int j=0; j<5; ++j) {
                if(c == vec[j])
                    continue;
                adj_list[indices[c]].push_back(indices[vec[j]]);
            }
        }

        vector<vector<char>> res;
        vector<int> lrp(adj_list.size(), -1);
        vector<int> pos(adj_list.size(), -1);
        stack<int> s;
        vector<bool> in_stack(adj_list.size(), -1);
        for(int i=0; i<adj_list.size(); ++i) {
            int count = 0;
            if(pos[i] == -1) {
                find_scc(res, s, in_stack, adj_list, lrp, pos, options, count, i);
            }
        }

        sort(res.begin(), res.end());

        if(tc != 0)
            cout<<"\n";
        for(int i=0; i<res.size(); ++i) {
            for(int j=0; j<res[i].size(); ++j) {
                if(j!=0)
                    cout<<" ";
                cout<<res[i][j];
            }
            cout<<"\n";
        }
        ++tc;
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