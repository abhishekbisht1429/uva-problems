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

#define SIZE 10000
struct entry {
    int l, h;
    string name;
};

vector<entry> db(SIZE);
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
    int t;
    cin>>t;
    while(t--) {
        int d;
        cin>>d;
        for(int i=0;i<d; ++i) {
            cin>>db[i].name>>db[i].l>>db[i].h;
        }
        int q;
        cin>>q;
        while(q--) {
            int p;
            cin>>p;
            int idx = -1, count = 0;
            for(int i=0; i<d; ++i) {
                if(p >= db[i].l && p <= db[i].h) {
                    count++;
                    idx = i;
                }
            }
            if(count == 1) {
                cout<<db[idx].name<<"\n";
            } else {
                cout<<"UNDETERMINED\n";
            }
        }
        if(t!=0) cout<<"\n";
    }
    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}