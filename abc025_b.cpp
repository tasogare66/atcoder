//ABC025 B - 双子とスイカ割り
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;
int main() {
    int N,A,B;
#if LOCAL&0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    cin>>N>>A>>B;
    int p=0;
    for(int i=0;i<N;++i){
        string s;
        int n;
        cin>>s>>n;
        if(n<A){
			n = A;
		} else if(n > B) {
			n = B;
		}
		if (s!="East"){
            n*=-1;
        }
        p += n;
    }
    if (p==0){
		cout << p << endl;
	}else
		cout << (p > 0 ? "East" : "West") << " " << std::abs(p) << endl;
	return 0;
}