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

void print_vec(_vec<int> &vec) {
    for(int i=0; i<vec.size(); ++i) {
        if(i) cout<<" ";
        cout<<vec[i];
    }
    cout<<"\n";
}
void find_all(_vec<_vec<int>> &combs, _vec<int> &inp, _vec<int> &temp, int pos, int st) {
    if(pos > temp.size()-1) {
        combs.push_back(temp);
        return;
    }
    for(int i=st; i<inp.size(); ++i) {
        temp[pos] = inp[i];
        find_all(combs, inp, temp, pos+1, i+1);
    }
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
    int t=0;
    while(1) {
        int k;
        cin>>k;
        if(k==0) break;

        if(t) cout<<"\n";

        _vec<int> inp(k);
        for(int i=0; i<k; ++i) {
            cin>>inp[i];
        }
        _vec<_vec<int>> combs;
        _vec<int> temp(6);

        find_all(combs, inp, temp, 0, 0);

        sort(combs.begin(), combs.end());

        for(auto perm : combs) {
            print_vec(perm);
        }
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