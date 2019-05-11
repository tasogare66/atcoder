// AGC020 A - Move and Win
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;
int main() {
    lli k;
    vector<lli> atbl(k);
    cin>>k;
    for(auto&& a: atbl){
        cin>>a;
    }
    revrse(atbl);
    if (atbl[0] != 2) {
        cout<<-1<<endl;
        return 0; //exit
    }
    lli min = 2;
    lli max = 3;
    for (lli i=1;i<atbl.size(); ++i) {
        auto a=atbl[i];
        min=a;
        max=atbl[i]*2-1;
    }

    return 0;
}