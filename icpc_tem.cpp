//#pragma GCC optimize "trapv"
#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< long long > vll;
typedef pair< int,int > ii;
typedef long long ll;
typedef pair <ll,ll> pll;

typedef long double ld;
typedef unsigned long long ull;
#define sz(a) int((a).size())
#define pb push_back
#define mp  make_pair
#define pll pair <ll,ll>
#define mod 1000000007
#define mod2 998244353
#define all(c) c.begin(),c.end()
#define rep(i,n) for (int i = 0; i <(n); i++)
#define rep2(i, a, b) for (int i = (a); i < int(b); i++)
#define repn(i,a,b)   for(int i=a;i>=b;i--)
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define Yes cout<<"Yes\n"
#define No cout<<"No\n"
#define nl "\n"
#define ff first
#define ss second 
#define eps 0.0000001
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr <<"("<<__LINE__<<")"<<endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


//common file for PBDS
#include<ext/pb_ds/assoc_container.hpp>
//including tree_order_statistics_node_update
#include<ext/pb_ds/tree_policy.hpp>
//namespace
using namespace __gnu_pbds;
template<typename T>
#define o_set(T) tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// mersene prime 19937 RNG

  
ll gcd (ll a, ll b);
unsigned long long factorial[2000007]; 
//___________________________________________
 unsigned long long power(unsigned long long x,long long y,int p)
{unsigned long long res=1;x=x%p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}
return res;}
//__________________________________________
unsigned long long modInverse(unsigned long long n,int p)
{return power(n,p-2,p);}
//_____________________________________________
unsigned long long nc(unsigned long long n,int r,int p)
{if(r==0)
return 1;return(factorial[n]*modInverse(factorial[r],p)%p*modInverse(factorial[n-r],p)%p)%p;}

ll gcd(ll a, ll b){
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
 
ll dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
 

ll spf[1000005];
ll lcm(ll a,ll b){
    return (a/gcd(a,b))*b;
}

const int N = 1000000;
vll pr;
void sieve(){
    spf[1]=0;
    for(ll i=2;i<=N;i++){
        
        if(spf[i]==0){
            //cout<<i<<endl;
            spf[i]=i;
            pr.pb(i);
        }
        for(ll j=0;j<(ll)pr.size() && pr[j]<=spf[i] && i*pr[j]<=N;++j){
            spf[i*pr[j]]= pr[j];
        }
    }
   

}

const int MA=200005;


ll bit[MA+2];

void update(int i , ll x){
    for(i;i<=MA;i+=(i&(-i))){
        bit[i] +=x;
    }
}
ll BITsu(int i){
    ll res = 0;
    for(i;i>0;i-=(i&(-i))){
        res+=bit[i];
    }
    return res;
}

ll rangeBITsum(int i,int j){
    return BITsu(j) - BITsu(i-1);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    freopen("error.txt","w",stderr);
    #endif
    int T=1;
	
	
    
     /*     factorial[0] = 1; 
for (int i = 1; i <= 2000004; i++) {
    factorial[i] = (factorial[i - 1] * i) % mod; 
}  */
    //cin>>T;
  
   //Google,FB 
   //sieve();
    //cout << fixed << setprecision(12);
    while(T--){
          
      
    }
    
   return 0;
}

// Check the order of index while substracitng them
// Overflow - constraints
// create extra p[0] or s[n+1] , for prefix and suffix sums
// check the way in which input is given 
