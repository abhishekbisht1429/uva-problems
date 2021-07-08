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

int backtrack(_vec<int> &earning, int s, int d, int sum = 0, int i=0) {
    if(i==12) {
        return accumulate(earning.begin(), earning.end(), 0);
    }

    int s1 = -1, s2 = -1;
    if(i < 4) {
        earning[i] = s;
        s1 = backtrack(earning, s, d, sum+s, i+1);
        earning[i] = -d;
        s2 = backtrack(earning, s, d, sum-d, i+1);
    } else {
        int sum1 = sum + s - ((i-5>=0)?earning[i-5]:0);
        if(sum1 < 0) {
            earning[i] = s;
            s1 = backtrack(earning, s, d, sum1, i+1);
        }

        int sum2 = sum - d - ((i-5>=0)?earning[i-5]:0);
        if(sum2 < 0) {
            earning[i] = -d;
            s2 = backtrack(earning, s, d, sum2, i+1);
        }
    }
    return max(s1, s2);
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
        int s, d;
        cin>>s>>d;
        if(cin.fail()) break;

        _vec<int> temp(12);
        int surp = backtrack(temp, s, d);
        if(surp>=0) {
            cout<<surp<<"\n";
        } else {
            cout<<"Deficit\n";
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