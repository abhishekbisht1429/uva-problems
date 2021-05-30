#include<bits/stdc++.h>
#define DEBUG

#define INF numeric_limits<int>::max()
#define umap unordered_map
#define uset unordered_set
#define ll long long
#define vec vector

using namespace std;

void ignore_lines(int n) {
    while(n--)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

class segment_tree {
    umap<int, int> *freqMap;
    vec<int> *val;
    vec<int> tree;

    public:segment_tree(vec<int> *val, umap<int, int> *freqMap) {
        this->val = val;
        this->freqMap = freqMap;

        tree = vec<int>(4 * (*val).size());
        build(0, 0, (*val).size()-1);
    }

    private:void build(int node, int p, int q) {
        if(p == q) { //leaf node
            tree[node] = (*freqMap)[(*val)[p]];
        } else {
            int mid = (p+q)/2;
            build(2*node + 1, p, mid);
            build(2*node + 2, mid+1, q);
            tree[node] = max(tree[2*node + 1], tree[2*node + 2]);
        }
    }

    public:int rmq(int node, int p, int q, int l, int r) {
        if(l > q || r < p) {
            return -1;
        } else if(l <= p && r >= q) {
            return tree[node];
        } else {
            int mid = (p+q)/2;
            int v1 = rmq(node*2 + 1, p, mid, l, r);
            int v2 = rmq(node*2 + 2, mid+1, q, l, r);

            return max(v1, v2);
        }
    }

};

bool run_test_case() {
    int n, q;
    cin>>n;
    if(n==0) return 0;

    cin>>q;

    umap<int, int> freqMap, startMap, posMap;
    vec<int> val, inp;
    for(int i=0; i<n; ++i) {
        int v;
        cin>>v;
        if(freqMap.find(v) == freqMap.end()) {
            freqMap[v] = 0;
            startMap[v] = i;
            val.push_back(v);
            posMap[v] = val.size()-1;
        }
        freqMap[v]++;
        inp.push_back(v);
    }
    segment_tree sg_tree(&val, &freqMap);
    while(q--) {
        int i, j;
        cin>>i>>j;
        i--;
        j--;

        // cout<<i<<" "<<j<<endl;
        int x, y, ans;
        x = startMap[inp[i]] + freqMap[inp[i]];
        y = startMap[inp[j]] - 1;
        // cout<<x<<" "<<y<<endl;
        if(x > j) {
            ans = j - i + 1;
        } else {
            int c1 = x - i;
            int c2 = sg_tree.rmq(0, 0, val.size()-1, posMap[inp[x]], posMap[inp[y]]);
            int c3 = j - y;
            // cout<<c1<<" "<<c2<<" "<<c3<<"\n";
            ans = max(c1, max(c2, c3));
        }
        cout<<ans<<"\n";
    }

    return 1;
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
    while(run_test_case());
    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}