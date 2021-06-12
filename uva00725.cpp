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

bool isValid(int s1, int s2) {
    _ull used = 0L;
    if(s1<10000 && s2<10000) {
        return false;
    } else if(s1<10000 || s2<10000) {
        _set(used, 0);
    }
    while(s1>0) {
        int digit = s1%10;
        if(_isSet(used, digit)) {
            return false;
        }
        _set(used, digit);
        s1/=10;
    }
    while(s2>0) {
        int digit = s2%10;
        if(_isSet(used, digit)) {
            return false;
        }
        _set(used, digit);
        s2/=10;
    }
    return true;
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
    int count = 0;
    while(1) {
        int n;
        cin>>n;

        if(n==0) break;

        if(count) cout<<"\n";
        bool found = false;
        for(int s2 = 1234; n*s2<=98765; ++s2) {
            int s1 = n*s2;
            if(isValid(s1, s2)) {
                cout<<setfill('0')<<setw(5)<<s1;
                cout<<" / ";
                cout<<setfill('0')<<setw(5)<<s2;
                cout<<" = "<<n<<"\n";
                found = true;
            }
        }
        if(!found) {
            cout<<"There are no solutions for "<<n<<".\n";
        }
        count++;
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