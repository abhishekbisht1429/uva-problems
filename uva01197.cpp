#include<bits/stdc++.h>
#define DEBUG

using namespace std;

void ignore_lines(int n) {
    while(n--)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

template<typename T>
class union_find {
    unordered_map<T, T> parent;
    unordered_map<T, int> rank;
    unordered_map<T, int> nodeCount;
    int dj_set_count = 0;

    public:void add(T u) {
        if(parent.find(u) == parent.end()) {
            parent[u] = u;
            rank[u] = 1;
            dj_set_count++;
            nodeCount[u] = 1;
        }
    }

    public:T findSet(T u) {
        return (parent[u] == u) ? u : (parent[u] = findSet(parent[u]));
    }

    public:void unionSet(T u, T v) {
        T rep_u = findSet(u);
        T rep_v = findSet(v);
        if(rep_u != rep_v) {
            if(rank[rep_u] > rank[rep_v]) {
                parent[rep_v] = parent[rep_u];
                nodeCount[rep_u] += nodeCount[rep_v];
            } else {
                parent[rep_u] = parent[rep_v];
                nodeCount[rep_v] += nodeCount[rep_u];
                if(rank[rep_u] == rank[rep_v]) {
                    rank[rep_v]++;
                }
            }
            dj_set_count--;
        }
    }

    public:T getRank(T u) {
        return rank[u];
    }

    public:int getDjSetCount() {
        return dj_set_count;
    }

    public:int getNodeCount(T u) {
        return nodeCount[u];
    }
};

int main() {
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
        int n, m;
        cin>>n>>m;

        if(n==0 && m==0) break;

        union_find<int> uf;
        uf.add(0);
        for(int i=0; i<m; ++i) {
            int k, val1;
            cin>>k>>val1;
            uf.add(val1);

            k--;
            while(k--) {
                int val;
                cin>>val;
                uf.add(val);
                uf.unionSet(val1, val);
            }
        }
        cout<<uf.getNodeCount(uf.findSet(0))<<endl;
    }

    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}