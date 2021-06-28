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

_p<_vec<int>, int> findBestComb(const _vec<int> &customer, const _vec<_p<_uset<int>, int>> &common, _vec<int> &selected, int pos = 0, int st = 0) {
    if(pos == selected.size()) {
        int total = 0;
        for(int t : selected) {
            total += customer[t];
        }

        for(auto p : common) {
            int count = 0;
            for(int t : selected) {
                if(p.first.find(t) != p.first.end()) count++;
            }
            total -= max(0, count-1)*p.second;
        }

        return {selected, total};
    }

    int remaining_pos = selected.size() - pos - 1;
    _p<_vec<int>, int> opt_selection = {vector<int>(selected.size()), INT_MIN};
    for(int i = st; i + remaining_pos < customer.size(); ++i) {
        selected[pos] = i;
        auto selection = findBestComb(customer, common, selected, pos+1, i+1);
        if(selection.second > opt_selection.second) {
            opt_selection.first.assign(selection.first.begin(), selection.first.end());
            opt_selection.second = selection.second;
        }
    }
    return opt_selection;
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
    int case_n = 0;
    while(1) {
        int n, x;
        cin>>n>>x;
        if(n==0 && x==0) break;

        _vec<int> customer(n);
        for(int i=0; i<n; ++i) {
            cin>>customer[i];
        }
        int m;
        cin>>m;
        _vec<_p<_uset<int>, int>> common(m);
        for(int i=0; i<m; ++i) {
            int t;
            cin>>t;
            while(t--) {
                int temp;
                cin>>temp;
                common[i].first.insert(temp-1);
            }
            cin>>common[i].second;
        }

        _vec<int> temp(x);
        _p<_vec<int>, int> selection = findBestComb(customer, common, temp);

        cout<<"Case Number  "<<(++case_n)<<"\n";
        cout<<"Number of Customers: "<<selection.second<<"\n";
        cout<<"Locations recommended:";
        for(int i : selection.first) {
            cout<<" "<<i+1;
        }
        cout<<"\n\n";
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