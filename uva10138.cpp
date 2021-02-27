#include<bits/stdc++.h>
#define DEBUG

using namespace std;

void ignore_lines(int n) {
    while(n--)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
struct Data {
    string time;
    string type;
    int dist;
};
class Compare {
    public:
    bool operator() (Data &d1, Data &d2) {
        return d1.time > d2.time;
    }
};
double compute_cost(const Data *enter, const Data *exit, vector<int> &cost_vec) {
    int dist = abs(exit->dist - enter->dist);
    int hour = stoi(enter->time.substr(6,2));
    return (dist * cost_vec[hour])/100.0 + 1;
}
double compute_total_cost(priority_queue<Data, vector<Data>, Compare> &pq, vector<int> &cost_vec) {
    Data *enter = nullptr;
    Data *exit = nullptr;
    double total_cost = 0;
    while(!pq.empty()) {
        Data *data = new Data(pq.top());
        pq.pop();

        if(data->type == "exit" && enter != nullptr) {
            exit = data;
            total_cost += compute_cost(enter, exit, cost_vec);
            
            delete enter;
            delete exit;
            enter = exit = nullptr;
        } else if(data->type == "enter") {
            enter = data;
        } else {
            delete data;
        }
    }
    total_cost += 2; //account charge
    return total_cost;
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
    int t;
    cin>>t;
    ignore_lines(2);

    while(t--) {
        vector<int> cost_vec(24);
        for(int i=0;i<24;++i) {
            cin>>cost_vec[i];
        }
        ignore_lines(1);
        unordered_map<string, priority_queue<Data, vector<Data>, Compare>> data_map;
        unordered_map<string, double> total_cost_map;
        while(1) {
            string input;
            getline(cin, input);

            if(input.size()==0) break;

            stringstream ss(input);
            string license;
            Data data;
            ss>>license>>data.time>>data.type>>data.dist;

            if(data_map.find(license) == data_map.end()) {
                data_map[license] = priority_queue<Data, vector<Data>, Compare>();
            }
            data_map[license].push(data);
        }

        for(auto entry : data_map) {
            total_cost_map[entry.first] = compute_total_cost(entry.second, cost_vec);
        }
        vector<pair<string, double>> total_cost_vec(total_cost_map.begin(), total_cost_map.end());
        sort(total_cost_vec.begin(), total_cost_vec.end());

        for(auto p : total_cost_vec) {
            if(p.second > 3) {
                cout<<p.first<<" $"<<fixed<<setprecision(2)<<round(p.second * 100)/100<<endl;
            }
        }
        cout<<(t?"\n":"");

    }
    
    
    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}