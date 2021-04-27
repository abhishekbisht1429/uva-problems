#include<bits/stdc++.h>
#define DEBUG
#define INF numeric_limits<int>::max()
#define MIN_INF numeric_limits<int>::min()

using namespace std;

void ignore_lines(int n) {
    while(n--)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
int minAbsDist(string str) {
    int min_abs_dist = INF;
    for(int i=0;i<str.size()-1;++i) {
        min_abs_dist = min(min_abs_dist, abs(str[i] - str[i+1]));
    }
    return min_abs_dist;
}
void findNextPermutations(vector<string> &permutations, string str) {
    bool end = false;
    for(int i=0;i<10;++i) {
        end = next_permutation(str.begin(), str.end());
        permutations.push_back(str);
    }
}
void findPrevPermutations(vector<string> &permutations, string str) {
    for(int i=0;i<10;++i) {
        prev_permutation(str.begin(), str.end());
        permutations.insert(permutations.begin(), str);
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
    while(1) {
        string str;
        getline(cin, str);

        if(cin.fail()) break;

        vector<string> permutations;
        findPrevPermutations(permutations, str);
        permutations.push_back(str);
        findNextPermutations(permutations, str);

        sort(permutations.begin(), permutations.end());

        int maxMinAbsDist = MIN_INF;
        string pass;
        for(string permutation : permutations) {
            int temp = minAbsDist(permutation);
            if(temp > maxMinAbsDist) {
                pass = permutation;
                pass += to_string(temp);
                maxMinAbsDist = temp;
            }
        }
        cout<<pass<<endl;
    }

    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}