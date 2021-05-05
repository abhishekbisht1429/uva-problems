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
    int case_n = 0;
    while(1) {
        int n;
        cin>>n;

        if(n==0) break;

        case_n++;

        vector<int> y_vec(n), a_vec(n), b_vec(n);
        int max_a = -1;
        for(int i=0;i<n;++i) {
            cin>>y_vec[i]>>a_vec[i]>>b_vec[i];
            max_a = max(max_a, a_vec[i]);
        }

        int year;
        bool found;
        for(year = max_a; year<10000; ++year) {
            found = true;
            for(int i=0;i<n;++i) {
                if(a_vec[i] + ((year - a_vec[i]) % (b_vec[i] - a_vec[i])) != y_vec[i]) {
                    found = false;
                    break;
                }
            }
            if(found) {
                break;
            }
        }
        cout<<"Case #"<<case_n<<":"<<endl;
        if(found) {
            cout<<"The actual year is "<<year<<"."<<endl;
        } else {
            cout<<"Unknown bugs detected."<<endl;
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