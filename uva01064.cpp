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
#define _reset(n, i) n = (n & ((-1u<<1)<<(i)))
#define _flip(n, i) n = (n ^ (1u<<(i)))
#define _rset(n, i, cnt) n = n | (((1u<<(cnt))-1)<<i)
#define _rreset(n, i, cnt) n = n & ~(((1u<<(cnt))-1)<<i)
#define _ffzi(n, i) __builtin_ffs(~(((1u<<i+1)-1) | n))

#define _isSetl(n, i) ((n) & (1ull<<(i)))
#define _setl(n, i) n = ((n) | (1ull<<(i))) 
#define _resetl(n, i) n = ((n) & ((-1ull<<1)<<(i)))
#define _flipl(n, i) n = ((n) ^ (1ull<<(i)))
#define _rsetl(n, i, cnt) n = n | (((1ull<<(cnt))-1)<<i)
#define _rresetl(n, i, cnt) n = n & ~(((1ull<<(cnt))-1)<<i)
#define _ffzil(n, i) __builtin_ffs(~(((1ull<<i+1)-1) | n))

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
    int case_n = 0;
    while(1) {
        int n, m;
        cin>>n>>m;
        if(n==0 && m==0) break;

        _vec<int> msg_size(n);
        _vec<tuple<int, int, int>> porder(m);
        for(int i=0; i<n; ++i) {
            cin>>msg_size[i];
        }
        for(int i=0; i<m; ++i) {
            int msg_n, st, end;
            cin>>msg_n>>st>>end;
            msg_n--;
            st--;
            end--;
            porder[i] = make_tuple(msg_n, st, end);
        }

        /*processing */
        _vec<int> pass_order(n);
        _vec<set<_p<int, int>>> buf(n);
        _vec<int> oa(n);
        int min_buf_size = INT_MAX;

        for(int i=0; i<n; ++i) 
            pass_order[i] = i;
        
        do {
            int pass_idx = 0;
            for(auto &set : buf) set.clear();
            oa.assign(oa.size(), -1);
            int buf_size = 0;
            int req_buf_size = 0;

            for(int i=0; i<m; ++i) {
                int mn = get<0>(porder[i]);
                int st = get<1>(porder[i]);
                int end = get<2>(porder[i]);

                buf[mn].insert({st, end});
                buf_size += end-st+1;
                
                if(mn == pass_order[pass_idx]) {
                    while(buf[mn].begin()->first == oa[mn]+1) {
                        auto temp = *buf[mn].begin();

                        oa[mn] = temp.second;
                        buf[mn].erase(buf[mn].begin());
                        buf_size -= (temp.second - temp.first + 1);
                    }
                }
                if(oa[mn] == msg_size[mn]-1) pass_idx++;
                req_buf_size = max(req_buf_size, buf_size);
            }
            min_buf_size = min(min_buf_size, req_buf_size);
        } while(next_permutation(pass_order.begin(), pass_order.end()));

        /* Output */
        cout<<"Case "<<++case_n<<": ";
        cout<<min_buf_size<<"\n\n";
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