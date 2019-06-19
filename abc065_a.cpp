//AtCoder ABC065 A - Expired?
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll x,a,b;
    cin>>x>>a>>b;
    if(a+x<b) {
        cout<<"dangerous"<<endl;
    } else if(a>=b){
        cout<<"delicious"<<endl;
    } else {
        cout<<"safe"<<endl;
    }
    return 0;
}