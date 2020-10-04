#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds;
using namespace std;
#define int             long long
#define ld              long double
#define ll              long long
#define pb              push_back
#define fi              first
#define se              second
#define mt              make_tuple
#define endl            '\n'
#define test            int _o_; cin>>_o_; while(_o_--)
#define fast_io         ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define tree            tree <int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update>

const int MAXN = 200064;
const ld eps   = 1e-6;
const int mod  = 1000000007; //998244353// 1e9 + 7
const int inf  = 1000000007; // 1e9 + 7
const int MAX = 8000000000000000064LL;
const int MIN = -8000000000000000064LL;

int fact[1000007]={0};
int spf[(int)(1e7) + 20];
bool prime[(int)((1e7) + 20)];
int gcd(int a,int b){if(b==0)return a; return gcd(b,a%b);}
void sp(int n){spf[1]=1;for(int i=2;i<n;i++)spf[i]=i;for(int i=4;i<n;i+=2)spf[i]=2;for(int i=3;i*i<n;i++){if(spf[i]==i){for(int j=i*i;j<n;j+=i)if(spf[j]==j)spf[j]=i;}}}
void sieve(int n){memset(prime,true,sizeof(prime) );for(int p=2;p*p<=n;p++){if(prime[p]==true)for(int i=p*p;i<=n;i+=p)prime[i]=false;}prime[0]=false;prime[1]=false;}
int xyp(int x,int y){int res=1;while(y>0){if(y%2==1) res=(res*x)%mod;x=(x*x)%mod;y/=2;}return res%mod;}
int inv(int x){return xyp(x,mod - 2);}
int inv_euclid(int a, int m = mod){int m0 = m;int y = 0, x = 1;if (m == 1)return 0;while (a > 1){int q = a / m;int t = m;m = a % m, a = t;t = y;y = x - q * y;x = t;}if (x < 0)x += m0;return x;}
void init() {fact[0]=1;fact[1]=1;for(int i=2;i<1000007;i++)fact[i]=(fact[i-1]*i)%mod;}
int ncr(int n,int r) {int res=1; res=fact[n]; res=(res*(xyp(fact[r],mod-2)))%mod; res=(res*(xyp(fact[n-r],mod-2)))%mod; return res;}
int npr(int n,int r) {int res=1; res=fact[n]; res=(res*(xyp(fact[n-r],mod-2)))%mod; return res; }
bool isp(int a){if(a == 2)return true;if(a == 1)return false;for(int x= 2; x <= sqrt(a) + 1; x++)if(a % x == 0)return false;return true;}
int add(int a, int b){return (a%mod + b%mod + ((MAX)/mod)*mod)%mod;}
int sub(int a, int b){return (a%mod - b%mod + ((MAX)/mod)*mod)%mod;}
int mul(int a, int b){return ((a%mod)*(b%mod) + ((MAX)/mod)*mod)%mod;}
// #define p_set tree< pair<int,int> ,  null_type ,  less<pair<int,int>> ,  rb_tree_tag ,  tree_order_statistics_node_update>
// #define i_set tree< int ,  null_type ,  less< int > ,  rb_tree_tag ,  tree_order_statistics_node_update>
// freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
// int dx[] = {+1, -1, 0, 0};
// int dy[] = {0, 0, +1, -1};

signed main()
{
	fast_io
	test
	{
		
	}
}
