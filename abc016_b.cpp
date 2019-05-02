//ABC016 B - A±B Problem
#include <bits/stdc++.h>
using namespace std;
int main() {
    int A,B,C;
    cin>>A>>B>>C;
    if (A+B==C&&A-B==C){
        cout<<"?"<<endl;
    }else if(A+B==C){
        cout<<"+"<<endl;
    }else if(A-B==C){
        cout<<"-"<<endl;
    }else{
        cout<<"!"<<endl;
    }
    return 0;
}