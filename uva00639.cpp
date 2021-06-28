#include<bits/stdc++.h>

using namespace std;

#define DEBUG

#define _umap unordered_map
#define _uset unordered_set
#define _ll long long
#define _ull unsigned _ll
#define _vec vector
#define _tp tuple
#define _p pair

#define _ignore_lines(n) for(int i=0;i<n;++i) cin.ignore(numeric_limits<streamsize>::max(), '\n')

/* Bit Manipulation */
#define _isSet(n, i) (n & (1L<<i))
#define _set(n, i) n = (n | (1L<<i)) 
#define _reset(n, i) n = (n & (0xfffffffffffffffeL<<i))
#define _flip(n, i) n = (n ^ (1L<<i))

int findMaxRooks(_vec<string> grid, int i = 0, int j = 0) {
    if(i == grid.size()) {
        return 0;
    }
    int next_i = i + (j+1 == grid.size());
    int next_j = (j+1) % grid.size();

    int rooks = findMaxRooks(grid, next_i, next_j);
    if(grid[i][j] != 'X') {
        for(int temp = i; temp < grid.size() && grid[temp][j]!='X'; ++temp) grid[temp][j] = 'X';
        for(int temp = j+1; temp < grid.size() && grid[i][temp]!='X'; ++temp) grid[i][temp] = 'X';

        return max(rooks, 1 + findMaxRooks(grid, next_i, next_j));
    }
    return rooks;
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
        int n;
        cin>>n;
        if(n==0) break;

        _vec<string> grid(n);
        for(int i=0; i<n; ++i) {
            cin>>grid[i];
        }

        cout<<findMaxRooks(grid)<<"\n";

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