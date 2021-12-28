//
// Created by reckoner1429 on 28/12/21.
//
#include <bits/stdc++.h>

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
    int p;
    cin>>p;
    while(p--) {
        int s;
        cin>>s;
        _vec<_vec<int>> board(s, _vec<int>(s, 1));
        int n;
        cin>>n;
        for(int i=0; i<n; ++i) {
            int r1, c1, r2, c2;
            cin>>r1>>c1>>r2>>c2;
            --r1; --c1; --r2; --c2;
            for(int i=r1; i<=r2; ++i)
                for(int j=c1; j<=c2; ++j)
                    board[i][j] = 0;
        }

        /* calculate histograms */
        for(int i=0; i<s; ++i) {
            for(int j=0; j<s; ++j) {
                if(i>0 && board[i][j] == 1)
                    board[i][j] += board[i-1][j];
            }
        }

        /* calculate max area */
        int max_area = 0;
        for(int i=0; i<s; ++i) {
            stack<int> st;
            for(int j=0; j<s; ++j) {
                while(!st.empty() && board[i][st.top()] >= board[i][j]) {
                    int height = board[i][st.top()];
                    st.pop();
                    int width = j - ((!st.empty())?st.top():-1) - 1;

                    max_area = max(max_area, height * width);
                }
                st.push(j);
            }

            while(!st.empty()) {
                int height = board[i][st.top()];
                st.pop();
                int width = s - ((!st.empty())?st.top():-1) - 1;

                max_area = max(max_area, height * width);
            }
        }

        cout<<max_area<<"\n";
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
