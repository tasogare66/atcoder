//AtCoder ABC051 B - Sum of Three Integers
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
    int K,S;
    cin>>K>>S;
    int ans=0;
    for(int x=0;x<=K;++x){
        for(int y=0;y<=K;++y){
            int z=S-x-y;
            if(z>=0&&z<=K) ++ans;
			// for(int z = 0; z <= K; ++z) {
            //     if(x+y+z==S)++ans;
			// }
		}
	}
    cout<<ans<<endl;
    return 0;
}