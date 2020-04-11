//https://atcoder.jp/contests/abc014/tasks/abc014_3
//ABC014 C - AtColor
//C - AtColor
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    int st,ed;
    int col_max = 1000000;
#if LOCAL&0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    cin>>n;
#if 1
    //いもす
    vector<int> numtbl(col_max+2,0);
    for (int i=0;i<n;++i) {
        cin>>st;
        cin>>ed;
        ++numtbl[st];
        numtbl[ed+1]--;
    }
    int ans=0;
    int val=0;
    for (auto n:numtbl) {
        val += n;
        ans = std::max(ans,val);
    }
    cout<<ans<<endl;
#else
    vector<int> numtbl(col_max+1,0);
    for (int i=0;i<n;++i) {
        cin>>st;
        cin>>ed;
        while (st <= ed) {
			++numtbl[st];
			++st;
        }
    }
    int max=0;
    for (auto n:numtbl) {
        if(max < n){
            max = n;
        }
    }
    cout<<max<<endl;
#endif
    return 0;
}