#include<bits/stdc++.h>

using namespace std;

#define DEBUG

#define _umap unordered_map
#define _uset unordered_set
#define _ll long long
#define _ull unsigned _ll
#define _vec vector

#define _ignore_lines(n) for(int i=0;i<n;++i) cin.ignore(numeric_limits<streamsize>::max(), '\n')

/* Bit Manipulation */
#define _isSet(n, i) (n & (1L<<i))
#define _set(n, i) n = (n | (1L<<i)) 
#define _reset(n, i) n = (n & (0xfffffffffffffffeL<<i))
#define _flip(n, i) n = (n ^ (1L<<i))

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
        _ull n;
        cin>>n;
        if(cin.fail()) break;

        _ull s2=0, r2=0, s3=0, r3=0, s4=0, r4=0;
        /* Commented out solution below was my first attempt. It is correct but it can be made better */
        // for(_ull i=0; i<n; ++i) {
        //     for(_ll j=0; j<n; ++j) {
        //         /* 2d */
        //         _ull temp1 = min(n-i, n-j);
        //         s2 += temp1;
        //         r2 += (n-i)*(n-j) - temp1;

        //         /*3d*/
        //         _ull temp2 = n*(n+1)/2 - (n-temp1)*(n-temp1+1)/2;
        //         s3 += temp2;
        //         r3 += (n-i)*(n-j)*n*(n+1)/2 - temp2;

        //         /*4d*/
        //         for(_ull k=0; k<n; ++k) {
        //             _ull temp3 = min({n-i, n-j, n-k});
        //             _ull temp4 = n*(n+1)/2 - (n-temp3)*(n-temp3+1)/2;
        //             s4 += temp4;
        //             r4 += (n-i)*(n-j)*(n-k)*n*(n+1)/2 - temp4;
        //         }
        //     }
        // }

        _ull temp = n*(n+1)/2;
        s2 = temp*(2*n+1)/3;
        s3 = pow(temp,2);
        s4 = pow(n, 5)/5 + pow(n, 4)/2 + pow(n,3)/3 - n/30;
        r2 = s3 - s2;
        r3 = pow(temp, 3) - s3;
        r4 = pow(temp, 4) - s4;
        cout<<s2<<" "<<r2<<" "<<s3<<" "<<r3<<" "<<s4<<" "<<r4<<"\n";
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