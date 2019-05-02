//ABC014 A - けんしょう先生のお菓子配り
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b;
    cin>>a;
    cin>>b;
    auto remains = a % b;
    auto per = a / b;
    if (remains > 0) per+=1;
    cout<<per*b-a<<endl;
    return 0;
}