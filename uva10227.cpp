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

    public:T unionSet(T u, T v) {
        T rep_u = findSet(u);
        T rep_v = findSet(v);
        T new_rep = rep_u;
        if(rep_u != rep_v) {
            if(rank[rep_u] > rank[rep_v]) {
                parent[rep_v] = rep_u;
                nodeCount[rep_u] += nodeCount[rep_v];
                new_rep = rep_u;
            } else {
                parent[rep_u] = rep_v;
                nodeCount[rep_v] += nodeCount[rep_u];
                new_rep = rep_v;
                if(rank[rep_u] == rank[rep_v]) {
                    rank[rep_v]++;
                }
            }
            dj_set_count--;
        }
        return new_rep;
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

bool set_equals(unordered_set<int> &s1, unordered_set<int> &s2) {
    if(s1.size() != s2.size()) return false;

    for(int i : s1) {
        if(s2.find(i) == s2.end()) {
            return false;
        }
    }
    return true;
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
    int n_cases;
    cin>>n_cases;
    while(n_cases--) {
        int p, t;
        cin>>p>>t;
        ignore_lines(1);

        union_find<int> uf;
        unordered_map<int, unordered_set<int>> opinions;
        for(int i=1; i<=p; ++i) {
            uf.add(i);
        }

        while(1) {
            string str;
            getline(cin, str);

            if(str.size() == 0) break;

            istringstream iss(str);
            int i, j;
            iss>>i>>j;

            opinions[i].insert(j);
        }

        for(int i = 1; i<=p; ++i) {
            for(int j = i+1; j<=p; ++j) {
                if(set_equals(opinions[i], opinions[j])) {
                    uf.unionSet(i, j);
                }
            }
        }

        cout<<uf.getDjSetCount()<<"\n";

        if(n_cases != 0) cout<<"\n";
    }

    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}