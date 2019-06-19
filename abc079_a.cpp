//AtCoder ABC079 A - Good Integer
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    string N;
    cin>>N;
    bool ans=false;
    for(ll i=0;i<N.size()-2;++i){
        if(N[i]==N[i+1]&&N[i]==N[i+2]){
            ans=true;
            break;
        }
    }
    cout<<(ans?"Yes":"No")<<endl;
    return 0;
}