//ABC009 C - 辞書式順序ふたたび
#include <bits/stdc++.h>
using namespace std;
struct Info {
	Info(int ip, char ic) : pos(ip), ch(ic) {}
	int pos;
	char ch;
    bool use=false;
};
int main() {
    int N, K;
#if 0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    string S;
    cin>>N>>K;
    cin>>S;
    string ss = S; //copy,昇順の文字,これにしたい
    sort(ss.begin(),ss.end());
    //cout<<ss<<endl;
	int n0 = 0, n1 = 0;
	for (int i=0;i<S.size();++i) {
        if (S[i]!=ss[i]){
            ++n0;
        }
        n1 = 0;
        bool flag[S.size()]={};
        for (int j=i+1;j<S.size();++j) {
			bool found = false;
			for (int k=i+1;k<ss.sie();++k) {
                if (S[j] == ss[k] && !flag[k]){
                    flag[k] = true;
                    found=true;
                    break;
                }
            }
			if(!found) n1++; //みつからなかった
		}
        if (n0+n1 > N) {
            break;
        }
    }
    cout<<S<<endl;
    return 0;
}