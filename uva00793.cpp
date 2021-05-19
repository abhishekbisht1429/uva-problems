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

    public:void add(T u) {
        if(parent.find(u) == parent.end()) {
            parent[u] = u;
            rank[u] = 1;
        }
    }

    public:T findSet(T u) {
        return (parent[u] == u) ? u : (parent[u] = findSet(parent[u]));
    }

    public:void unionSet(T u, T v) {
        T rep_u = findSet(u);
        T rep_v = findSet(v);
        if(rank[u] > rank[v]) {
            parent[rep_v] = parent[rep_u];
        } else {
            parent[rep_u] = parent[rep_v];
            if(rank[u] == rank[v]) {
                rank[v]++;
            }
        }
    }

    // public:void display() {
    //     for(auto p : parent) {
    //         cout<<p.first<<"->"<<p.second<<endl;
    //     }
    //     cout<<endl;
    // }
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
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        ignore_lines(1);

        union_find<int> uf;
        for(int i=1; i<=n; ++i) {
            uf.add(i);
        }
        
        int success_count = 0, fail_count = 0;

        while(1) {
            string str;
            getline(cin, str);

            if(str.size()==0) break;

            istringstream iss(str);
            char c;
            int u, v;
            iss>>c>>u>>v;

            if(c == 'c') {
                uf.unionSet(u, v);
            } else {
                if(uf.findSet(u) == uf.findSet(v)) {
                    success_count++;
                } else {
                    fail_count++;
                }
            }
        }

        cout<<success_count<<","<<fail_count<<endl;
        if(t!=0) cout<<endl;
    }

    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}