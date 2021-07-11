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

bool isSorted(_vec<int> &vec) {
    for(int i=0; i<vec.size()-1; ++i) {
        if(vec[i] > vec[i+1])
            return false;
    }
    return true;
}


/* The validity of this algorithm is based on the fact that
    the number of swaps for 'each element' will remain same regardless of the
    order of swapping as each element must go to its valid position step by step(one swap at a time).

    However, note that the position of the element may vary in the various possible orders of swaps, therefore 
    different possible swap maps cannot be obtained only by permuting one swap map. The relative position however does
    not change.
*/
int minSwapMaps(_vec<int> &vec) {
    if(isSorted(vec)) {
        return 1;
    }

    int count = 0;
    for(int i=0; i<vec.size()-1; ++i) {
        if(vec[i] > vec[i+1]) {
            swap(vec[i], vec[i+1]);
            count += minSwapMaps(vec);
            swap(vec[i], vec[i+1]);
        }
    }
    return count;
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
    int tc = 0;
    while(1) {
        int n;
        cin>>n;
        if(n==0) break;
        _vec<int> vec(n);
        for(int i=0; i<n; ++i) {
            cin>>vec[i];
        }

        int min_swap_map = (!isSorted(vec))?minSwapMaps(vec):0;
        cout<<"There are "<<min_swap_map<<" swap maps for input data set "<<(++tc)<<".\n";
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