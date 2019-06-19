//AtCoder ABC070 A - Palindromic Number
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    string N;
    cin>>N;
    ll v0=stoi(N);
    string tmp;
    for(ll i=N.size()-1;i>=0;--i){
        tmp.push_back(N[i]);
    }
    ll v1=stoi(tmp);
    cout<<(v0==v1?"Yes":"No")<<endl;
    return 0;
}