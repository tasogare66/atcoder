//ABC012 C - 九九足し算
#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin>>N;
    int sum = 0;
    for (int i=1;i<=9;++i) {
        for (int j=1;j<=9;++j) {
			sum += i * j;
		}
    }
    int diff = sum - N;
    for (int i=1;i<=9;++i) {
        for (int j=1;j<=9;++j) {
			if (diff == i*j) {
                cout<<i<<" x "<<j<<endl;
            }
		}
    }
    return 0;
}