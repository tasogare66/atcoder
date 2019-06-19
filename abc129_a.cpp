//AtCoder ABC129
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
	vector<ll> tbl(3);
    cin>>tbl[0]>>tbl[1]>>tbl[2];
    sort(tbl.begin(),tbl.end());
    cout<<tbl[0]+tbl[1]<<endl;
	return 0;
}