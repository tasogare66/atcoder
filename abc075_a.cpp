//AtCoder ABC075 A - One out of Three
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    vector<ll> tbl(3);
    cin>>tbl[0]>>tbl[1]>>tbl[2];
    sort(tbl.begin(),tbl.end());
    cout<<(tbl[0]==tbl[1]?tbl[2]:tbl[0])<<endl;
    return 0;
}