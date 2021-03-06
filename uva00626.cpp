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
    int t=0;
    while(1) {
        int n;
        cin>>n;
        if(cin.fail()) break;

        _vec<_vec<int>> adjMat(n);
        for(int i=0; i<n; ++i) {
            adjMat[i] = _vec<int>(n);
        }
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                cin>>adjMat[i][j];
            }
        }

        /* Processing */
        _vec<tuple<int, int, int>> res;
        int total = 0;
        for(int i=0; i<n; ++i) {
            for(int j=i+1; j<n; ++j) {
                if(!adjMat[i][j] && !adjMat[j][i]) continue;

                for(int k=j+1; k<n; ++k) {
                    if(adjMat[i][j] && adjMat[j][k] && adjMat[k][i]) {
                        res.push_back(make_tuple(i+1, j+1, k+1));
                        total++;
                    }
                    if(adjMat[i][k] && adjMat[k][j] && adjMat[j][i]) {
                        res.push_back(make_tuple(k+1, j+1, i+1));
                        total++;
                    }
                }
            }
        }

        /*Output*/
        sort(res.begin(), res.end());
        for(auto tpl : res) {
            cout<<get<0>(tpl)<<" "<<get<1>(tpl)<<" "<<get<2>(tpl)<<"\n";
        }
        cout<<"total:"<<total<<"\n\n";
        ++t;
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