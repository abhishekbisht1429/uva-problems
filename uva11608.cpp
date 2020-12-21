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

    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());
    #endif

    int n_case = 0;
    while(1) {
        ++n_case;
        vector<int> aval(13);
        vector<int> req(13);

        cin>> aval[0];
        if(aval[0]<0) break;

        for(int i=1;i<=12;++i) {
            cin>>aval[i];
        }
        for(int i=1;i<=12;++i) {
            cin>>req[i];
        }

        vector<bool> problem(13);
        for(int i=1;i<=12;++i) {
            if(req[i]<=aval[i-1]) {
                problem[i] = false;
                aval[i] += (aval[i-1] - req[i]);
            } else {
                problem[i] = true;
                aval[i] += aval[i-1];
            }
        }

        cout<<"Case "<<n_case<<":"<<endl;
        for(int i=1;i<=12;++i) {
            cout<<"No problem";
            if(problem[i]) {
                cout<<". :("<<endl;;
            } else {
                cout<<"! :D"<<endl;
            }
        }
    }
    
    return 0;
}