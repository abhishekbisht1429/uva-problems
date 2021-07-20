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


_umap<int, int> valid_combs_map = {{0b1111110, 0},
                                   {0b0110000, 1},
                                   {0b1101101, 2},
                                   {0b1111001, 3},
                                   {0b0110011, 4},
                                   {0b1011011, 5},
                                   {0b1011111, 6},
                                   {0b1110000, 7},
                                   {0b1111111, 8},
                                   {0b1111011, 9}};

_vec<_uset<int>> possible_valid_combs;
_vec<int> combs;
int n;
void init_tc() {
    possible_valid_combs.resize(n);
    for(auto &uset : possible_valid_combs) uset.clear();

    combs.clear();
    combs.resize(n);
}

bool burnout_possible(int i, int j) {
    for(++i; i<n; ++i) {
        if(_isSet(combs[i], j))
            return false;
    }
    return true;
}
void genValidCombs(_uset<int> &valid, int comb, int i, int j=0) {
    if(j==8) {
        if(valid_combs_map.find(comb) != valid_combs_map.end()) {
            valid.insert(valid_combs_map[comb]);
        }
        return;
    }
    if(!_isSet(comb, j) && burnout_possible(i, j)) {
        _set(comb, j);
        genValidCombs(valid, comb, i, j+1);
        _reset(comb, j);
    }
    genValidCombs(valid, comb, i, j+1);
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
        cin>>n;
        if(n==0) break;
        init_tc();

        for(int i=0; i<n; ++i) {
            string str;
            cin>>str;
            for(int j=0; j<str.size(); ++j) {
                if(str[j]=='Y') {
                    _set(combs[i], 6-j);
                }
            }
        }
        for(int i=0; i<n; ++i)
            genValidCombs(possible_valid_combs[i], combs[i], i);
        
        bool match = false;
        for(int comb : possible_valid_combs[0]) {
            bool count_down_present = true;
            for(int j=1; j<n; ++j) {
                --comb;
                if(possible_valid_combs[j].find(comb) == possible_valid_combs[j].end()) {
                    count_down_present = false;
                    break;
                }
            }
            if(count_down_present) {
                match = true;
                break;
            }
        }
        if(match)
            cout<<"MATCH\n";
        else
            cout<<"MISMATCH\n";
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