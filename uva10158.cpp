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

bool areFriends(union_find<int> &uf, int x, int y) {
    return uf.findSet(x) == uf.findSet(y);
}

bool areEnemies(union_find<int> &uf, unordered_map<int, unordered_set<int>> &enemySet, int x, int y) {
    int rep_x = uf.findSet(x);
    int rep_y = uf.findSet(y);

    return enemySet[rep_x].find(rep_y) != enemySet[rep_x].end();
}

bool setFriends(union_find<int> &uf, unordered_map<int, unordered_set<int>> &enemySet, int x, int y) {
    if(areEnemies(uf, enemySet, x, y)) {
        return false;
    } else if(areFriends(uf, x, y)) {
        return true;
    }
    int rep_x = uf.findSet(x);
    int rep_y = uf.findSet(y);

    int new_rep = uf.unionSet(x, y);
    int old_rep;
    if(new_rep == rep_x) {
        old_rep = rep_y;
    } else {
        old_rep = rep_x;
    }

    for(int e : enemySet[old_rep]) {
        enemySet[new_rep].insert(e);
    }
    enemySet.erase(old_rep);

    return true;
}

int setEnemies(union_find<int> &uf, unordered_map<int, unordered_set<int>> &enemySet, int x, int y) {
    if(areFriends(uf, x, y)) {
        return false;
    } else if(areEnemies(uf, enemySet, x, y)) {
        return true;
    }
    int rep_x = uf.findSet(x);
    int rep_y = uf.findSet(y);

    for(int e : enemySet[rep_x]) {
        if(areEnemies(uf, enemySet, e, rep_y)) {
            return false;
        }
    }

    for(int e : enemySet[rep_y]) {
        if(areEnemies(uf, enemySet, e, rep_x)) {
            return false;
        }
    }

    enemySet[rep_x].insert(rep_y);
    enemySet[rep_y].insert(rep_x);
    for(int e : enemySet[rep_x]) {
        setFriends(uf, enemySet, e, rep_y);
    }
    for(int e : enemySet[rep_y]) {
        setFriends(uf, enemySet, e, rep_x);
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
    int n;
    cin>>n;
    union_find<int> uf;
    unordered_map<int, unordered_set<int>> enemySet;
    for(int i=0; i<n; ++i) {
        uf.add(i);
        enemySet[i] = unordered_set<int>();
    }

    while(1) {
        int c, x, y;
        cin>>c>>x>>y;

        // cout<<c<<x<<y<<"   ";
        
        if((c==0) && (x == 0) && (y == 0)) break;

        if(c == 1) {
            if(!setFriends(uf, enemySet, x, y)) {
                cout<<-1<<endl;
            }
        } else if(c == 2) {
            if(!setEnemies(uf, enemySet, x, y)) {
                cout<<-1<<endl;
            }
        } else if(c == 3) {
            cout<<areFriends(uf, x, y)<<"\n";
        } else {

            cout<<areEnemies(uf, enemySet, x, y)<<"\n";
        }

    }


    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}