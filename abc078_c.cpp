//AtCoder ABC078 C - HSI
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll N,M;
    cin>>N>>M;
    ll num=pow(2,M); //回数の期待値、確率の逆数
    ll ans=(1900*M+(N-M)*100)*num; //時間の期待値
    cout<<ans<<endl;
    return 0;
}