//AtCoder ABC042 A - 和風いろはちゃんイージー / Iroha and Haiku (ABC Edition)
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
	vector<int> abc(3);
    cin>>abc[0]>>abc[1]>>abc[2];
    sort(abc.begin(),abc.end());
    if(abc[0]==5 && abc[1]==5&& abc[2]==7){
        cout<<"YES"<<endl;
    } else{
		cout << "NO" << endl;
	}
	return 0;
}