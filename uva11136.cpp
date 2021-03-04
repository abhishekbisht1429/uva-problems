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

        if(n==0) break;

        multiset<int> urn;
        long total = 0;
        while(n--) {
            int k;
            cin>>k;
            while(k--) {
                int temp;
                cin>>temp;
                urn.insert(temp);
            }
            int smallest = *(urn.begin());
            int largest = *(--urn.end());
            
            total += (largest - smallest);

            urn.erase(urn.begin());
            urn.erase(--(urn.end()));
        }
        cout<<total<<endl;
    }

    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}