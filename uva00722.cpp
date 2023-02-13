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

_vec<int> dir_i = {1, 0, -1, 0};
_vec<int> dir_j = {0, 1, 0, -1};

int find_area(_vec<string> &grid, int x, int y) {
    queue<_ii> q;

    //assuming that (x,y) will always be valid
    q.emplace(x, y);
    int area = 0;
    while(!q.empty()) {
        int i, j;
        tie(i, j) = q.front();
        q.pop();

        if((i < 0 || i >= grid.size()) || (!grid.empty() && (j < 0 || j>=grid[0].size())))
            continue;
        if(grid[i][j] != '0')
            continue;

        ++area;
        grid[i][j] = 'v'; //visited

        for (int k = 0; k < 4; ++k) {
            int ni = i + dir_i[k];
            int nj = j + dir_j[k];
            q.emplace(ni, nj);
        }

    }

    return area;
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
    int m;
    cin>>m;
    while(m--) {
        int x, y;
        cin>>x>>y;
        --x; --y;
        _ignore_lines(1);
        _vec<string> grid;

        string s;
        while(1) {
            getline(cin, s);
            if(!cin || s.empty())
                break;
            grid.push_back(s);
//            cout << s<<"\n";
        }

        cout<<find_area(grid, x, y)<<"\n";
        if(m>0)
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