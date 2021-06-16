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

const double EPS = 1e-9;
const int INF = 2; // it doesn't actually have to be infinity or a big number

int gauss (vector < vector<double> > a, vector<double> & ans) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;

    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if (abs (a[sel][col]) < EPS)
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                double c = a[i][col] / a[row][col];
                for (int j=col; j<=m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }

    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i=0; i<n; ++i) {
        double sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] * a[i][j];
        if (abs (sum - a[i][m]) > EPS)
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return INF;
    return 1;
}

const int o =104;

// 32 times fast implementation for modulo field with use of bitsets 
int gauss1 (vector<bitset<o>> a, int n, int m, bitset<o> & ans) {
    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        for (int i=row; i<n; ++i)
            if (a[i][col]) {
                swap (a[i], a[row]);
                break;
            }
        if (! a[row][col])
            continue;
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row && a[i][col])
                a[i]^= a[row];
        ++row;
    }
    debug(where);
    for(int i=0;i<m;i++){
        if(where[i]!=-1){
            ans[i]= a[where[i]][m];
        }
    }
    for(int i=0;i<n;i++){
        int c=0;
        for(int j=0;j<m;j++){
            if(where[j]!=-1 && a[i][j]){
                c^=ans[j];
            }
        }
        if(c!=a[i][m]){
            //cout<<i<<nl;
            return 0;  // no solution 
        }
    }
    // if any one of where[i] is -1 the we have infinite solutions 
    // code when required

    return 1; // atleast one solution 

        // The rest of implementation is the same as above
      
  
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
	auto start1 = high_resolution_clock::now();
	
    
     /*     factorial[0] = 1; 
for (int i = 1; i <= 2000004; i++) {
    factorial[i] = (factorial[i - 1] * i) % mod; 
}  */
    //cin>>T;
  
//SieveOfEratosthenes(1000001);
   //Google,FB 
   //sieve();
    //cout << fixed << setprecision(12);
    while(T--){
        int p,f;
        cin>>p>>f;
        vi g[p];
        rep2(i,0,f){
            int a,b;
            cin>>a>>b;
            a--;
            b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<bitset<o>> a;
        
        for(int i=0;i<p;i++){
            int no = g[i].size();
            bitset<o> temp;
             //temp[0]=1;
           
           
            if(no&1){
                temp[i]=1;
                for(auto j : g[i]){
                    temp[j]=1;
                }
                temp[p] =0;
            }
            else{
                for(auto j : g[i]){
                    temp[j]=1;
                }
                temp[p]=1;

            }
            //cout<<temp<<nl;
            a.push_back(temp);
        }
        bitset<o> ans;

        int q = gauss1(a,p,p,ans);
        //cout<<q<<nl;
        if(q){
            cout<<"Y\n";
        }
        else{
            cout<<"N\n";
        }
     


      
    }
    
 


    auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
    #ifndef ONLINE_JUDGE
        cerr << "Time: " << duration . count() / 1000 << endl;
    #endif

   return 0;
}



