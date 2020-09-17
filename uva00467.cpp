#include<bits/stdc++.h>
#define DEBUG

using namespace std;

string get_signal(int time, string prev_signal, int cycle) {
    if(time == 0) {
        return "green";
    }
    if(time % cycle == 0) {
        if(prev_signal == "red") {
            return "green";
        } else {
            return "red";
        }
    } else {
        if(prev_signal == "green" && (time - (time/cycle)*cycle) == cycle - 5) {
            return "yellow";
        } else {
            return prev_signal;
        }
    }
}
int main() {
    #ifdef DEBUG
    ifstream in("input.txt");
    ofstream out("output.txt");

    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());
    #endif

    for(int set=1; true; set++){
        string inp;
        getline(cin, inp);

        if(cin.fail()) break;

        vector<int> cycles;
        istringstream iss(inp);
        while(true) {
            int temp;
            iss>>temp;

            if(iss.fail()) break;

            cycles.push_back(temp);
        }

        //start algorithm
        string signal[cycles.size()];

        int start = -1, end = -1;
        for(int time = 0; time <= 3600; time++){
            for(int i=0;i<cycles.size();++i) {
                signal[i] = get_signal(time, signal[i], cycles[i]);
            }

            bool all_green = true;
            for(int i=0;i<cycles.size();++i) {
                if(start == -1 && signal[i] == "yellow") {
                    start = time;
                }

                all_green = start != -1 && all_green && (signal[i] == "green");
            }

            if(all_green) {
                end = time;
                break;
            }
        }
        if(start == -1 || end == -1) {
            cout<<"Set "<<set<<" is unable to synch after one hour."<<endl;
        } else {
            int mins = end/60;
            int secs = end%60;
            cout<<"Set "<<set<<" synchs again at "<<mins<<" minute(s) and "<<secs<<" second(s) after all turning green."<<endl;
        }
    }

    return 0;
}