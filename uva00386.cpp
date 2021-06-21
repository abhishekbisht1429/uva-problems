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

#define MAX_CUBE 8000000
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
    _vec<tuple<int, int, int, int>> tp;
    bool stop = false;
    for(int b=2; ; ++b) {
        int b_cube = pow(b, 3);
        if(b_cube > MAX_CUBE) break;

        for(int c=b+1; ; ++c) {
            int c_cube = pow(c, 3);
            if(b_cube + c_cube > MAX_CUBE) break;

            for(int d=c+1; ; ++d) {
                int cube = b_cube + c_cube + pow(d, 3);
                if(cube > MAX_CUBE) break;

                double a = cbrt(cube);
                if(abs(a - round(a)) < 1e-8) 
                    tp.push_back(make_tuple(round(a), b, c, d));
            }
        }
    }
    sort(tp.begin(), tp.end());
    for(auto t : tp) {
        cout<<"Cube = "<<get<0>(t)<<", Triple = ("<<get<1>(t)<<","<<get<2>(t)<<","<<get<3>(t)<<")\n";
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