//ABC025 C - 双子と○×ゲーム
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;
using Mat=vector<vector<int>>;

int b[2][3]={};
int c[3][2]={};

int calc_score(const Mat& m)
{
    int ret = 0;
    for (int y=0; y<2; ++y) {
		for(int x = 0; x < 3; ++x) {
            if (m[y][x]==1 && m[y+1][x]==1) {
                ret += b[y][x];
            }
		}
	}
	for(int x = 0; x < 2; ++x) {
        for (int y=0; y<3; ++y) {
            if (m[y][x]==1 && m[y][x+1]==1) {
                ret += c[y][x];
            }
        }
	}
    return ret;
}

int search(int cnt,Mat& m,int cur_score){
    if (cnt>=9){
        return cur_score;
    }
    int flag = cnt%2; //0先行,1後攻
    int next_score=(flag==0)?0:INT32_MAX;
    for(int i=0;i<3;++i){
		for(int j = 0; j < 3; ++j) {
            if (m[i][j] != 0) {
				continue; //設定済
			}
            Mat nm=m;
			nm[i][j] = flag + 1;
			cur_score = calc_score(nm);
	        auto ret = search(cnt+1,nm,cur_score);
            if (flag==0){
				next_score = std::max(next_score, ret);
			} else {
				next_score = std::min(next_score, ret);
			}
		}
	}
    return next_score;
}

int main() {
#if LOCAL&01
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    int total_score=0;
    for(int i=0;i<2;++i){
		for(int j = 0; j < 3;++j) {
            int sc;
			cin >> sc;
            b[i][j]=sc;
            total_score+=sc;
		}
	}
    for(int i=0;i<3;++i){
		for(int j = 0; j < 2;++j) {
			int sc;
			cin >> sc;
            c[i][j]=sc;
            total_score+=sc;
		}
	}
    Mat m = Mat(3,vector<int>(3,0));
    int cnt=0;
    int ans = search(cnt,m,0);
    cout<<ans<<endl;
    cout<<total_score-ans<<endl;
	return 0;
}