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

int lcs(_vec<int> &correct_order, _vec<int> &stu_order, _vec<_vec<int>> &memo, int i, int j) {
    if(i==correct_order.size() || j==stu_order.size())
        return 0;
    
    if(memo[i][j] == -1) {
        if(correct_order[i] == stu_order[j])
            memo[i][j] = 1 + lcs(correct_order, stu_order, memo, i+1, j+1);
        else
            memo[i][j] = max(lcs(correct_order, stu_order, memo, i, j+1),
                              lcs(correct_order, stu_order, memo, i+1, j));
    }

    return memo[i][j];
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
    int n;
    _vec<int> correct_order;
    _vec<int> stu_order;
    while(1) {
        string inp;
        getline(cin, inp);
        if(cin.fail()) break;

        if(inp.size()<3) {
            n = stoi(inp);
            correct_order.resize(n);
            for(int i=0; i<n; ++i) {
                int rank;
                cin>>rank;
                correct_order[rank-1] = i;
            }
            _ignore_lines(1);
        } else {
            stu_order.resize(n);
            istringstream iss(inp);
            for(int i=0; i<n; ++i) {
                int rank;
                iss>>rank;
                stu_order[rank-1] = i;
            }
            
            /* lcs on stu_order and correct_order */
            _vec<_vec<int>> memo(n, _vec<int>(n, -1));
            cout<<lcs(correct_order, stu_order, memo, 0, 0)<<"\n";
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