//AtCoder ABC030 A - 勝率計算
#include <bits/stdc++.h>
using namespace std;
using li=int64_t;

int search(li& idx, const vector<li>& t, li hour){
    for (li i=idx;i<t.size();++i){
        if(t[i]>=hour){
            idx=i+1;
            return t[i];
        }
    }
    return -1;
}

int main() {
#if LOCAL&0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    int N,M;
    int X,Y;
    cin>>N>>M;
    cin>>X>>Y;
    vector<li> at(N);
    vector<li> bt(M);
    for(auto&&a:at){
		cin >> a;
	}
    for(auto&&b:bt){
		cin >> b;
	}
    int ans=0;
    li now=0;
    li no_a=0;
    li no_b=0;
    while(true){
        now = search(no_a, at, now);
        if (now<0) break;
        now += X;
        now = search(no_b, bt, now);
        if (now<0) break;
        now += Y;
        ++ans;
    }
    cout<<ans<<endl;
    return 0;
}