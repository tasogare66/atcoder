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
    std::vector<Info> l0;
    l0.reserve(ss.length());
    for (int i=0; i< S.size(); ++i) {
        if (ss[i] != S[i]) {
            l0.emplace_back(i,S[i]);
        }
    }
    //違うのだけ並べ替える,並べかえるのを決める
    //0,小さいもじ
    //1,先頭
    std::vector<Info*> lpos; //順番
    std::vector<Info*> lchr; //小さい文字
    for(auto& info:l0){
        lpos.push_back(&info);
    }
    lchr = lpos;//copy
	std::sort(lchr.begin(), lchr.end(), [](const Info *l, const Info *r) {
		if(l->ch == r->ch) return (l->pos < r->pos);
		return (l->ch < r->ch);
	});
	int pc = 0, pp = 0;
	std::vector<Info*> lss; //ならべかえるリスト
	for(int i = 0; i < K; ++i) {
		if (i%2==0) {
            //小さい文字
            for (int j=pc;j<lchr.size();++j) {
				pc = j;
                if (lchr[j]->use==false) {
                    lchr[j]->use=true;
                    lss.push_back(lchr[j]);
					break;
				}
			}
        } else {
            //先頭
            for (int j=pp;j<lpos.size();++j) {
				pp = j;
				if (lpos[j]->use==false) {
                    lpos[j]->use=true;
                    lss.push_back(lpos[j]);
					break;
				}
            }
		}
    }    
    //lssをならべかえる
    auto lss_p=lss;
	std::sort(lss.begin(), lss.end(),
			  [](const Info* l, const Info* r) { return (l->ch < r->ch); });
	std::sort(lss_p.begin(), lss_p.end(),
			  [](const Info* l, const Info* r) { return (l->pos < r->pos); });
    for (int i=0;i<lss.size();++i) {
		char ch = lss[i]->ch;
        int pos = lss_p[i]->pos;
        S[pos]=ch;
	}
    cout<<S<<endl;
    return 0;
}