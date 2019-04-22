//ABC009 C - 辞書式順序ふたたび
#include <bits/stdc++.h>
using namespace std;
#define CHR_ID(_in_c) ((_in_c)-'a')
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
    //使用文字しらべ
    vector<char> ctbl(26,0);
    for (int i=0;i<S.size();++i){
        ++ctbl[CHR_ID(S[i])];
	}
    //
    string ans="";
    bool flag[S.size()] = {};
    int n0 = 0;
    for (int i=0;i<N;++i) {
        for (char chr='a'; chr<='z';++chr){
			if (ctbl[CHR_ID(chr)]) {
				auto tmp = ctbl; //copy
                int n1 = (S[i] == chr) ? 0 : 1;
                --tmp[CHR_ID(chr)];
				for(int n = i + 1; n < N; ++n) {
					if (tmp[CHR_ID(S[n])] > 0)
						tmp[CHR_ID(S[n])]--;
					else
						++n1;
				}
				if (n1 <= K) { //みつかった
					ans += chr;
					--ctbl[CHR_ID(chr)];
					if(S[i] != chr)
						--K;
					break;
				}
            }
        }
#if 0
        for (int j=0;j<N;++j) {
			if(flag[j]) continue; //使ってる?
			char c = ss[j];
			//一致数の確認
            int n0_tmp=n0;
            int n1=0;
			if(S[i] != c) {
				n0_tmp+=1;
            }
            

			if (n0_tmp + n1 < K) {
				ans = ans + c;
				flag[j] = true; //使った
                n0 = n0_tmp;
				break;
			}
		}        
#endif
    }
    cout<<ans<<endl;
    return 0;
}