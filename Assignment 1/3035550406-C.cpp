
#include <iostream>
#include <string>
using namespace std;

int main() {
    string n;
    cin>>n;
    
    int length= n.length();
    string s[length];
    
    for (int k=0; k<length;k++){
        s[k]=n[k];
    }
    
    if(length%2==1){
        cout<<0;
        return 0;
    }
    
    int leftBracketCounter=0;
    int rightBracketCounter=0;
    int diff;
    for (int i =0; i<length; i++){
        if(s[i]=="("){leftBracketCounter++;}
        if(s[i]==")"){rightBracketCounter++;}
        diff= leftBracketCounter-rightBracketCounter;
        if(diff<0){
            cout<<0;
            return 0;
        }
    }
    if (diff!=0){
        cout<<0;
        return 0;
    }
    
    while(length!=1){
        for (int i=0; i<length;i++){
            if(s[i]=="(" && s[i+1]==")"){
                s[i]="1";
                
                for(int k=i+1; k<length-1;k++){
                    s[k]=s[k+1];
                }
                length--;
                break;
            }
            if(s[i]=="(" && (s[i+1]!="(" && s[i+1]!=")")){
                if(s[i+2]==")"){
                    int t= stoi(s[i+1]) ;
                    t*=2;
                    string stemp = to_string(t);
                    s[i]=stemp;
                    for (int k=i+1; k<length - 2; k++){
                        s[k]=s[k+2];
                    }
                    length= length-2;
                    break;
                }
            }
            if((s[i]!="(" && s[i]!=")")&&(s[i+1]!="(" && s[i+1]!=")")){
                int a= stoi(s[i]) + stoi(s[i+1]) ;
                string stemp = to_string(a);
                s[i]=stemp;
                
                for(int k=i+1; k<length-1;k++){
                    s[k]=s[k+1];
                }
                length--;
                break;
            }
        }
    }
    
    cout<<s[0];
    return 0;
}

