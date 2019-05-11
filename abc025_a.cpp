//ABC025 A - 25個の文字列
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;
int main() {
    string S;
    int N;
    cin>>S>>N;
    vector<string> names;
    names.reserve(25);
    for(int i=0;i<S.length();++i){
        for(int j=0;j<S.length();++j){
            string tmp;
            tmp += S[i];
            tmp += S[j];
			names.push_back(tmp);
		}
    }
    sort(names.begin(),names.end());
    cout<<names[N-1]<<endl;
    return 0;
}