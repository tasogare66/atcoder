//AtCoder ABC059 B - Comparison
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    string A,B; //数字
    cin>>A>>B;
    if (A==B){
        cout<<"EQUAL"<<endl;
    } else if (A.size()==B.size()) {
        for(int i=0;i<A.size();++i){
            if(A[i]==B[i])continue;
            cout<<(A[i]>B[i]?"GREATER":"LESS")<<endl;
            break;
        }
    } else {
        cout<<(A.size()>B.size()?"GREATER":"LESS")<<endl;
    }
    return 0;
}