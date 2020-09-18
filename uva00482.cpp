#include<bits/stdc++.h>
#define DEBUG

using namespace std;

void ignore_line() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    #ifdef DEBUG
    ifstream in("input.txt");
    ofstream out("output.txt");

    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());
    #endif

    int t;
    cin>>t;
    // cout<<t<<endl;
    while(t--) {
        // cout<<t<<endl;
        ignore_line();
        ignore_line();
        string inp;

        getline(cin,inp);
        // cout<<inp<<endl;

        istringstream iss(inp);
        vector<int> indices;
        while(true) {
            int temp;
            iss>>temp;
            if(iss.fail()) break;

            // cout<<temp<<endl;
            indices.push_back(temp);
        }

        vector<string> values;
        for(int i=0;i<indices.size();++i) {
            string val;
            cin>>val;
            values.push_back(val);
        }
        
        vector<string> permutedValues(values.size());
        for(int i=0;i<indices.size();++i) {
            permutedValues[indices[i] - 1] = values[i];
        }

        for(int i=0;i<indices.size();++i) {
            cout<<permutedValues[i]<<endl;
        }
        if(t!=0) cout<<endl;
    }
    

    return 0;
}