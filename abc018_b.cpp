//ABC018 B - 文字列の反転
#include <bits/stdc++.h>
using namespace std;
int main() {
    string S;
	int N;
	cin>>S;
    cin>>N;
    for(int i=0;i<N;++i){
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        while(l<r){
            swap(S[l],S[r]);
            l++;
            r--;
        }
    }
    cout<<S<<endl;
    return 0;
}