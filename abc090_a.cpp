//AtCoder ABC090 A - Diagonal String
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    string c[3];
    for(auto&& ci:c){
        cin>>ci;
    }
    cout<<c[0][0]<<c[1][1]<<c[2][2]<<endl;
    return 0;
}