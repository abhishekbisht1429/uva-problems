#include<bits/stdc++.h>
#define DEBUG

using namespace std;

void ignore_lines(int n) {
    while(n--)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
int placeCard(vector<pair<string,bool>> &vec, pair<string,string> &p, int start) {
    int n = vec.size();
    int w_size = p.second.size();
    int pos = start;
    // cout<<"start "<<start<<"   ";
    // cout<<p.second<<" "<<pos<<"    ";

    for(int i=0;;++i) {
        pos = (start + i) % vec.size();
        if(vec[pos].second == false) {
            w_size--;
            if(w_size == 0)
                break;
        }
    }
    
    // cout<<p.second<<" "<<pos<<endl;
    vec[pos].first = p.first;
    vec[pos].second = true;

    return (pos+1)%n;
}

int main() {
    #ifdef DEBUG
    ifstream in("input.txt");
    ofstream out("output.txt");

    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());
    #endif

    while(1) {
        int n;
        cin>>n;
        if(n==0) break;

        vector<pair<string,bool>> vec(n);
        int start = 0;
        while(n--) {
            pair<string, string> p;
            cin>>p.first;
            cin>>p.second;

            start = placeCard(vec, p, start);
        }

        for(int i=0;i<vec.size();++i) {
            cout<<vec[i].first;
            if(i!=vec.size()-1)
                cout<<" ";
        }
        cout<<endl;

    }
    return 0;
}