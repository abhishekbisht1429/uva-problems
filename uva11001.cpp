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
        double v, v0;
        cin>>v>>v0;

        if(v==0 && v0 == 0) break;

        int max_n = 0;
        double max_l = -1;
        for(int n=1; n<(v/v0); ++n) {
            double l = 0.3*n*sqrt((v/n) - v0);
            l = (round(l*1000000));
            //cout<<setprecision(20)<<l<<" "<<n<<" "<<max_l<<"\n";
            if(l > max_l) {
                max_n = n;
                max_l = l;
            } else if(l == max_l) {
                max_n = 0;
                break;
            }
        }
        cout<<max_n<<"\n";
    }
    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}