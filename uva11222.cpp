#include<bits/stdc++.h>
#define DEBUG

using namespace std;

void ignore_lines(int n) {
    while(n--)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void count_unique(vector<set<int>> &inp, int f_no, pair<int, vector<int>> &unique) {
    int f1 = f_no;
    int f2 = (f_no + 1) % 3;
    int f3 = (f_no + 2) % 3;

    unique.first = f1+1;
    for(auto p_no : inp[f1]) {
        if(inp[f2].find(p_no) == inp[f2].end() &&
            inp[f3].find(p_no) == inp[f3].end()) {
                unique.second.push_back(p_no);
            }
    }
}
bool comp(pair<int, vector<int>> &p1, pair<int, vector<int>> &p2) {
    return p1.second.size() > p2.second.size();
}

void print_unique(pair<int, vector<int>> &unique) {
    cout<<unique.first<<" "<<unique.second.size();
    for(int i=0;i<unique.second.size();++i) {
        cout<<" "<<unique.second[i];
    }
    cout<<endl;
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
    for(int x = 1; x<=t; ++x) {
        
        vector<set<int>> inp(3);
        for(int i=0;i<3;++i) {
            int n;
            cin>>n;
            for(int j=0;j<n;++j) {
                int p_no;
                cin>>p_no;
                inp[i].insert(p_no);
            }
        }

        vector<pair<int, vector<int>>> uniques(3);
        
        count_unique(inp, 0, uniques[0]);
        count_unique(inp, 1, uniques[1]);
        count_unique(inp, 2, uniques[2]);


        sort(uniques.begin(), uniques.end(), comp);

        cout<<"Case #"<<x<<":"<<endl;
        print_unique(uniques[0]);

        for(int i=1;i<3;++i) {
            if(uniques[i].second.size() == uniques[0].second.size()) {
                print_unique(uniques[i]);
            }
        }

    }
    return 0;
}