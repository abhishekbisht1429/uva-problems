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

void findPi(_vec<int> &pi, _vec<int> &votes, int majority, _ll included = 0, int sum=0, int i=0) {
    if(i == votes.size()) {
        if(sum < majority) {
            for(int j=0; j<votes.size(); ++j) {
                if(!_isSet(included, j) && (votes[j] + sum) >= majority) pi[j]++;
            }
        }
        return;
    }
    findPi(pi, votes, majority, included, sum, i+1);
    _set(included, i);
    findPi(pi, votes, majority, included, sum + votes[i], i+1);
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
    int t;
    cin>>t;
    while(t--) {
        int p;
        cin>>p;
        _vec<int> votes(p);
        for(int i=0; i<p; ++i) {
            cin>>votes[i];
        }

        int majority = (int)ceil(accumulate(votes.begin(), votes.end(), 0)/2.0);
        _vec<int> pi(p);
        findPi(pi, votes, majority);

        for(int i=0; i<p; ++i) {
            cout<<"party "<<i+1<<" has power index "<<pi[i]<<"\n";
        }
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