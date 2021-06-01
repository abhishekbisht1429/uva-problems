#include<bits/stdc++.h>
#define DEBUG
#define umap unordered_map
#define uset unordered_set
#define ll long long
#define vec vector

#define max3(a, b, c) max(a, max(b, c))
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define min3(a, b, c) min(a, min(b, c))
#define min4(a, b, c, d) min(min(a, b), min(c, d))

#define INF numeric_limits<int>::max()
#define MIN_INF numeric_limits<int>::min()

using namespace std;

void ignore_lines(int n) {
    while(n--)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

struct node {
    int minP;
    int maxP;
    node() {
        minP = INF;
        maxP = MIN_INF;
    }
    node(int minP, int maxP) {
        this->minP = minP;
        this->maxP = maxP;
    }
};

class segment_tree_2d {
    vec<node> tree;

    public:segment_tree_2d(vec<vec<int>> &grid) {
        int n = grid.size();
        tree = vec<node>(4 * n * n);
        build(0, 0, n-1, 0, n-1, grid);
    }

    private:void build(int node_i, int t, int b, int l, int r, vec<vec<int>> &grid) {
        if(t>b || l>r) {
            return;
        }
        if(t == b && l == r) {
            // cout<<t<<" "<<b<<" "<<l<<" "<<r<<"\n";
            tree[node_i] = node(grid[t][l], grid[t][l]);
            return;
        }
        int midV = (t+b)/2;
        int midH = (l+r)/2;
        int quad1, quad2, quad3, quad4;
        quad1 = 4*node_i + 1;
        quad2 = 4*node_i + 2;
        quad3 = 4*node_i + 3;
        quad4 = 4*node_i + 4;


        build(quad1, t, midV, midH+1, r, grid);
        build(quad2, t, midV, l, midH, grid);
        build(quad3, midV+1, b, l, midH, grid);
        build(quad4, midV+1, b, midH+1, r, grid);

        tree[node_i].minP = min4(tree[quad1].minP, tree[quad2].minP, tree[quad3].minP, tree[quad4].minP);
        tree[node_i].maxP = max4(tree[quad1].maxP, tree[quad2].maxP, tree[quad3].maxP, tree[quad4].maxP);
    }

    public:void update(int node_i, int i, int j, int val, int t, int b, int l, int r) {
        if(t>b || l>r) {
            return;
        }
        if(t==i && b==i && l == j && r==j) {
            tree[node_i].minP = val;
            tree[node_i].maxP = val;
            return;
        }
        int midH = (l+r)/2;
        int midV = (t+b)/2;
        int quad1, quad2, quad3, quad4;
        quad1 = 4*node_i + 1;
        quad2 = 4*node_i + 2;
        quad3 = 4*node_i + 3;
        quad4 = 4*node_i + 4; 

        if(i<=midV && j>midH) {
            update(quad1, i, j, val, t, midV, midH+1, r);
        } else if(i<=midV && j<=midH) {
            update(quad2, i, j, val, t, midV, l, midH);
        } else if(i>midV && j<=midH) {
            update(quad3, i, j, val, midV+1, b, l, midH);
        } else {
            update(quad4, i, j, val, midV+1, b, midH+1, r);
        }

        tree[node_i].minP = min4(tree[quad1].minP, tree[quad2].minP, tree[quad3].minP, tree[quad4].minP);
        tree[node_i].maxP = max4(tree[quad1].maxP, tree[quad2].maxP, tree[quad3].maxP, tree[quad4].maxP);
    }

    public:pair<int, int> rmq(int node_i, int t, int b, int l, int r, int qt, int qb, int ql, int qr) {
        if(t>b || l>r) {
            return {MIN_INF, INF};
        }
        if(qt>b || qb<t || ql>r || qr<l) {
            return {MIN_INF, INF};
        }

        if(qt<=t && qb>=b && ql<=l && qr>=r) {
            return {tree[node_i].maxP, tree[node_i].minP};
        }

        int midH = (l+r)/2;
        int midV = (t+b)/2;
        int quad1, quad2, quad3, quad4;
        quad1 = 4*node_i + 1;
        quad2 = 4*node_i + 2;
        quad3 = 4*node_i + 3;
        quad4 = 4*node_i + 4; 

        pair<int, int> val1, val2, val3, val4;
        val1 = rmq(quad1, t, midV, midH+1, r, qt, qb, ql, qr);
        val2 = rmq(quad2, t, midV, l, midH, qt, qb, ql, qr);
        val3 = rmq(quad3, midV+1, b, l, midH, qt, qb, ql, qr);
        val4 = rmq(quad4, midV+1, b, midH+1, r, qt, qb, ql, qr);

        int maxP = max4(val1.first, val2.first, val3.first, val4.first);
        int minP = min4(val1.second, val2.second, val3.second, val4.second);

        return {maxP, minP};
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
    int n;
    cin>>n;
    vec<vec<int>> grid(n);
    for(int i=0; i<n; ++i) {
        grid[i] = vec<int>(n);
        for(int j=0; j<n; ++j) {
            cin>>grid[i][j];
        }
    }
    segment_tree_2d sg_tree(grid);

    int q;
    cin>>q;
    while(q--) {
        char c;
        cin>>c;
        if(c == 'q') {
            int qt, qb, ql, qr;
            cin>>qt>>ql>>qb>>qr;
            qt--;
            qb--;
            ql--;
            qr--;
            auto p = sg_tree.rmq(0, 0, n-1, 0, n-1, qt, qb, ql, qr);
            cout<<p.first<<" "<<p.second<<"\n";
        } else {
            int i, j, val;
            cin>>i>>j>>val;
            i--;
            j--;
            sg_tree.update(0, i, j, val, 0, n-1, 0, n-1);
        }
    }
    
    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}