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

int n, l;
string ans;
void init_tc() {
    ans = "";
}
bool isHard(string str) {
    for(int len = 1; len <= (str.size())/2; ++len) {
        string s1 = str.substr(str.size()-len);
        string s2 = str.substr(str.size()-2*len, len);
        if(s1 == s2) 
            return false;
    }
    return true;
}
void genHardSeq(string str = "") {
    if(!isHard(str))
        return;
    n--;
    if(n==-1) {
        ans = str;
        return;
    }

    for(char c = 'A'; c<'A'+l && ans==""; ++c) {
        str.push_back(c);
        genHardSeq(str);
        str.pop_back();
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
    while(1) {
        cin>>n>>l;
        if(n==0 && l==0) break;
        init_tc();

        genHardSeq();

        for(int i=0; i<ans.size(); i+=4) {
            if(i%64 == 0)
                cout<<((i!=0)?"\n":"");
            else 
                cout<<" ";
            cout<<ans.substr(i, 4);
        }
        cout<<"\n";
        cout<<ans.size()<<"\n";
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