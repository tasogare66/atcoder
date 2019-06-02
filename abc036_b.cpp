//AtCoder ABC036 B - 回転
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
    int N;
    cin>>N;
    vector<string> ban(N);
    for(auto&& s:ban){
        cin>>s;
    }
    vector<string> ban2=ban;
    for(int y=0;y<N;++y){
		for(int x = 0; x < N; ++x) {
            ban2[y][x]=ban[N-1-x][y];
		}
	}
    for(const auto& b:ban2){
		cout << b << endl;
	}
	return 0;
}