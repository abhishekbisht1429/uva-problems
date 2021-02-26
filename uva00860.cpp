#include<bits/stdc++.h>
#define DEBUG
#define TEXT_END "****END_OF_TEXT****"
#define INPUT_END "****END_OF_INPUT****"

using namespace std;

void ignore_lines(int n) {
    while(n--)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
double cal_entropy(int lambda, unordered_map<string, int> &freq_map) {
    double sum = 0.0;
    for(auto entry : freq_map) {
        sum += entry.second * (log10(lambda) - log10(entry.second));
    }
    return sum / lambda;
}
bool isValid(char c) {
    switch(c) {
        case ',':
        case '.':
        case ':':
        case ';':
        case '!':
        case '?':
        case '"':
        case '(':
        case ')':
        case ' ':
        case 9:
        case '\n': return false;
        default: return true;
    }
    
}
string convert(string &s) {
    string upper;
    for(char c : s) {
        if(isValid(c)) {
            upper += toupper(c);
        }
    }
    return upper;
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

    int count = 0;
    unordered_map<string, int> freq_map;
    while(1) {
        string line;
        getline(cin, line);

        if(line == TEXT_END) {
            int lambda = count;
            double entropy = cal_entropy(lambda, freq_map);
            double rel_entropy = (entropy / log10(lambda)) * 100;

            entropy = round(entropy * 10) / 10;
            rel_entropy = round(rel_entropy);

            cout<<fixed<<setprecision(1)<<lambda<<" "<<entropy<<" "<<(int)rel_entropy<<endl;
            count = 0;
            freq_map.clear();
            continue;
        } else if(line == INPUT_END) {
            break;
        }

        stringstream ss(line);
        while(1) {
            string temp;
            ss>>temp;

            if(ss.fail()) break;
            temp = convert(temp);
            if(temp.size() > 0) {
                freq_map[temp] = freq_map[temp] + 1;
                count++;
            }
        }
    }

    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}