//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll N,Y;
    cin>>N>>Y;
    for(ll a=0;a<=Y/10000;++a){
        for(ll b=0;b<=Y/5000;++b){
            ll c=N-a-b;
            if (c<0)break;;
            ll cy=a*10000+b*5000+c*1000;
            if(cy==Y){
                cout<<a<<" "<<b<<" "<<c<<endl;
                return 0; //終了
            }
        }
    }
    cout<<"-1 -1 -1"<<endl;
    return 0;
}