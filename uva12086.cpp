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
#define ignore_lines(n) for(ll i=0;i<n;++i) cin.ignore(numeric_limits<streamsize>::max(), '\n')

#define SIZE 200005

class sgt {
    vec<ll> tree;

    public:sgt(vec<ll> &inp) {
        tree = vec<ll>(4 * inp.size());
        build(0, 0, inp.size()-1, inp);
    }

    private:void build(ll p, ll l, ll r, vec<ll> &inp) {
        if(l==r) {
            tree[p] = inp[l];
            return;
        }
        build(2*p+1, l, (l+r)>>1, inp);
        build(2*p+2, ((l+r)>>1)+1, r, inp);

        tree[p] = tree[2*p+1] + tree[2*p+2];
    }


    public:void update(ll p, ll l, ll r, ll x, ll val) {
        if(x < l || x > r) {
            return;
        }

        if(l == x && r == x) {
            tree[p] = val;
            return;
        }

        update(2*p+1, l, (l+r)>>1, x, val);
        update(2*p+2, ((l+r)>>1)+1, r, x, val);

        tree[p] = tree[2*p+1] + tree[2*p+2];
    }

    public:ll rsq(ll p, ll l, ll r, ll ql, ll qr) {
        if(ql > r || qr < l) {
            return 0;
        }

        if(ql <= l && qr >= r) {
            // cout<<l<<" "<<r<<" "<<" "<<p<<" "<<tree[p]<<"\n";
            return tree[p];
        }

        return rsq(2*p+1, l, (l+r)>>1, ql, qr) +
                rsq(2*p+2, ((l+r)>>1)+1, r, ql, qr);
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
    ll case_n = 1;
    while(1) {
        ll n;
        cin>>n;

        if(n==0) break;
        vec<ll> r_vec(n);
        for(ll i=0; i<n; ++i) {
            cin>>r_vec[i];
        }

        sgt tree(r_vec);

        ignore_lines(1);

        if(case_n !=1) {
            cout<<"\n";
        }
        cout<<"Case "<<case_n<<":\n";
        while(1) {
            string str;
            getline(cin, str);

            if(str == "END") break;

            istringstream iss(str);
            char c;
            iss>>c;
            if(c == 'S') {
                ll x, r;
                iss>>x>>r;
                x--;
                // cout<<x<<" "<<r<<"\n";
                tree.update(0, 0, n-1, x, r);
            } else {
                ll x, y;
                iss>>x>>y;
                x--;
                y--;
                // cout<<x<<" "<<y<<"\n";
                cout<<tree.rsq(0, 0, n-1, x, y)<<"\n";
            }
        }
        case_n++;
    }
    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}