//AtCoder ABC110 C - String Transformation
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
    string S,T; cin>>S>>T;
    unordered_map<char,char> tbl; //変換 b,a
    unordered_map<char,char> tbl2; //a,b
    unordered_set<char> fixed; //決まったやつ
    bool ans=true;
    for(ll i=0;i<S.size();++i){
        vector<char> sw(2);
        auto a=S[i];
        auto b=T[i];
        auto itb=tbl.find(b);  //tが一致でsが違う場合不可
        if(itb!=tbl.end()&&itb->second!=a){
            ans=false;
            break;
        }
        auto ita=tbl2.find(a);
        if(ita!=tbl2.end()&&ita->second!=b){
            ans=false;
            break;
        }
        tbl.insert(make_pair(b,a));
        tbl2.insert(make_pair(a,b));
        //tbl.insert(make_pair(a,b));
        //tbl.insert(make_pair(b,a));
        //fixed.insert(b);
    }   
    cout<<(ans?"Yes":"No")<<endl;
    return 0;
}