#include<bits/stdc++.h>
#define DEBUG

using namespace std;

void ignore_lines(int n) {
    while(n--)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
bool compare(const pair<string, string> &p1, const pair<string, string> &p2) {
    return p1.first < p2.first;
}
string change_case(string &str, string type) {
    string out = "";
    for(char c : str) {
        if(type == "lower") {
            out.push_back(tolower(c));
        } else if(type == "upper") {
            out.push_back(toupper(c));
        }
    }
    return out;
}
void find_kwic_indices(string title, vector<pair<string, string>> &indices, unordered_set<string> &wordsToIgnore) {
    title = change_case(title, "lower");
    istringstream iss(title);
    int replace_pos = 0;
    while(1) {
        string s;
        iss>>s;
        if(iss.fail()) break;
        if(wordsToIgnore.find(s) == wordsToIgnore.end()) {
            string capitalized = change_case(s, "upper");
            string title_copy = title;
            indices.push_back({capitalized, title_copy.replace(replace_pos, capitalized.size(), capitalized)});
        }
        replace_pos += s.size() + 1;
    }
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
    unordered_set<string> wordsToIgnore;
    while(1) {
        string word;
        getline(cin, word);
        if(word == "::") break;
        wordsToIgnore.insert(word);
    }
    vector<pair<string,string>> indices;

    while(1) {
        string title;
        getline(cin, title);
        if(cin.fail()) break;

        find_kwic_indices(title, indices, wordsToIgnore);
    }
    stable_sort(indices.begin(), indices.end(), compare);

    for(auto p : indices) {
        cout<<p.second<<endl;
    }

    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}