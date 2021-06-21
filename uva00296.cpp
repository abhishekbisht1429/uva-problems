#include<bits/stdc++.h>

using namespace std;

#define DEBUG

#define _umap unordered_map
#define _uset unordered_set
#define _ll long long
#define _ull unsigned _ll
#define _vec vector

#define _max3(a, b, c) max(a, max(b, c))
#define _max4(a, b, c, d) max(max(a, b), max(c, d))
#define _min3(a, b, c) min(a, min(b, c))
#define _min4(a, b, c, d) min(min(a, b), min(c, d))
#define _ignore_lines(n) for(int i=0;i<n;++i) cin.ignore(numeric_limits<streamsize>::max(), '\n')

/* Bit Manipulation */
#define _isSet(n, i) (n & (1L<<i))
#define _set(n, i) n = (n | (1L<<i)) 
#define _reset(n, i) n = (n & (0xfffffffffffffffeL<<i))
#define _flip(n, i) n = (n ^ (1L<<i))

#define _get_digit(n, i) (n/(int)pow(10, i))%10

pair<int, int> getClue(string &guess, string &code) {
    int c1 = 0;
    for(int i=0; i<4; ++i) {
        c1 += guess[i] == code[i];
    }

    _ull used = 0l;
    int c2 = -c1;
    for(int i=0; i<4; ++i) { //code
        for(int j=0; j<4; ++j) {
            if(!_isSet(used, j) && code[i] == guess[j]) {
                c2++;
                _set(used, j);
                break;
            }
        }
    }
    return {c1, c2};
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
    cin>>n;
    while(n--) {
        int g;
        cin>>g;

        _ignore_lines(1);
        _vec<string> inp(g);
        for(int i=0; i<g; ++i) {
            getline(cin, inp[i]);
        }

        _vec<string> sol;
        for(int i=0; i<=9999; ++i) {
            string code;
            if(i<10) code.append(3, '0');
            else if(i<100) code.append(2, '0');
            else if(i<1000) code.append(1, '0');
            code.append(to_string(i));

            bool match = true;
            for(string &str : inp) {
                string guess = str.substr(0, 4);
                int c1 = str[5] - '0';
                int c2 = str[7] - '0';

                auto p = getClue(guess, code);
                if(c1 != p.first || c2 != p.second) {
                    match = false;
                    break;
                }
            }
            if(match) {
                sol.push_back(code);
                if(sol.size()>1) break;
            }
        }
        int count = sol.size();
        if(count==0) {
            cout<<"impossible\n";
        } else if(count==1) {
            cout<<sol[0]<<"\n";
        } else {
            cout<<"indeterminate\n";
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