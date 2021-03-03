#include<bits/stdc++.h>
#define DEBUG

using namespace std;

void ignore_lines(int n) {
    while(n--)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
string convert(string &inp) {
    string out;
    for(char c : inp) {
        if(isalpha(c)) {
            out.push_back(tolower(c));
        }
    }
    return out;
}
void extract_words(string &text, set<string> &dict) {
    bool started_extraction = false;
    string word;
    for(char c : text) {
        c = tolower(c);
        if(started_extraction) {
            if(isalpha(c) || c == '-') {
                word.push_back(c);
            } else {
                dict.insert(word);
                word = "";
                started_extraction = false;
            }
        } else {
            if(isalpha(c) || c == '-') {
                started_extraction = true;
                word.push_back(c);
            }
        }
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
    set<string> dict;
    string text;
    while(1) {
        string line;
        getline(cin, line);

        if(cin.fail()) break;

        if(line.back() == '-') {
            text += line.substr(0,line.size()-1);
        } else {
            text+=line+"\n";
        }
        // extract_words(line, dict);
    }
    extract_words(text, dict);
    for(string word : dict) {
        cout<<word<<endl;
    }

    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}