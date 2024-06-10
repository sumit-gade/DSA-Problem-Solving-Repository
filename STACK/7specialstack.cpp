#include<iostream>
#include<stack>
using namespace std;

void push(stack<int>& s, int a);
bool isFull(stack<int>& s, int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);

// This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, a;
        cin >> n;
        while(!isEmpty(s)){
            pop(s);
        }
        while(!isFull(s, n)){
            cin >> a;
            push(s, a);
        }
        cout << getMin(s) << endl;
    }
}

int mi = 99999; // taken max value

void push(stack<int>& s, int a){
    if(s.empty()){
        mi = a;
        s.push(a);
    } else {
        int x = a;
        if(a < mi){
            x = 2 * a - mi;
            mi = a;
        }
        s.push(x);
    }
}

bool isFull(stack<int>& s, int n){
    return s.size() == n;
}

bool isEmpty(stack<int>& s){
    return s.empty();
}

int pop(stack<int>& s){
    if(s.empty()) return -1;
    int top = s.top();
    s.pop();
    if(top < mi){
        int prevMin = mi;
        mi = 2 * mi - top;
        return prevMin;
    }
    return top;
}

int getMin(stack<int>& s){
    return mi;
}
