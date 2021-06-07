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
struct bin {
    int b=0, g=-0, c=0;
};
int count(bin &b, char c) {
    if(c == 'B') {
        return b.c + b.g;
    } else if(c == 'G') {
        return b.b + b.c;
    } else {
        return b.b + b.g;
    }
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
    while(1) {
        bin b1, b2, b3;
        cin>>b1.b>>b1.g>>b1.c;
        cin>>b2.b>>b2.g>>b2.c;
        cin>>b3.b>>b3.g>>b3.c;

        if(cin.fail()) break;

        int min_moves = INT_MAX;
        string req_perm;
        string str = "BCG";
        do {
            int total = count(b1, str[0]) +
                        count(b2, str[1]) +
                        count(b3, str[2]);
            if(total < min_moves) {
                min_moves = total;
                req_perm = str;
            }
        } while(next_permutation(str.begin(), str.end()));

        cout<<req_perm<<" "<<min_moves<<"\n";
    }
    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}