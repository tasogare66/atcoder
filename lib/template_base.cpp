//##template
//key:main function
//prefix:m
//description:main function
//$1
#include <bits/stdc++.h>
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif
using namespace std;
using ll=long long;
const ll LINF = 0x1fffffffffffffff;
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
template<class T>bool chmax(T &a, const T &b) {if (a<b) { a=b; return 1; } return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) { a=b; return 1; } return 0;}
int main() {
  
  return 0;
}
//##


void temp(){
//##template
//key:input_text
//prefix:input
//description:input text
#if LOCAL&01
  std::ifstream in("./test/sample-1.in");
  //std::ifstream in("./input.txt");
  std::cin.rdbuf(in.rdbuf());
#else
  cin.tie(0);
  ios::sync_with_stdio(false);
#endif
//##

//##template
//key:cout for float
//prefix:cout_float
//description:float用のcout
  cout<<fixed<<std::setprecision(10)
//##
  ;

}//temp()


//##template
//key:mod primary
//prefix:mod
//description:mod primary number
constexpr ll MOD=1e9+7;
//##


//##template
//key:string split
//prefix:split
//description:string split
std::vector<std::string> split(const std::string& input, char delimiter){
  std::istringstream stream(input);
  std::string field;
  std::vector<std::string> result;
  while (std::getline(stream, field, delimiter)) {
    result.push_back(field);
  }
  return result;
}
//##

//##template
//key:least common multiple
//prefix:lcm
//description:least common multiple
ll lcm(ll num1,ll num2){
  //return num1 / __gcd(num1,num2) * num2;
  return num1 / std::gcd(num1,num2) * num2;
}
//##

//##template
//key:combination
//prefix:combination
//description:nCkの組み合わせ列挙
void recursive_comb(vector<ll>& indexes, ll s, ll rest, std::function<void(vector<ll>&)> f) {
  if (rest == 0) {
    f(indexes);
  } else {
    if (s < 0) return;
    recursive_comb(indexes, s - 1, rest, f);
    indexes.at(rest - 1) = s;
    recursive_comb(indexes, s - 1, rest - 1, f);
  }
}
// nCkの組み合わせに対して処理を実行する
void foreach_comb(ll n, ll k, std::function<void(vector<ll>&)> f) {
  vector<ll> indexes(k);
  recursive_comb(indexes, n - 1, k, f);
}
//foreach_comb(N-1, 2, [&](vector<ll>& indexes) {
//  dump(indexes[0],indexes[1]);
//});
//##


//##template
//key:matrix
//prefix:matrix
//description:matrix vector2重配列
template< typename T >
using Matrix = vector< vector< T > >;
template< typename T>
Matrix<T> make_matrix(ll y, ll x, T v={}){
	return Matrix<T>(y, vector<T>(x,v));
}
//##
void test(){
  Matrix<ll> t=make_matrix<ll>(4,3);
}


//##template
//key:deg2rad
//prefix:deg2rad
//description:degree to radian, radian to degree
double deg2rad(double deg){
  return deg*M_PI/180.0;
}
double rad2deg(double rad){
  return rad*180.0/M_PI;
}
//##
