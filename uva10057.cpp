#include<bits/stdc++.h>
#define DEBUG

using namespace std;

void ignore_lines(int n) {
    while(n--)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
int countA(vector<int> &vec, int med_pos1, int med_pos2) {
    int n = vec.size();
    int i = med_pos1-1;
    int count = 0;

    while(i>=0 && vec[i] == vec[med_pos1]) {
        i--;
        count++;
    }
    
    i = med_pos2+1;
    while(i < n && vec[i] == vec[med_pos2]) {
        i++;
        count++;
    }
    count += (med_pos1 == med_pos2)?1:2;
    
    return count;
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

        if(cin.fail()) break;

        vector<int> vec(n);
        for(int i=0;i<n;++i) {
            cin>>vec[i];
        }

        sort(vec.begin(), vec.end());

        int med_pos1 = (n-1)/2;
        int med_pos2 = n/2;

        int a = vec[med_pos1];
        int aCount = countA(vec, med_pos1, med_pos2);
        int possibleACount = vec[med_pos2] - vec[med_pos1] + 1;

        cout<<a<<" "<<aCount<<" "<<possibleACount<<endl;

    }

    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}