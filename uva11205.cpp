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
    int t;
    cin>>t;
    while(t--) {
        int p, n;
        cin>>p>>n;
        _vec<int> codes;
        for(int i=0; i<n; ++i) {
            string temp = "";
            for(int j=0; j<p; ++j) {
                char c;
                cin>>c;
                cin.ignore();
                temp += c;
            }
            codes.push_back(stoi(temp, nullptr, 2));
        }

        /* Processing */
        _uset<int> uset;
        int min_led = INT_MAX;
        for(int led_comb = 0; led_comb<(1<<p); ++led_comb) {
            if(__builtin_popcount(led_comb) > p) continue;

            uset.clear();
            bool valid = true;
            for(int code : codes) {
                int new_code = code & led_comb;
                if(uset.find(new_code) != uset.end()) {
                    valid = false;
                    break;
                }
                uset.insert(new_code);
            }

            if(valid) {
                min_led = min(min_led, __builtin_popcount(led_comb));
            }
        }

        /* Output */
        cout<<min_led<<"\n";
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