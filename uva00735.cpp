#include<bits/stdc++.h>

using namespace std;

#define DEBUG

#define _umap unordered_map
#define _uset unordered_set
#define _ll long long
#define _ull unsigned _ll
#define _vec vector

#define _max3(a, b, c) max(a, max(b, c))
#define _max4(a, b, c, d) max(max(a, b), max(c, d))
#define _min3(a, b, c) min(a, min(b, c))
#define _min4(a, b, c, d) min(min(a, b), min(c, d))
#define _ignore_lines(n) for(int i=0;i<n;++i) cin.ignore(numeric_limits<streamsize>::max(), '\n')

/* Bit Manipulation */
#define _isSet(n, i) (n & (1L<<i))
#define _set(n, i) n = (n | (1L<<i)) 
#define _reset(n, i) n = (n & (0xfffffffffffffffeL<<i))
#define _flip(n, i) n = (n ^ (1L<<i))

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

    /* Preprocessing */
    _uset<int> temp;
    for(int i=0; i<=20; ++i) {
        temp.insert(i);
        temp.insert(2*i);
        temp.insert(3*i);
    }
    temp.insert(50);
    _vec<int> score(temp.begin(), temp.end());
    sort(score.begin(), score.end());

    while(1) {
        int n;
        cin>>n;
        if(n<=0) break;

        int comb = 0, perm = 0;
        for(int i=0; i<score.size(); ++i) {
            if(score[i] > n) break;
            for(int j=i; j<score.size(); ++j) {
                if(score[i] + score[j] > n) break;
                for(int k=j; k<score.size(); ++k) {
                    if(score[i] + score[j] + score[k] > n) break;
                    if(score[i] + score[j] + score[k] == n) {
                        comb++;
                        if(score[i] == score[j] && score[j] == score[k] && score[k] == score[i]) {
                            perm++;
                        } else if(score[i] == score[j] || score[j] == score[k] || score[k] == score[i]) {
                            perm += 3;
                        } else {
                            perm += 6;
                        }
                    }
                }
            }
        }
        if(comb > 0) {
            cout<<"NUMBER OF COMBINATIONS THAT SCORES "<<n<<" IS "<<comb<<".\n";
            cout<<"NUMBER OF PERMUTATIONS THAT SCORES "<<n<<" IS "<<perm<<".\n";
        } else {
            cout<<"THE SCORE OF "<<n<<" CANNOT BE MADE WITH THREE DARTS.\n";
        }
        for(int i=0; i<70; ++i) {
            cout<<"*";
        }
        cout<<"\n";
    }
    cout<<"END OF OUTPUT\n";


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