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
#define _reset(n, i) n = (n & ((-1u<<1)<<(i)))
#define _flip(n, i) n = (n ^ (1u<<(i)))
#define _rset(n, i, cnt) n = n | (((1u<<(cnt))-1)<<i)
#define _rreset(n, i, cnt) n = n & ~(((1u<<(cnt))-1)<<i)
#define _ffzi(n, i) __builtin_ffs(~(((1u<<i+1)-1) | n))

#define _isSetl(n, i) ((n) & (1ull<<(i)))
#define _setl(n, i) n = ((n) | (1ull<<(i))) 
#define _resetl(n, i) n = ((n) & ((-1ull<<1)<<(i)))
#define _flipl(n, i) n = ((n) ^ (1ull<<(i)))
#define _rsetl(n, i, cnt) n = n | (((1ull<<(cnt))-1)<<i)
#define _rresetl(n, i, cnt) n = n & ~(((1ull<<(cnt))-1)<<i)
#define _ffzil(n, i) __builtin_ffs(~(((1ull<<i+1)-1) | n))

struct node {
    int time;
    int duration;
    string target;
};

string findTarget(_umap<string, _vec<node>> &fwd_map, _uset<string> &fwd_hist, int time, string ext) {
    if(fwd_hist.find(ext) != fwd_hist.end()) 
        return "9999";

    fwd_hist.insert(ext);

    for(auto fwd_det : fwd_map[ext]) {
        if(time >= fwd_det.time && time <= fwd_det.time + fwd_det.duration) {
            return findTarget(fwd_map, fwd_hist, time, fwd_det.target);
        }
    }
    return ext;
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
    int tc;
    cin>>tc;
    _ignore_lines(1);
    cout<<"CALL FORWARDING OUTPUT\n";
    for(int t=0; t<tc; ++t) {
        _umap<string, _vec<node>> fwd_map;
        while(1) {
            string inp;
            getline(cin, inp);
            if(inp == "0000") break;

            istringstream iss(inp);
            string src;
            node fwd_det;
            iss>>src;
            iss>>fwd_det.time>>fwd_det.duration>>fwd_det.target;
            if(fwd_map.find(src) == fwd_map.end())
                fwd_map[src] = _vec<node>();
            fwd_map[src].push_back(fwd_det);
        }
        cout<<"SYSTEM "<<(t+1)<<"\n";
        while(1) {
            string inp;
            getline(cin, inp);
            if(inp == "9000") break;

            istringstream iss(inp);
            string time, ext;
            iss>>time>>ext;

            _uset<string> temp;
            cout<<"AT "<<time<<" CALL TO "<<ext<<" RINGS ";
            cout<<findTarget(fwd_map, temp, stoi(time), ext)<<"\n";
        }
    }
    cout<<"END OF OUTPUT\n";

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