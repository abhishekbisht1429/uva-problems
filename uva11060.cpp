//
// Created by abhishek on 23/2/23.
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

_vec<int> find_order(map<int, set<int>> &incoming, map<int, set<int>> &outgoing, _vec<string> &beverages) {
    int n = incoming.size();
    priority_queue<int, _vec<int>, greater<int>> pq;
    /* insert nodes with 0 incoming edges */
    for(int i=0; i<n; ++i) {
        if(incoming[i].empty()) {
            pq.push(i);
            incoming.erase(i);
        }
    }

    /* start bfs */
    _vec<int> order;
    while(!pq.empty()) {
        int front = pq.top();
        pq.pop();
        order.push_back(front);
        /* remove front from the graph */
        for(int adj : outgoing[front]) {
            incoming[adj].erase(front);
            if(incoming[adj].empty()) {
                pq.push(adj);
                incoming.erase(adj);
            }
        }
    }

    return order;
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
    int count = 0;
    _vec<string> beverages;
    _umap<string, int> beverage_pos;
    map<int, set<int>> incoming, outgoing;
    while(1) {
        int n;
        cin>>n;
        if(cin.fail())
            break;
        beverages.clear();
        beverage_pos.clear();
        for(int i=0; i<n; ++i) {
            string beverage;
            cin>>beverage;
            beverages.push_back(beverage);
            beverage_pos[beverage] = i;
        }

        int m;
        cin>>m;
        incoming.clear();
        outgoing.clear();
        for(int i=0; i<n; ++i) {
            incoming[i] = set<int>();
            outgoing[i] = set<int>();
        }
        for(int i=0; i<m; ++i) {
            string b1, b2;
            cin>>b1>>b2;
            int b1_pos = beverage_pos[b1];
            int b2_pos = beverage_pos[b2];
            outgoing[b1_pos].insert(b2_pos);
            incoming[b2_pos].insert(b1_pos);
        }

        _vec<int> order = find_order(incoming, outgoing, beverages);

        cout<<"Case #"<<(++count)<<": Dilbert should drink beverages in this order: ";

        for(int i=0; i<n; ++i) {
            if(i!=0) {
                cout<<" ";
            }
            cout<<beverages[order[i]];
            if(i == n-1){
                cout<<".";
            }
        }
        cout<<"\n\n";
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