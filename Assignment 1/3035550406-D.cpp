#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool CheckDuplicacte(vector <string> vect,string temp){
    for(int j=0; j<vect.size();j++){
        if(vect[j]==temp){
            return false;
        }
    }
    return true;
}

void SolveD () {
    int n;
    cin>>n;
    vector <string> vect;
    
    for (int i=0; i<n; i++){
        string temp;
        cin>>temp;
        if(CheckDuplicacte(vect,temp)){
            vect.push_back(temp);
        }
    }
    cout<<vect.size();
}
int main() {
    SolveD();
    return 0;
}
