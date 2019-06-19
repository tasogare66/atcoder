//AtCoder ABC060 B - Choose Integers
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    int A,B,C;
    cin>>A>>B>>C;
    bool ans=false;
    for(int i=1;i<=B;++i){
        if(i*A%B==C) {
            ans=true;
            break;
        }
    }
    cout<<(ans?"YES":"NO")<<endl;
    return 0;
}