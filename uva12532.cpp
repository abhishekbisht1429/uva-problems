#include<bits/stdc++.h>

using namespace std;

#define DEBUG

#define umap unordered_map
#define uset unordered_set
#define ll long long
#define vec vector

#define INF numeric_limits<ll>::max()
#define MIN_INF numeric_limits<ll>::min()

#define max3(a, b, c) max(a, max(b, c))
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define min3(a, b, c) min(a, min(b, c))
#define min4(a, b, c, d) min(min(a, b), min(c, d))
#define ignore_lines(n) for(int i=0;i<n;++i) cin.ignore(numeric_limits<streamsize>::max(), '\n')

struct node {
    int p=0, n=0;
    
    node operator+(node nd) {
        node res;
        res.n = this->n + nd.n;
        res.p = this->p + nd.p;

        return res;
    }
    node operator-(node nd) {
        node res;
        res.n = this->n - nd.n;
        res.p = this->p - nd.p;

        return res;
    }
};
class fenwick_tree {
    vec<node> ft;
    vec<int> inp;
    public:fenwick_tree(int n) {
        ft = vec<node>(n);
        inp = vec<int>(n);
        inp.assign(n, 0);
    }

    public:void update(int i, int val) {
        int prev = inp[i];
        inp[i] = val;
        for(; i<ft.size(); i = i|(i+1)) {
            ft[i].n += (val<0) - (prev<0);
            ft[i].p += (val>0) - (prev>0);
        }
    }

    private:node prefix_sum(int i) {
        node res;
        for(; i>=0; i = (i&(i+1)) - 1) {
            res = res + ft[i];
        }
        return res;
    }

    public:node sum(int l, int r) {
        return prefix_sum(r) - prefix_sum(l-1);
    }
};
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
        int n, k;
        cin>>n>>k;
        if(cin.fail()) break;

        fenwick_tree ft(n);
        for(int i=0; i<n; ++i) {
            int val;
            cin>>val;
            ft.update(i, val);
        }
        string ans = "";
        while(k--) {
            char c;
            cin>>c;
            if(c=='C') {
                int i, v;
                cin>>i>>v;
                i--;
                ft.update(i, v);
            } else {
                int l, r;
                cin>>l>>r;
                l--;
                r--;
                node nd = ft.sum(l ,r);
                if(nd.n + nd.p != r-l+1) {
                    ans.append("0");
                } else {
                    if(nd.n%2==0) {
                        ans.append("+");
                    } else {
                        ans.append("-");
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}