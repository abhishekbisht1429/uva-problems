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
    int c;
    cin>>c;
    while(c--) {
        int n;
        cin>>n;

        int min_area = INT_MAX;

        /* Commented out solution is my first attempt. It is also correct but 
           the solution below is more efficient */
        // for(int l=1; l<=n; ++l) {
        //     for(int b=l;b<=n; ++b) {
        //         if(n % (l*b) == 0) {
        //             int h = n / (l*b);
        //             min_area = min(min_area, 2*(l*b + b*h + h*l));
        //         }
        //     }
        // }

        for(int l=1; l<=n; ++l) {
            for(int b=l;l*b<=n; ++b) {
                if(n % (l*b) == 0) {
                    int h = n / (l*b);
                    min_area = min(min_area, 2*(l*b + b*h + h*l));
                }
            }
        }
        cout<<min_area<<"\n";
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