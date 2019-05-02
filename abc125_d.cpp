//ABC125 D - Flipping Signs
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int64_t> atbl(n);
    int64_t fnum=0;
    int64_t min_val=INT64_MAX;
    int64_t idx=0;
    int i=0;
    for(auto&a:atbl){
		cin >> a;
        if(a<0) ++fnum;
        if (min_val > abs(a)) {
            min_val = abs(a);
            idx=i;
        }
        ++i;
	}
    int64_t sum=0;

    if (fnum%2) { //odd
        for(int i=0;i<atbl.size();++i){
            if (i==idx) {
                sum -= abs(atbl[i]);
            } else {
				sum += abs(atbl[i]);
			}
        }
	} else {
        //even
        for(auto&a:atbl){
			sum += abs(a);
		}
    }
    cout<<sum<<endl;
	return 0;
}