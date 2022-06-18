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

int dir_i[] = {0, 0, 1, 1, -1, -1, 1, -1};
int dir_j[] = {1, -1, 0, -1, 0, 1, 1, -1};

int find_area(_vec<string> &grid, int si, int sj) {
        queue<_ii> q;
        q.push({si, sj});
        _vec<_vec<bool>> visited(grid.size(), _vec<bool>(grid[0].size()));
        int area = 0;
        while(!q.empty()) {
            _ii front = q.front();
            q.pop();
            if(!visited[front.first][front.second] && grid[front.first][front.second] == 'W') {
                ++area;
                visited[front.first][front.second] = true;
                for (int k = 0; k < 8; ++k) {
                    int x = front.first + dir_i[k];
                    int y = front.second + dir_j[k];
                    if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size())
                        q.push({x, y});
                }
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
    int tc;
    cin>>tc;
    _ignore_lines(2);
    while(tc--) {
        _vec<string> grid;
        string s;
        while(1) {
            getline(cin, s);
            if(s[0] != 'L' && s[0] != 'W') {
                istringstream iss(s);
                int i, j;
                iss>>i;
                iss>>j;
                --i;
                --j;
                cout<<find_area(grid, i, j)<<"\n";
                break;
            }
            grid.push_back(s);
        }

        while(1) {
            string s;
            getline(cin, s);
            if(s.size() == 0)
                break;
            istringstream iss(s);
            int i, j;
            iss>>i;
            iss>>j;
            --i;
            --j;
            cout<<find_area(grid, i, j)<<"\n";
        }
        if(tc)
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