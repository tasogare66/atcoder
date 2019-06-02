//AtCoder ABC043 B - バイナリハックイージー / Unhappy Hacking (ABC Edit)
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
    string s;
    cin>>s;
    string out;
    for(const auto& i:s){
        if(i=='0') out.push_back('0');
        else if(i=='1') out.push_back('1');
        else if(i=='B') {
			if(out.length() > 0)
				out.pop_back();
		}
	}
    cout<<out<<endl;
    return 0;
}