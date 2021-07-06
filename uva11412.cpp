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
    string colors = "BGORVY";
    int t;
    cin>>t;
    while(t--) {
        bool possible;
        _vec<string> guess(2);
        _vec<int> n1(2);
        _vec<int> n2(2);
        for(int i=0; i<2; ++i) {
            cin>>guess[i]>>n1[i]>>n2[i];
        }

        /* Processing */
        for(int i=0; i<(1<<6); ++i) {
            if(__builtin_popcount(i) != 4) continue;
            
            string holes;
            for(int j=0; j<6; ++j)
                if(_isSet(i, j)) holes.push_back(colors[j]);

            do {
                bitset<2> temp_bs;

                for(int x=0; x<2; ++x) {
                    int temp1=0, temp2=0;
                    for(int j=0; j<4; ++j) {
                        if(holes[j] == guess[x][j]) temp1++;
                        if(holes.find(guess[x][j]) != string::npos) temp2++;
                    }
                    temp2 -= temp1;
                    if(temp1==n1[x] && temp2==n2[x]) temp_bs.set(x);
                }
                possible = temp_bs[0] && temp_bs[1];
                if(possible) break;
            } while(next_permutation(holes.begin(), holes.end()));
            if(possible) break;
        }

        /* Output */
        if(possible) cout<<"Possible\n";
        else cout<<"Cheat\n";
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