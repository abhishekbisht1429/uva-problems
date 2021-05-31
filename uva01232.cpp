#include<bits/stdc++.h>
#define DEBUG
#define umap unordered_map
#define uset unordered_set
#define ll long long
#define vec vector

#define SIZE 100005

using namespace std;

void ignore_lines(int n) {
    while(n--)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
struct node {
    /* max and min height among the descendent nodes
       or 
       max and min height in the range represented by the node
    */
    int max_h;
    int min_h;
    bool isUpdatePending;
};

class segment_tree {
    vec<node> tree;

    public:segment_tree(int n) {
        tree = vec<node>(4 * n);
    }

    public:void init() {
        for(int i=0; i<tree.size(); ++i) {
            tree[i].max_h = tree[i].min_h = 0;
            tree[i].isUpdatePending = true;
        }
    }

    private: void applyPendingUpdate(int node) {
        if(tree[node].isUpdatePending) {

            /* Find out why the commented out syntax below is wrong */
            // tree[2*node + 1].min_h = tree[2*node + 2].max_h = tree[node].min_h;
            // tree[2*node + 1].isUpdatePending = tree[2*node + 2].isUpdatePending = true;

            updateNodeLazily(2*node+1, tree[node].min_h);
            updateNodeLazily(2*node+2, tree[node].min_h);

            tree[node].isUpdatePending = false;
        }
    }
    private:void updateNodeLazily(int node, int h) {
        tree[node].min_h = tree[node].max_h = h;
        tree[node].isUpdatePending = true;
    }

    public: int update(int node, int st, int end, int l, int r, int h) {
        if(l > end || r < st) {
            return 0;
        } 
        
        if(st!=end) { //leaf nodes don't need to apply pending update
            applyPendingUpdate(node);
        }
        // cout<<"st end "<<st<<" "<<end<<"\n";
        int mid = (st+end)/2;
        if(l <= st && r >= end) { //full match
            if(h >= tree[node].max_h) {
                updateNodeLazily(node, h);
                return end - st + 1;
            } else if(h < tree[node].min_h) {
                return 0;
            }
        }

        //full match and minh < h <maxh 
        //              or
        //partial match

        int overlapL = update(2*node + 1, st, mid, l, r, h);
        int overlapR = update(2*node + 2, mid+1, end, l, r, h);

        tree[node].min_h = min(tree[2*node+1].min_h, tree[2*node+2].min_h);
        tree[node].max_h = max(tree[2*node+1].max_h, tree[2*node+2].max_h);

        return overlapL + overlapR;
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
    int c;
    cin>>c;
    segment_tree sg_tree(SIZE);
    while(c--) {
        // cout<<"c"<<c<<endl;
        sg_tree.init();
        int n;
        cin>>n;
        // cout<<"n"<<n<<endl<<endl;
        int count = 0;
        while(n--) {
            int l, r, h;
            cin>>l>>r>>h;
    
            r--;
            // cout<<"\nl r h "<<l<<" "<<r<<" "<<h<<"\n";
            count += sg_tree.update(0, 0, SIZE-1, l, r, h);
        }
        cout<<count<<"\n";
    }
    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}