#include<bits/stdc++.h>
#define DEBUG

using namespace std;

void ignore_lines(int n) {
    while(n--)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
class Comp {
    int m;
    public:
    Comp(int m) {
        this->m = m;
    }

    bool operator()(int a, int b) {
        int a_mod = a % m;
        int b_mod = b % m;

        if(a_mod != b_mod) {
            return a_mod < b_mod;
        } else {
            if(a % 2 == 0 && b % 2 == 0) {
                return a < b;
            } else if(a %2 != 0 && b % 2 != 0) {
                return a > b;
            } else {
                return a%2 != 0;
            }
        }
    }
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
     while(1) {
        int n, m;
        cin>>n>>m;

        cout<<n<<" "<<m<<endl;
        if(n==0 && m==0) break;

        vector<int> vec(n);
        for(int i=0;i<n;++i) {
            cin>>vec[i];
        }

        sort(vec.begin(), vec.end(), Comp(m));

        for(int val : vec) {
            cout<<val<<endl;
        }
    }

    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}