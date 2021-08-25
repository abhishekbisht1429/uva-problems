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

#define MAX_N 1200

int dp[MAX_N][20][200];
_vec<int> primes;
bitset<MAX_N> isPrime;
void sieve() {
    isPrime.set();
    isPrime[0] = 0;
    isPrime[1] = 0;
    for(int i=2; i*i<MAX_N; ++i)
        if(isPrime[i])
            for(int j=i*i; j<MAX_N; j+=i)
                isPrime[j] = 0;
    
    for(int i=0; i<MAX_N; ++i)
        if(isPrime[i])
            primes.push_back(i);
}

int nWays(int remN, int remK, int i=0) {
    if(i == primes.size() || remN < 0)
        return 0;
    if(remN == 0 && remK == 0)
        return 1;
    else if(remN == 0 || remK == 0)
        return 0;
    
    if(dp[remN][remK][i] == -1) {
        dp[remN][remK][i] = nWays(remN, remK, i+1) + 
                            nWays(remN - primes[i], remK - 1, i+1);
    }

    return dp[remN][remK][i];
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
    sieve();
    while(1) {
        int n, k;
        cin>>n>>k;
        if(n==0 && k==0) break;
        for(int i=0; i<=n; ++i)
            for(int j=0; j<=k; ++j)
                for(int l=0; l<primes.size(); ++l)
                    dp[i][j][l] = -1;
        
        cout<<nWays(n, k)<<"\n";
        

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