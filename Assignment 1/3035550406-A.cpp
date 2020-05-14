#include <iostream>
#include <string>
using namespace std;

#define SIZE 1000

class Stack{
private:
    int top;
public:
    Stack() {top=-1;};
    int array[SIZE];
    void push(int value);
    int pop();
    bool isEmpty();
};

void Stack::push(int value) {array[++top] = value;}

int Stack::pop()
{   int x = array[top--];
    return x;
}

bool Stack::isEmpty() { return (top < 0);}


void SolveA() {
    string s;
    Stack st;
    // for (int i = 0; i < 1000; i++) {
      while (getline(cin, s)){

        if (s[1]=='o' || s[1]=='O'){
            if(st.isEmpty()){
                cout<<"false";
                exit(1);
            }
            int t= st.pop();
            cout<<t<<" ";

        }
        else {
            st.push(stoi(s.substr(5)));
        }
}
}

int main() {
    SolveA();
    return 0;
}
