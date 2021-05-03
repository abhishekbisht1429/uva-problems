#include<bits/stdc++.h>
#define DEBUG

using namespace std;

void ignore_lines(int n) {
    while(n--)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
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
    int n;
    cin>>n;
    for(int case_n = 1; case_n <= n; ++case_n) {
        cout<<"Case #"<<case_n<<":";

        int c, r;
        cin>>c>>r;

        vector<int> factors;
        int q_total = c - r;
        if(q_total > 0) {
            for(int i=1; i<=(int)sqrt(q_total); ++i) {
                if(q_total % i == 0) {
                    factors.push_back(i);
                    if(i != q_total/i)
                        factors.push_back(q_total/i);
                }
            }
            sort(factors.begin(), factors.end());

            for(int i=0;i<factors.size();++i) {
                if(factors[i] > r) {
                    cout<<" "<<factors[i];
                }
            }
        } else {
            cout<<" "<<0;
        }
        cout<<endl;
    }

    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}