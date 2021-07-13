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

_vec<bitset<1001>> visited(1001);
_vec<int> trace, res;
int min_trace_size;
int ca, cb, n;

void init_tc() {
    for(int i=0; i<n; ++i) {
        visited[i].reset();
    }
    trace.clear();
    res.clear();
    min_trace_size = INT_MAX;
}

void findSol(int a=0, int b=0, int step=0) {
    if(visited[a][b])
        return;
    visited[a][b] = 1;
    trace.push_back(step);
    if(b == n) {
        if(trace.size() < min_trace_size) {
            res.assign(trace.begin(), trace.end());
            min_trace_size = trace.size();
        }
    } else {
        findSol(ca, b, 1);
        findSol(a, cb, 2);
        findSol(0, b, 3);
        findSol(a, 0, 4);
        findSol(max(0, a+b-cb), min(cb, a+b), 5);
        findSol(min(ca, a+b), max(0, a+b-ca), 6);
    }

    visited[a][b] = 0;
    trace.pop_back();
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
    while(1) {
        cin>>ca>>cb>>n;
        if(cin.fail()) break;

        /* init globals */
        init_tc();

        findSol();

        for(int i : res) {
            switch(i) {
                case 1:
                    cout<<"fill A\n";
                    break;
                case 2:
                    cout<<"fill B\n";
                    break;
                case 3:
                    cout<<"empty A\n";
                    break;
                case 4:
                    cout<<"empty B\n";
                    break;
                case 5:
                    cout<<"pour A B\n";
                    break;
                case 6:
                    cout<<"pour B A\n";
                    break;
                default: break;
            }
        }
        cout<<"success\n";
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