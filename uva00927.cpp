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

ll calcA(int n, vec<int> coeff) {
    ll res = 0;
    for(int i=0; i<coeff.size(); ++i) {
        res += coeff[i]*pow(n, i);
    }
    return res;
}
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
    int n_cases;
    cin>>n_cases;
    while(n_cases--) {
        int i;
        cin>>i;
        vec<int> coeff(i+1);
        for(int j=0; j<=i; ++j) {
            cin>>coeff[j];
        }
        int d, k;
        cin>>d>>k;

        int n = (int)ceil((sqrt((d+8*k)/d)-1)/2);
        cout<<calcA(n, coeff)<<endl;
    }
    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}