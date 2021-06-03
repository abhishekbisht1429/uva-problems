#include<bits/stdc++.h>

using namespace std;

#define DEBUG

#define umap unordered_map
#define uset unordered_set
#define ll long long
#define vec vector

#define INF numeric_limits<int>::max()
#define MIN_INF numeric_limits<int>::min()

#define max3(a, b, c) max(a, max(b, c))
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define min3(a, b, c) min(a, min(b, c))
#define min4(a, b, c, d) min(min(a, b), min(c, d))
#define ignore_lines(n) for(int i=0;i<n;++i) cin.ignore(numeric_limits<streamsize>::max(), '\n')

struct node {
    int count;
    char pendingAct;
    node() {
        this->count = 0;
        this->pendingAct = 'X';
    }
    node(int count) {
        this->count = count;
        this->pendingAct = 'X';
    }
};

class segment_tree {
    vec<node> tree;

    public:segment_tree(string &pirates) {
        tree = vec<node>(4 * pirates.size());
        build(0, 0, pirates.size()-1, pirates);
    }

    private:void build(int node_i, int l, int r, string &pirates) {
        if(l == r) {
            tree[node_i] = node(pirates[l] == '1');
            return;
        }

        int mid = (l+r)/2;
        build(2*node_i+1, l, mid, pirates);
        build(2*node_i+2, mid+1, r, pirates);

        tree[node_i].count = tree[2*node_i+1].count + tree[2*node_i+2].count;
    }

    private:void changeState(int node_i) {
        if(tree[node_i].pendingAct == 'I') {
            tree[node_i].pendingAct = 'X';
            return;
        }

        if(tree[node_i].pendingAct == 'E') {
            tree[node_i].pendingAct = 'F';
            return;
        }

        if(tree[node_i].pendingAct == 'F') {
            tree[node_i].pendingAct = 'E';
            return;
        }

        if(tree[node_i].pendingAct == 'X') {
            tree[node_i].pendingAct = 'I';
            return;
        }
    }
    
    private:void updateLazily(int node_i, int l, int r, char action) {

        //apply action to current node
        int total = r-l+1;
        if(action == 'F') {
            tree[node_i].count = total;
        } else if(action == 'E') {
            tree[node_i].count = 0;
        } else if(action == 'I') {
            tree[node_i].count = total - tree[node_i].count;
        }

        if(l!=r) {
            if(action == 'I') {
                changeState(2*node_i+1);
                changeState(2*node_i+2);
            } else {
                tree[2*node_i+1].pendingAct = action;
                tree[2*node_i+2].pendingAct = action;
            }
        }
    }
    private:void propogateUpdate(int node_i, int l, int r) {
        if(tree[node_i].pendingAct != 'X') {
            updateLazily(node_i, l, r, tree[node_i].pendingAct);
            tree[node_i].pendingAct = 'X';
        }
    }

    public:void update(int node_i, int l, int r, int ql, int qr, char action) {
        propogateUpdate(node_i, l, r);
        if(ql > r || qr < l) {
            return;
        }

        /* Full Match */
        if(ql <= l && qr >= r) {
            updateLazily(node_i, l, r, action);
            return;
        }
        int mid = (l+r)/2;
        update(2*node_i+1, l, mid, ql, qr, action);
        update(2*node_i+2, mid+1, r, ql, qr, action);

        tree[node_i].count = tree[2*node_i+1].count + tree[2*node_i+2].count;
    }

    public:int rsq(int node_i, int l, int r, int ql, int qr) {
        propogateUpdate(node_i, l, r);
        if(ql>r || qr<l) {
            return 0;
        }

        if(ql <= l && qr >= r) {
            return tree[node_i].count;
        }

        int mid = (l+r)/2;

        return rsq(2*node_i+1, l, mid, ql, qr) +
                rsq(2*node_i+2, mid+1, r, ql, qr);
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
    int n_cases;
    cin>>n_cases;
    for(int case_n = 1; case_n<=n_cases; ++case_n) {
        string pirates;
        int m;
        cin>>m;
        while(m--) {
            int t;
            cin>>t;
            string str;
            cin>>str;
            
            string temp;
            while(t--) {
                temp.append(str);
            }
            pirates.append(temp);
        }
        cout<<"Case "<<case_n<<":\n";
        segment_tree sg_tree(pirates);

        int q;
        cin>>q;
        int qn = 1;
        while(q--) {
            char c;
            int a, b;
            cin>>c>>a>>b;
            if(c=='S') {
                cout<<"Q"<<qn<<": "<<sg_tree.rsq(0, 0, pirates.size()-1, a, b)<<"\n";
                qn++;
            } else {
                sg_tree.update(0, 0, pirates.size()-1, a, b, c);
            }
        }
    }
    
    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}