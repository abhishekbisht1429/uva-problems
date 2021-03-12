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
    while(1) {
        int n;
        cin>>n;

        if(cin.fail()) break;
        
        vector<string> vec(n);
        int l = 0;
        for(int i=0;i<n;++i) {
            cin>>vec[i];
            l = max(l, (int)vec[i].size());
        }
        sort(vec.begin(), vec.end());
        
        int c = 1 + (60 - l) / (l+2); //check
        int r = (int)ceil((double)n / c);

        // cout<<"l "<<l<<endl;
        // cout<<"c "<<c<<endl;
        // cout<<"r "<<r<<endl;

        for(int i=0;i<60;++i) {
            cout<<"-";
        }
        cout<<endl;
        for(int i=0;i<r;++i) {
            for(int j=0;j<c;++j) {
                int pos = r * j + i;
                if(pos < vec.size()) {
                    cout<<vec[pos];
                    int spaces;
                    if(j!=c-1) {
                        spaces = l+2 - vec[pos].size();
                    } else {
                        spaces = l - vec[pos].size();
                    }
                    while(spaces--) {
                        cout<<" ";
                    }
                }
            }
            cout<<endl;
        }
    }

    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}