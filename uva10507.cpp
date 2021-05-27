#include<bits/stdc++.h>
#define DEBUG
#define umap unordered_map
#define uset unordered_set
#define vec vector
#define ll long long

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
        int n, m;
        cin>>n>>m;

        if(cin.fail()) break;

        union_find<char> uf;
        umap<char, vec<char>> adjMap;
        string str;
        cin>>str;
        for(int i=0; i<str.size(); ++i) {
            uf.add(str[i]);
            adjMap[str[i]] = vec<char>();
        }
        uf.unionSet(str[0], str[1]);
        uf.unionSet(str[1], str[2]);

        char awake_rep = uf.findSet(str[0]);

        for(int i=0; i<m; ++i) {
            string conn;
            cin>>conn;

            if(adjMap.find(conn[0]) == adjMap.end()) {
                adjMap[conn[0]] = vec<char>();
                uf.add(conn[0]);
            }
            if(adjMap.find(conn[1]) == adjMap.end()) {
                adjMap[conn[1]] = vec<char>();
                uf.add(conn[1]);
            }

            adjMap[conn[0]].push_back(conn[1]);
            adjMap[conn[1]].push_back(conn[0]);
        }

        /* Processing */

        int years = 0;
        while(1) {
            vec<char> awokenAreas;
            for(auto p : adjMap) {
                char area = p.first;
                if(uf.findSet(area) != awake_rep) {
                    int count = 0;
                    for(char n_area : p.second) {
                        if(uf.findSet(n_area) == awake_rep) {
                            count++;
                        }
                    }
                    if(count >= 3) {
                        awokenAreas.push_back(area);
                    }
                }
            }
            
            if(awokenAreas.size() == 0) {
                break;
            }
            for(char area : awokenAreas) {
                uf.unionSet(awake_rep, area);
            }
            years++;
        }

        /* OUTPUT */

        bool brain_awake = true;
        if(adjMap.size() == n) {
            for(auto p : adjMap) {
                char area = p.first;
                if(uf.findSet(area) != awake_rep) {
                    brain_awake = false;
                    break;
                }
            }
        } else {
            brain_awake = false;
        }
        if(brain_awake) {
            cout<<"WAKE UP IN, "<<years<<", YEARS"<<"\n";
        } else {
            cout<<"THIS BRAIN NEVER WAKES UP"<<"\n";
        }
    }
    
    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}