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

int grid_sum(int (*grid)[1025], int i_st, int i_end, int j_st, int j_end) {
    int sum = 0;
    for(int i=i_st; i<=i_end; ++i) {
        for(int j=j_st; j<=j_end; ++j)  {
            sum += grid[i][j];
        }
    }
    return sum;
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
    int killed[1025][1025];
    int t;
    cin>>t;
    while(t--) {
        /*reset the grid for new test case*/
        for(int i=0; i<1025; ++i) {
            for(int j=0; j<1025; ++j) {
                killed[i][j] = 0;
            }
        }

        int d,n;
        cin>>d>>n;
        while(n--) {
            int x, y, size;
            cin>>x>>y>>size;
            for(int i=x-d; i<=x+d; ++i) {
                if(i<0 || i>1024) continue;
                
                for(int j=y-d; j<=y+d; ++j) {
                    if(j<0 || j>1024) continue;

                    killed[i][j] += size;
                }
            }
        }

        int x, y, size=-1;
        for(int i=0; i<1025; ++i) {
            for(int j=0; j<1025; ++j) {
                if(killed[i][j] > size) {
                    size = killed[i][j];
                    x = i;
                    y = j;
                }
            }
        }

        cout<<x<<" "<<y<<" "<<size<<"\n";

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