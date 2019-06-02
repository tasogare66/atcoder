//AtCoder ABC043 A - キャンディーとN人の子供イージー / Children and Candies (ABC Edit)s
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
    int N;
    cin>>N;
    int ans=0;
    for(int i=1;i<=N;++i){
		ans += i;
	}
    cout<<ans<<endl;
    return 0;
}