//AtCoder ABC047 A - キャンディーと2人の子供 / Fighting over Candies
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
    vector<int> abc(3);
    for(auto&& d:abc){
        cin>>d;
    }
    sort(abc.begin(),abc.end(), greater<int>());
    cout<<(abc[0]==abc[1]+abc[2]?"Yes":"No")<<endl;
    return 0;
}