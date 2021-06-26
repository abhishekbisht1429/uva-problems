#include<bits/stdc++.h>

using namespace std;

#define DEBUG

#define _umap unordered_map
#define _uset unordered_set
#define _ll long long
#define _ull unsigned _ll
#define _vec vector
#define _tp tuple
#define _p pair

#define _ignore_lines(n) for(int i=0;i<n;++i) cin.ignore(numeric_limits<streamsize>::max(), '\n')

/* Bit Manipulation */
#define _isSet(n, i) (n & (1L<<i))
#define _set(n, i) n = (n | (1L<<i)) 
#define _reset(n, i) n = (n & (0xfffffffffffffffeL<<i))
#define _flip(n, i) n = (n ^ (1L<<i))

int comp(_vec<int> &v1, _vec<int> &v2) {
    for(int i=0; i<v1.size(); ++i) {
        if(v1[i] < v2[i]) return -1;
        if(v1[i] > v2[i]) return 1;
    }
    return 0;
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
    int ds = 0;
    while(1) {
        int p;
        cin>>p;
        if(p==0) break;

        _vec<int> order(p);
        for(int i=0; i<p; ++i) {
            cin>>order[i];
        }
        int a;
        cin>>a;
        _vec<_p<int, int>> apts(a);
        for(int i=0; i<a; ++i) {
            cin>>apts[i].first>>apts[i].second;
        }

        /* Processing */
        sort(order.begin(), order.end());
        _vec<int> opt_order(order.size()), opt_error(5, INT_MAX);
        _vec<int> temp(5);
        _vec<int> timing(p+1);
        do {
            timing[0] = 0;
            for(int i=1; i<=p; ++i) {
                timing[i] = timing[i-1] + order[i-1];
            }
            temp.assign(5, 0);
            for(auto apt : apts) {
                int priority = apt.first;
                int time = apt.second;
                int error = INT_MAX;
                for(int i=0; i<timing.size(); ++i) {
                    error = min(error, abs(timing[i] - time));
                }
                temp[priority-1] += error;
            }
            if(comp(temp, opt_error) < 0) {
                opt_error.assign(temp.begin(), temp.end());
                opt_order.assign(order.begin(), order.end());
            }
        } while(next_permutation(order.begin(), order.end()));

        /* Output */
        int total_miss = accumulate(opt_error.begin(), opt_error.end(), 0);
        cout<<"Data set "<<++ds<<"\n";
        cout<<"Order:";
        for(int i=0; i<opt_order.size(); ++i) {
            cout<<" "<<opt_order[i];
        }
        cout<<"\n";
        cout<<"Error: "<<total_miss<<"\n";
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