//AtCoder ABC054 A - One Card Poker
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    int A,B;
    cin>>A>>B;
    int as=A==1?14:A;
    int bs=B==1?14:B;
    if(as==bs){
        cout<<"Draw"<<endl;
    }else if(as>bs){
        cout<<"Alice"<<endl;
    }else{
        cout<<"Bob"<<endl;
    }
    return 0;
}