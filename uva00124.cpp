#include<bits/stdc++.h>

using namespace std;

#define DEBUG

#define _umap unordered_map
#define _uset unordered_set
#define _uint unsigned int
#define _ll long long
#define _ull unsigned _ll
#define _vec vector
#define _tp tuple
#define _p pair

#define _ignore_lines(n) for(int i=0;i<n;++i) cin.ignore(numeric_limits<streamsize>::max(), '\n')

/* Bit Manipulation */
#define _isSet(n, i) ((n) & (1u<<(i)))
#define _set(n, i) n = (n | (1u<<(i)))
#define _reset(n, i) n = (n & (~(1u<<(i))))
#define _flip(n, i) n = (n ^ (1u<<(i)))
#define _rset(n, i, cnt) n = n | (((1u<<(cnt))-1)<<i)
#define _rreset(n, i, cnt) n = n & ~(((1u<<(cnt))-1)<<i)
#define _ffzi(n, i) __builtin_ffs(~(((1u<<i+1)-1) | n))

#define _isSetl(n, i) ((n) & (1ull<<(i)))
#define _setl(n, i) n = ((n) | (1ull<<(i)))
#define _resetl(n, i) n = (n & (~(1ull<<(i))))
#define _flipl(n, i) n = ((n) ^ (1ull<<(i)))
#define _rsetl(n, i, cnt) n = n | (((1ull<<(cnt))-1)<<i)
#define _rresetl(n, i, cnt) n = n & ~(((1ull<<(cnt))-1)<<i)
#define _ffzil(n, i) __builtin_ffs(~(((1ull<<i+1)-1) | n))

typedef _p<int, int> _ii;

bool can_append(_umap<char,_umap<char, bool>> &lt, string &s, char c) {
    for(auto x : s)
        if(lt[c][x])
            return false;
    return true;
}
void find_orderings(string vars,
                    _umap<char,_umap<char, bool>> &lt,
                    set<string> &res,
                    int pos,
                    int visited=0,
                    string s="") {
    
    //backtrack if cannot append
    if(!can_append(lt, s, vars[pos]))
        return;
    
    _set(visited, pos);
    s += vars[pos];
    if(s.size() == vars.size()) {
        //append to res if valid order is found
        res.insert(s);
        return;
    }
    
    for(int i=0; i<vars.size(); ++i) {
        if(!_isSet(visited, i)) {
            //if not already visited
            find_orderings(vars, lt, res, i, visited, s);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef DEBUG
    ifstream _in("input.txt");
    ofstream _out("output.txt");
    streambuf* _in_backup = cin.rdbuf();
    streambuf* _out_backup = cout.rdbuf();
    cin.rdbuf(_in.rdbuf());
    cout.rdbuf(_out.rdbuf());
    auto _start = chrono::high_resolution_clock::now();
#endif
    /* ######################CODE_START################################ */
    int count = 0;
    while(1) {
        string vars = "";
        _umap<char, _umap<char, bool>> lt;

        string line1;
        getline(cin, line1);
        if(cin.fail())
            break;
        if(count != 0)
            cout<<"\n";
        ++count;
        istringstream iss(line1);
        while(1) {
            char c;
            iss>>c;
            if(iss.fail())
                break;
            vars += c;
        }

        // initialize lt
        for(int i=0; i<vars.size(); ++i) {
            for(int j=0; j<vars.size(); ++j) {
                lt[vars[i]][vars[j]] = false;
            }
        }

        string line2;
        getline(cin, line2);
        istringstream iss2(line2);
        while(1) {
            char u, v;
            iss2>>u>>v;
            if(iss2.fail())
                break;
            lt[u][v] = true;
        }

        set<string> res;
        for(int i=0; i<vars.size(); ++i)
            find_orderings(vars, lt, res, i);

        for(string order : res) {
            cout << order << "\n";
        }
    }




    /* #######################CODE_END############################### */
#ifdef DEBUG
    auto _end = chrono::high_resolution_clock::now();
    auto _duration = chrono::duration_cast<chrono::nanoseconds>(_end - _start);
    _ll _ns = _duration.count();
    double _s = _ns / 1e9;
    cout<<"\nDuration: "<<_s<<" sec\n";
    cin.rdbuf(_in_backup);
    cout.rdbuf(_out_backup);
#endif
    return 0;
}