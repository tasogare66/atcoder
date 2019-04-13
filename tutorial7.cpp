//ABC088B - Card Game for Two
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    std::vector<int> atbl;
    atbl.resize(n);
    for (auto& a: atbl){
        cin >> a;
    }
    std::sort(atbl.begin(), atbl.end(), std::greater<int>());
    int alice = 0;
    int bob = 0;
    for (int i = 0; i < atbl.size(); ++i)
    {
        if (i % 2 == 0)
        {
            alice += atbl[i];
        }
        else
        {
            bob += atbl[i];
        }
    }
    cout<<(alice-bob)<<endl;
}