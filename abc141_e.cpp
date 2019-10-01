//https://atcoder.jp/contests/abc141/tasks/abc141_e
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

ll calc(string &s, string &t){
  string nt = "";
  ll div2=s.length()/2;
  for(int i=0; i<s.length(); i++) nt += "*"; //ダミー
  nt += t + nt; //文字列tの前後にダミーの文字("*")を入れることで、条件分岐などをなくした

  ll ret = 0;
  for(ll i=0; i<nt.length()-s.length(); i++){
    if (i==s.length()) continue;
    ll tmp = 0;
    ll tmp2 = 0;
    for(ll j=0; j<s.length(); j++){
      if (i+j > div2 && i+j < div2+s.length()+1) continue;
      //if(i==div2+1) tmp = 0;
      if(s[j]==nt[i+j]) tmp++;
      else tmp = 0;
      ret = max(ret, tmp);
      tmp2 = max(tmp2, tmp);
    }
    cout<<nt<<endl;
    REP(ii,i){ cout<<" ";}
    cout<<s<<" "<<tmp2<<","<<i<<endl;
  }
  return ret;
}

int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    string S; cin>>S;

    ll ans = calc(S,S);
    cout<<ans<<endl;

    return 0;
}