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

string src, trg;
_vec<string> res;
_umap<char, int> fm;

/* This solution gets WA for some reason. I haven't been able to figure out the test case for which
    it is getting WA. 
    On Udebug it passed all available test cases and this is the first time for me that any solution 
    got accepted on udebug for all test cases but not on uva online judge.
    If anyone figures out the flaw in this code kindly type it in the comments
*/
void find(_umap<char, int> fm, int i=0, int j=0, string str = "", stack<char> st = stack<char>()) {
    for(; i<=src.size(); ++i) {
        while(st.size()>0 && st.top() == trg[j]) {
            if(fm[st.top()] > 0) {
                st.push(src[i]);
                fm[src[i]]--;
                find(fm, i+1, j, str+" i", st);
                fm[src[i]]++;
                st.pop();
            }
            st.pop();
            j++;
            str += " o";
        }
        if(i<src.size()) {
            st.push(src[i]);
            str += " i";
            fm[src[i]]--;
        }
    }
    if(st.empty())
        res.push_back(str.substr(1));
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
    while(1) {
        cin>>src>>trg;
        if(cin.fail()) break;

        res.clear();
        fm.clear();
        for(char c : src) fm[c]++;

        find(fm);

        cout<<"[\n";
        sort(res.begin(), res.end());
        for(string str : res) {
            cout<<str<<"\n";
        }
        cout<<"]\n";
    }





    /* #######################CODE_END############################### */
    #ifdef DEBUG
    auto _end = chrono::high_resolution_clock::now();
    auto _duration = chrono::duration_cast<chrono::nanoseconds>(_end - _start);
    _ll _ns = _duration.count();
    double _s = _ns / 1e9;
    //cout<<"\nDuration: "<<_s<<" sec\n";
    cin.rdbuf(_in_backup);
    cout.rdbuf(_out_backup);
    #endif
    return 0;
}