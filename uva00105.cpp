#include<bits/stdc++.h>

using namespace std;

#define DEBUG

#define umap unordered_map
#define uset unordered_set
#define ll long long
#define vec vector

#define max3(a, b, c) max(a, max(b, c))
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define min3(a, b, c) min(a, min(b, c))
#define min4(a, b, c, d) min(min(a, b), min(c, d))
#define ignore_lines(n) for(int i=0;i<n;++i) cin.ignore(numeric_limits<streamsize>::max(), '\n')

#define INP_SIZE 5001
#define SKL_SIZE 10001
struct buld {
    int l, r, h;
};
buld inp[INP_SIZE];
int skyline[SKL_SIZE];

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
    int len = 0;
    while(1) {
        cin>>inp[len].l>>inp[len].h>>inp[len].r;
        if(cin.fail()) break;
        len++;
    }
    for(int i=0; i<SKL_SIZE; ++i) {
        int max_h = 0;
        for(int j=0; j<len; ++j) {
            if(i >= inp[j].l && i<= inp[j].r) {
                max_h = max(max_h, inp[j].h);
            }
        }
        skyline[i] = max_h;
    }
    vec<int> res;
    for(int i=1; i<SKL_SIZE; ++i) {
        if(skyline[i] > skyline[i-1]) {
            res.push_back(i);
            res.push_back(skyline[i]);
        } else if(skyline[i] < skyline[i-1]) {
            res.push_back(i-1);
            res.push_back(skyline[i]);
        }
    }

    for(int i=0; i<res.size(); ++i) {
        cout<<res[i];
        if(i!=res.size()-1) {
            cout<<" ";
        }
    }
    cout<<"\n";

    
    /* #######################CODE_END############################### */
    #ifdef DEBUG
    auto _end = chrono::high_resolution_clock::now();
    auto _duration = chrono::duration_cast<chrono::nanoseconds>(_end - _start);
    ll _ns = _duration.count();
    double _s = _ns / 10e9;
    cout<<"Duration: "<<_s<<" sec\n";
    cin.rdbuf(_in_backup);
    cout.rdbuf(_out_backup);
    #endif
    return 0;
}