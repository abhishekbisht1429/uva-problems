#include<bits/stdc++.h>
#define DEBUG

using namespace std;

void ignore_lines(int n) {
    while(n--)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
struct Employee {
    string title;
    string fName;
    string lName;
    string sAddr;
    string hPhone;
    string wPhone;
    string cBox;
    string dept;
};
bool comp(Employee &e1, Employee &e2) {
    return e1.lName < e2.lName;
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
    ignore_lines(1);
    vector<Employee> vec;
    while(n--) {
        string dept;
        getline(cin, dept);
        while(1) {
            string str;
            getline(cin, str);

            if(str.size() == 0) break;
            str+=",";
            istringstream iss(str);
            Employee emp;
            getline(iss, emp.title, ',');
            getline(iss, emp.fName, ',');
            getline(iss, emp.lName, ',');
            getline(iss, emp.sAddr, ',');
            getline(iss, emp.hPhone, ',');
            getline(iss, emp.wPhone, ',');
            getline(iss, emp.cBox, ',');
            emp.dept = dept;
            vec.push_back(emp);
        }
    }
    sort(vec.begin(), vec.end(), comp); 

    
    for(Employee emp : vec) {
        cout<<"----------------------------------------"<<endl;
        cout<<emp.title<<" "<<emp.fName<<" "<<emp.lName<<endl;
        cout<<emp.sAddr<<endl;
        cout<<"Department: "<<emp.dept<<endl;
        cout<<"Home Phone: "<<emp.hPhone<<endl;
        cout<<"Work Phone: "<<emp.wPhone<<endl;
        cout<<"Campus Box: "<<emp.cBox<<endl;
    }

    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}