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
    int n_cases;
    cin>>n_cases;

    while(n_cases--) {
        int s, a, f;
        cin>>s>>a>>f;
        vector<int> street(f), avenue(f);
        for(int i=0;i<f;++i) {
            cin>>street[i]>>avenue[i];
        }
        sort(street.begin(), street.end());
        sort(avenue.begin(), avenue.end());

        int med_street = street[(f-1)/2];
        int med_avenue = avenue[(f-1)/2];

        cout<<"(Street: "<<med_street<<", Avenue: "<<med_avenue<<")"<<endl;
    }

    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}