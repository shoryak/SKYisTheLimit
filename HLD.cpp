//#pragma GCC optimize "trapv"
#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
#define vi vector< int >
#define vvi vector< vi > 
#define vll vector< long long > 
#define ll long long
#define pll pair <ll,ll>
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
#define vout(v) for(auto &x : v){cout << x << " ";}cout << nl;
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

ll gcd(ll a, ll b){if (b == 0)return a;else return gcd (b, a % b);}
 unsigned long long power(unsigned long long x,long long y,int p)
{unsigned long long res=1;x=x%p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}
return res;}
//__________________________________________
unsigned long long modInverse(unsigned long long n,int p)
{return power(n,p-2,p);}
//common file for PBDS
// #include<ext/pb_ds/assoc_container.hpp>
// //including tree_order_statistics_node_update
// #include<ext/pb_ds/tree_policy.hpp>
// //namespace
// using namespace __gnu_pbds;
// template<typename T>
// #define o_set(T) tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set 

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// mersene prime 19937 RNG  
// unsigned long long factorial[2000007]; 
// //___________________________________________
const ll N = 200010;
typedef long long item;
ll val[N];
struct segtree{
    ll size;
    vector<item> values;
    item NEUTRAL_ELEMENT = LLONG_MIN;
    item single(ll v){
        return v;
    }
    item merge(item a, item b){
        return max(a, b);
    }
    void init(ll n){
        size = 1;
        while(size < n)size*=2;
        values.assign(2*size, 0LL);
    }
    void build(vll &a, ll x, ll lx, ll rx){
        if(rx - lx == 1){
            if(lx < sz(a)){
                values[x] = single(val[a[lx]]);
            }
            return;
        }
        ll m = (lx + rx)/2;
        build(a, 2*x+1, lx, m);
        build(a, 2*x+2, m, rx);
        values[x] = merge(values[2*x+1], values[2*x + 2]);
    }
    void build(vll &a){
        build(a,0,0,size);
    }
    void set(ll i, ll v, ll x, ll lx, ll rx){
        if(rx - lx == 1){
            values[x] = single(v);
            return;
        }
        ll m = (lx + rx)/2;
        if(i < m){
            set(i, v, 2 * x + 1, lx, m);
        } else{
            set(i, v, 2 * x + 2, m, rx);
        }
        values[x] = merge(values[2*x+1], values[2*x + 2]);
    }
    void set(ll i, ll v){
        set(i, v, 0, 0, size);
    }
    item calc(ll l, ll r, ll x, ll lx, ll rx){
        if(lx >= r || l >= rx)return NEUTRAL_ELEMENT;
        else if(lx >= l && rx <= r)return values[x];
        
        ll m = (lx + rx)/2;
        item v1 = calc(l, r, 2*x + 1, lx, m);
        item v2 = calc(l, r, 2*x + 2, m, rx);
        return merge(v1, v2);
            
    }
    item calc(ll l, ll r){
        return calc(l, r, 0, 0, size);
    }
};
vll g[N], chain[N];
ll color[N]; //chain color
ll cidx[N]; //index in the chain
ll lvl[N]; //distance from the root
ll sz[N]; // subtree size
ll par[N];// parent
vll chain_colors;
segtree st[N];
void dfs(ll u, ll p, ll d){
    par[u] = p;
    lvl[u] = d;
    sz[u] = 1;
    for(ll v : g[u]){
        if(v != p){
            dfs(v, u, d + 1);
            sz[u] += sz[v];
        }
    }
}
void dfs_hld(ll u, ll p){
    ll best = -1;
    for(ll v: g[u]){
        if(v == p)continue;
        if(best == -1 || sz[best] < sz[v]){
            best = v;
        }
    }
    if(best == -1)return;
    color[best] = color[u];
    chain[color[u]].pb(best);
    cidx[best] = cidx[u] + 1;
    dfs_hld(best, u);
    for(ll v: g[u]){
        if(v == p || v == best)continue;
        color[v] = v;
        chain_colors.pb(v);
        cidx[v] = 1;
        chain[v].pb(v);
        dfs_hld(v, u);
    }
}
// Either {color, start_chain_idx, end_chain_idx} or {-1, u, v}(jump from vertex u to vertex v)
vector <array<ll, 3>> segments(ll x, ll y){

    vector < array<ll, 3> > xseg;
    vector < array<ll, 3> > yseg;

    while (true) {
        if (color[x] == color[y]) {
            xseg.pb({color[x], cidx[x], cidx[y]});
            break;
        }
        if (lvl[color[x]] < lvl[color[y]]) {
            yseg.pb({color[y], 1, cidx[y]});
            //yseg.pb({-1, par[color[y]], color[y]});
            y = par[color[y]];  
        } else {
            xseg.pb({color[x], cidx[x], 1});
            //xseg.pb({-1, color[x], par[color[x]]});
            x = par[color[x]];
        }
    }

    reverse(all(yseg));
    for (auto a: yseg){
        xseg.pb(a);
    }

    return xseg;
}

void solve(){
    ll n, q;
    cin >> n >> q;
    rep2(i, 1, n + 1){
        cin >> val[i];
    }
    rep(i, n - 1){
        ll u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, 0, 0);
    chain_colors.pb(1);
    color[1] = 1;
    chain[1].pb(1);
    cidx[1] = 1;
    dfs_hld(1, 0);
    for(ll x: chain_colors){
        //vout(chain[x]);
        st[x].init(chain[x].size());
        st[x].build(chain[x]);
    }
    rep(i, q){
        ll ty;
        cin >> ty;
        if(ty == 1){
            ll s, x;
            cin >> s >> x;
            st[color[s]].set(cidx[s] - 1, x);
        } else {
            ll a, b;
            cin >> a >> b;
            vector < array<ll, 3> > aa = segments(a, b);
            ll res = -1;
            for(auto z: aa){
                //cout << z[0] << " " << z[1] << " " << z[2] << nl;
                res = max(res, st[z[0]].calc(min(z[1], z[2]) - 1, max(z[2], z[1])));
            }
            cout << res << " ";
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE 
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    // freopen("error.txt","w",stderr);
    // #endif
    int TC=1;
    //cin >> TC;
    rep(TT, TC){
        solve();      
    }    
    return 0;
}
// Check the order of index while substracitng them
// Overflow - constraints
// create extra p[0] or s[n+1] , for prefix and suffix sums
// check the way in which input is given 
