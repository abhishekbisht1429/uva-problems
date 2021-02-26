#include<bits/stdc++.h>
#define DEBUG

using namespace std;

void ignore_lines(int n) {
    while(n--)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
bool isGene(string &str) {
    return str == "non-existent" ||
           str == "dominant" ||
           str == "recessive";
}
string cal_gene(string &p1_gene, string &p2_gene) {
    if((p1_gene == "dominant" || p2_gene == "dominant") ||
        (p1_gene != "non-existent" && p2_gene != "non-existent")) {

            if( (p1_gene == "dominant" && p2_gene == "dominant") ||
                (p1_gene == "dominant" && p2_gene == "recessive") ||
                (p1_gene == "recessive" && p2_gene == "dominant")) {
                    return "dominant";
                } else {
                    return "recessive";
                }
        } else {
            return "non-existent";
        }
}

string find_gene(string name, unordered_map<string, string> &genes, unordered_map<string, pair<string,string>> &parents) {
    if(genes.find(name) != genes.end()) {
        return genes[name];
    }

    string p1 = parents[name].first;
    string p2 = parents[name].second;

    string p1_gene = find_gene(p1, genes, parents);
    string p2_gene = find_gene(p2, genes, parents);

    return cal_gene(p1_gene, p2_gene);
}

bool comp_entry(pair<string, string> &p1, pair<string, string> &p2) {
    return p1.first < p2.first;
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
    int n;
    cin>>n;
    
    unordered_map<string, string> genes;
    unordered_map<string, pair<string, string>> parents;
    while(n--) {
        string name, rhs;
        cin>>name>>rhs;

        if(isGene(rhs)) {
            genes[name] = rhs;
        } else {
            if(parents.find(rhs) == parents.end()) {
                parents[rhs] = {name, ""};
            } else {
                parents[rhs].second = name;
            }
        }
    }

    for(auto entry : parents) {
        string name = entry.first;
        string gene = find_gene(name, genes, parents);
        genes[name] = gene;
    }

    vector<pair<string, string>> gene_vec(genes.begin(), genes.end());

    sort(gene_vec.begin(), gene_vec.end(), comp_entry);
    for(auto entry : gene_vec) {
        cout<<entry.first<<" "<<entry.second<<endl;
    }

    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}