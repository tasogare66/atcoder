//Tenka1 Programmer Beginner Contest 2019
//A - On the Way
#include <bits/stdc++.h>
using namespace std;
template<size_t SIZE, class T> inline size_t array_size(T (&arr)[SIZE]) {
    return SIZE;
}
int main() {
    int A,B,C;
    cin>>A>>B>>C;
    if (A < C && C < B) {
        cout<<"Yes"<<endl;
    } else if (B < C && C < A) {
        cout<<"Yes"<<endl;
    } else {
        cout<<"No"<<endl;
    }
    return 0;
}