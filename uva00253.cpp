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

void rot_xy(string &str) {
    char temp = str[1];
    str[1] = str[2];
    str[2] = str[4];
    str[4] = str[3];
    str[3] = temp;
}
void rot_yz(string &str) {
    char temp = str[0];
    str[0] = str[2];
    str[2] = str[5];
    str[5] = str[3];
    str[3] = temp;
}
void rot_zx(string &str) {
    char temp = str[0];
    str[0] = str[1];
    str[1] = str[5];
    str[5] = str[4];
    str[4] = temp;
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
        string inp;
        cin>>inp;
        if(cin.fail()) break;
        string s1 = inp.substr(0, 6);
        string s2 = inp.substr(6);

        bool eq = false;
        for(int i=0; i<4; ++i) {
            for(int j=0; j<4; ++j) {
                for(int k=0; k<4; ++k) {
                    rot_xy(s1);
                    if(s1 == s2) {
                        eq = true;
                        break;
                    }
                }
                rot_yz(s1);
            }
            rot_zx(s2);
        }
        if(eq) cout<<"TRUE";
        else cout<<"FALSE";
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