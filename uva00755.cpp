#include<bits/stdc++.h>
#define DEBUG

using namespace std;

void ignore_lines(int n) {
    while(n--)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
string process(unordered_map<int, int> &keymap, string &input) {
    // cout<<"input : "<<input<<endl;
    string output;
    int i =0;
    for(auto c : input) {
        if(c != '-') {
            if(isalpha(c)) {
                output.push_back(keymap[c]);
            } else if(isdigit(c)){
                output.push_back(c);
            }
        }
    }
    output.insert(3,1,'-');
    // cout<<"output : "<<endl;
    return output;
}
int main() {
    #ifdef DEBUG
    ifstream in("input.txt");
    ofstream out("output.txt");

    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());
    #endif

    unordered_map<int,int> keymap;
    keymap['A'] = keymap['B'] = keymap['C'] = '2';
    keymap['D'] = keymap['E'] = keymap['F'] = '3';
    keymap['G'] = keymap['H'] = keymap['I'] = '4';
    keymap['J'] = keymap['K'] = keymap['L'] = '5';
    keymap['M'] = keymap['N'] = keymap['O'] = '6';
    keymap['P'] = keymap['R'] = keymap['S'] = '7';
    keymap['T'] = keymap['U'] = keymap['V'] = '8';
    keymap['W'] = keymap['X'] = keymap['Y'] = '9';

    int t;
    cin>>t;
    ignore_lines(1);
    while(t--) {
        ignore_lines(1);
        int n;
        cin>>n;
        vector<string> inp(n);
        unordered_map<string, int> freq_map;
        ignore_lines(1);
        for(int i=0;i<n;++i) {
            getline(cin, inp[i]);
            string out = process(keymap, inp[i]);
            if(freq_map.find(out) == freq_map.end()) {
                freq_map[out] = 0;
            }
            freq_map[out]++;
        }
        vector<string> keys;
        for(auto itr : freq_map) {
            keys.push_back(itr.first);
        }

        sort(keys.begin(), keys.end());
        ostringstream oss;
        for(auto key : keys) {
            if(freq_map[key] > 1)
                oss<<key<<" "<<freq_map[key]<<endl;
        }
        string output = oss.str();
        if(output.size()!=0) {
            cout<<output;
        } else {
            cout<<"No duplicates."<<endl;
        }
        if(t!=0) cout<<endl;

    }

    

    return 0;
}