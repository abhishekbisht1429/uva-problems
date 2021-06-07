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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef DEBUG
    ifstream in("input.txt");
    ofstream out("output.txt");
    streambuf* in_backup = cin.rdbuf();
    streambuf* out_backup = cout.rdbuf();
    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf()); 
    #endif

    /* ######################CODE_START################################ */
    while(1) {
        int k;
        cin>>k;

        if(cin.fail()) break;

        vec<pair<int, int>> res;
        for(int x = k+1; x<=2*k; ++x) {
            if((k*x) % (x-k) == 0) {
                res.push_back({(k*x)/(x-k), x});
            }
        }
        cout<<res.size()<<"\n";
        for(int i=0;i<res.size();++i) {
            cout<<"1/"<<k<<" = "<<"1/"<<res[i].first<<" + "<<"1/"<<res[i].second<<"\n";
        }
    }
    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}