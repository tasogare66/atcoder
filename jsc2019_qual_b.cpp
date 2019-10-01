//https://atcoder.jp/contests/jsc2019-qual/tasks/jsc2019_qual_b
//第一回日本最強プログラマー学生選手権-予選-
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
constexpr ll MOD=1e9+7;

template <std::uint_fast64_t Modulus> class modint {
  using u64 = std::uint_fast64_t;

public:
  u64 a;

  constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
  constexpr u64 &value() noexcept { return a; }
  constexpr const u64 &value() const noexcept { return a; }
  constexpr modint operator+(const modint rhs) const noexcept {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint rhs) const noexcept {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint rhs) const noexcept {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint rhs) const noexcept {
    return modint(*this) /= rhs;
  }
  constexpr modint &operator+=(const modint rhs) noexcept {
    a += rhs.a;
    if (a >= Modulus) {
      a -= Modulus;
    }
    return *this;
  }
  constexpr modint &operator-=(const modint rhs) noexcept {
    if (a < rhs.a) {
      a += Modulus;
    }
    a -= rhs.a;
    return *this;
  }
  constexpr modint &operator*=(const modint rhs) noexcept {
    a = a * rhs.a % Modulus;
    return *this;
  }
  constexpr modint &operator/=(modint rhs) noexcept {
    u64 exp = Modulus - 2;
    while (exp) {
      if (exp % 2) {
        *this *= rhs;
      }
      rhs *= rhs;
      exp /= 2;
    }
    return *this;
  }
};
 using mint = modint<MOD>;

void swap(ll *xp, ll *yp) 
{ 
    ll temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
// An optimized version of Bubble Sort 
ll bubbleSort(ll arr[], ll n) 
{ 
    ll cnt=0;
   ll i, j; 
   bool swapped; 
   for (i = 0; i < n-1; i++) 
   { 
     swapped = false; 
     for (j = 0; j < n-i-1; j++) 
     { 
        if (arr[j] > arr[j+1]) 
        { 
           swap(&arr[j], &arr[j+1]); 
           swapped = true; 
           ++cnt;
        } 
     } 
  
     // IF no two elements were swapped by inner loop, then break 
     if (swapped == false) 
        break; 
   } 
    return cnt;
}

ll merge_cnt(vector<ll> &a) {
    int n = a.size();
    if (n <= 1) { return 0; }

    ll cnt = 0;
    vector<ll> b(a.begin(), a.begin()+n/2);
    vector<ll> c(a.begin()+n/2, a.end());

    cnt += merge_cnt(b);
    cnt += merge_cnt(c);

    ll ai = 0, bi = 0, ci = 0;
    // merge の処理
    while (ai < n) {
        if ( bi < b.size() && (ci == c.size() || b[bi] <= c[ci]) ) {
            a[ai++] = b[bi++];
        } else {
            cnt += n / 2 - bi;
            a[ai++] = c[ci++];
        }
    }
    return cnt;
}

int main() {
    #if LOCAL&01
        std::ifstream in("./test/sample-1.in"); //input.txt
        std::cin.rdbuf(in.rdbuf());
    #endif
    ll N,K; cin>>N>>K;
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }
    auto an2=an;
    an2.insert(an2.end(),an.begin(),an.end());

    ll cnt=merge_cnt(an);
    ll cnt2=merge_cnt(an2);
    //ll tmp = bubbleSort(an2.data(),an2.size());
    assert(cnt<=MOD);
    assert(cnt2<=MOD);

    ll fueru=cnt2-cnt*2;

    mint ans=mint{cnt}*mint{K};
    if(K>1){
        auto tmp=mint{K}*mint{K-1}/mint{2};
        //auto tmp=(mint(1)+mint(N-1)*mint(K))/mint(2);
        ans += mint{fueru}*tmp;
    }

    cout<<ans.a<<endl;    
    return 0;
}