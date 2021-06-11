#include<bits/stdc++.h>

using namespace std;

#define DEBUG

#define umap unordered_map
#define uset unordered_set
#define ll long long
#define ull unsigned ll
#define vec vector

#define max3(a, b, c) max(a, max(b, c))
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define min3(a, b, c) min(a, min(b, c))
#define min4(a, b, c, d) min(min(a, b), min(c, d))
#define ignore_lines(n) for(int i=0;i<n;++i) cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define isSet(n, i) (0x0000000000000001L<<i) & n
#define set(n, i) n = (0x0000000000000001L<<i) | n

bool isValid(ll n) {
    ull used = 0;
    while(n>0) {
        if(isSet(used, n%10)) {
            return false;
        }
        set(used, n%10);
        n/=10;
    }
    return true;
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
        ll n;
        cin>>n;

        ll s1, s2;
        for(s2=1; s2<=(9876543210l)/n; ++s2) {
            s1 = n*s2;
            if(isValid(s1) && isValid(s2)) {
                cout<<s1<<" / "<<s2<<" = "<<n<<"\n";
            }
        }
        if(t) cout<<"\n";
    }
    
    /* #######################CODE_END############################### */
    #ifdef DEBUG
    auto _end = chrono::high_resolution_clock::now();
    auto _duration = chrono::duration_cast<chrono::nanoseconds>(_end - _start);
    ll _ns = _duration.count();
    double _s = _ns / 10e9;
    cout<<"\nDuration: "<<_s<<" sec\n";
    cin.rdbuf(_in_backup);
    cout.rdbuf(_out_backup);
    #endif
    return 0;
}