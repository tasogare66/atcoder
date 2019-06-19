//AtCoder ABC130
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

/*
引数
string s : 文字列
string t : パターン
返り値
int : 左から探索して初めて登場する箇所(見つからなかった場合は-1)
*/
int bm(vector<ll> s, vector<ll> t)
{
  int n = s.size();
  int m = t.size();
  map<char,int> f;
  for(int i=0; i<m; i++) f[t[i]] = m-1-i;
  int p = m-1;
  while(p<n)
  {
    int k = m-1;
    while(k >= 0 && t[k] == s[p]) {k--; p--;}
    if(k == -1) return p+1;
    else
    {
      if(f.find(s[p])==f.end()) p += m;
      else p += max(f[s[p]],m-k);
    }
  }
  return -1;
}
// int main()
// {
//   string s, t; cin >> s;
//   while(cin >> t) cout << bm(s,t) << endl;
//   return 0;
// }

int main() {
#if LOCAL&01
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N,M;
    cin>>N>>M;
    vector<ll> stbl(N);
    vector<ll> ttbl(M);
    for(auto&& s:stbl){
        cin>>s;
    }
    for(auto&& t:ttbl){
        cin>>t;
    }

    for(ll i=0;i<stbl.size();++i){
        for(ll j=2;j<stbl.size();++j){
			std::vector<ll> tmp(j); // ちゃんと確保しておくこと
			std::copy(stbl.begin()+i, stbl.begin()+j, tmp.begin());
            bm(ttbl, tmp);
        }
    }

    return 0;
}