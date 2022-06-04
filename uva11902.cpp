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

//_vec<_vec<int>> adj_mat;
//_vec<bool> initially_reachable;
//
//_vec<bool> visited;
void dfs(_vec<_vec<int>> &adj_mat, _vec<bool> &reachable, _vec<bool> &visited, int s=0) {
    visited[s] = true;
    reachable[s] = true;
    for(int i=0; i<adj_mat.size(); ++i) {
        if(adj_mat[s][i] && !visited[i])
            dfs(adj_mat, reachable, visited, i);
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
    int tc;
    cin>>tc;

    for(int case_n=1; case_n <= tc; ++case_n) {
        cout<<"Case "<<case_n<<":\n";
        int n;
        cin>>n;
        _vec<_vec<int>> adj_mat(n, _vec<int>(n));
        _vec<bool> initially_reachable(n);
        _vec<bool> visited(n);
        _vec<_vec<bool>> dominates(n, _vec<bool>(n));

        // intialize global variables
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                cin>>adj_mat[i][j];
                dominates[i][j] = false;
                visited[j] = false;
                initially_reachable[j] = false;
            }
        }

        /*
         * calculate initially_reachable vector
         */
        dfs(adj_mat, initially_reachable, visited);
        for(int i=0; i<n; ++i)
            if(initially_reachable[i])
                dominates[i][i] = true;


        _vec<bool> reachable(n);
        for(int i=0; i<n; ++i) {
            _vec<int> temp = adj_mat[i];
            for(int j=0; j<n; ++j) {
                adj_mat[i][j] = 0; //disable outgoing edges
                visited[j] = false;
                reachable[j] = false;
            }
            dfs(adj_mat, reachable, visited);
            adj_mat[i] = temp;

            for(int j=0; j<n; ++j) {
                if(initially_reachable[j] && !reachable[j])
                    dominates[i][j] = true;
            }
        }

        /*
         * Print the output
         */
        cout<<"+";
        for(int j=0; j<2*n-1; ++j)
            cout<<"-";
        cout<<"+\n";
        for(int i=0; i<n; ++i) {
            cout<<"|";
            for(int j=0; j<n; ++j)
                cout<<(dominates[i][j]?'Y':'N')<<'|';
            cout<<"\n";
            cout<<"+";
            for(int j=0; j<2*n-1; ++j)
                cout<<"-";
            cout<<"+\n";
        }

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