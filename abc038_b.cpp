//AtCoder ABC038 B - ディスプレイ
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
    int h1,w1;
    int h2,w2;
    cin>>h1>>w1;
    cin>>h2>>w2;
    int ans=0;
    if (h1==h2||h1==w2){
		ans = 1;
	}
    if (w1==h2||w1==w2){
        ans=1;
    }
    cout<<(ans?"YES":"NO")<<endl;
    return 0;
}