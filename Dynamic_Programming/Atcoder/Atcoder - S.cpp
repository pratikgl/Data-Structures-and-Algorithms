#include <bits/stdc++.h>
using namespace std;
/*
#pragma GCC optimize("Ofast,03")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
*/
#define    boost        ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define    nl           "\n"
#define    ll           long long
#define    pb           push_back
#define    mpr          make_pair
#define    fr(i,a,n)    for(ll i=a;i<n;++i)
#define    fr0(i,n)     for(ll i=0;i<n;++i)
#define    pii          pair<ll, ll>
#define    mem(a)       memset(a,0,sizeof(a))
#define    F            first
#define    S            second
#define    sp           ' '
#define    vi           vector<ll>
#define    vii          vector<pair<ll, ll>>
#define    all(a)       a.begin(), a.end()

/*
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree <ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
*/

void fio()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

template<typename T> void TIME(T start, T end)
{
#ifndef ONLINE_JUDGE
	double tt =  chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	cout << "\nExecuted in: " << fixed << tt * 1e-9 << setprecision(9) << " sec";
#endif
}

///----------------------------- | Debugging Starts | --------------------------------------///

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x...)  cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

///----------------------------- | Debugging Ends | --------------------------------------///

#define int long long //change int main to int32_t main

///----------------------------- | FUNCTIONS | --------------------------------------///

bool sortbysec(const pii &a, const pii &b) {return a.S < b.S;}
bool compBySec(const pii &a, const pii &b) {return a.S == b.S ? a.F < b.F : a.S < b.S;}
/*
const int N = 2e5 + 5;

vector<int> adj[N];      // mem(adj);
vector<bool> visited(N); // fill(all(visited), 0)
//vector<int> val(N);    // val.assign(N, 1)
//vector<int> depth(N);
//vector<int> parent(N);
//vector<int> child(N);

void dfs(int v)
{
	visited[v] = true;
	for (int u : adj[v])
	{
		if (!visited[u])
		{
			//parent[u] = v;
			//depth[u] = depth[v] + 1;
			dfs(u);
			//child[v] += child[u] + 1;
		}
	}
}
*/

// left shift << multiply by 2
// right shift >> divide by 2

///----------------------------- | START FROM HERE | --------------------------------------///
/*
const int N = 1e4 + 5;
int dp[N][105][2];
int mod = 1e9 + 7;
// https://atcoder.jp/contests/dp/submissions/18607617
// https://www.youtube.com/watch?v=FAQxdm0bTaw&t=11868s
// dp[][][0] -> could be iterable to 1 to 9
// dp[][][1] -> last digit (the number sfter this wont be in the range)

void solve()
{
	string k; cin >> k;
	int d; cin >> d;
	int n = k.size();
	dp[0][0][1] = 1;

	for (int i = 0; i < n; ++i) { // iterating from most significant number to the least significant one
		for (int sum = 0; sum < d; ++sum) { // iterating from 0 to all the achievable values of summation of the string
			for (int digit = 0; digit <= 9; ++digit) { // iterating on all the posiible values of digits
				if (digit < k[i] - '0') dp[i + 1][(sum + digit) % d][0] += dp[i][sum][1];
				if (digit == k[i] - '0') dp[i + 1][(sum + digit) % d][1] += dp[i][sum][1];
				dp[i + 1][(sum + digit) % d][0] += dp[i][sum][0];
				dp[i + 1][(sum + digit) % d][1] %= mod, dp[i + 1][(sum + digit) % d][0] %= mod;
			}
		}
	}
	cout << (dp[n][0][0] + dp[n][0][1] + mod - 1) % mod;
}
*/


const int N = 1e4 + 5;
int dp[105][2];
int mod = 1e9 + 7;
// https://atcoder.jp/contests/dp/submissions/18607617
// https://www.youtube.com/watch?v=FAQxdm0bTaw&t=11868s
// dp[][][0] -> could be iterable to 1 to 9
// dp[][][1] -> last digit (the number sfter this wont be in the range)

void solve()
{
	string k; cin >> k;
	int d; cin >> d;
	int n = k.size();
	dp[0][1] = 1;

	for (int i = 0; i < n; ++i) { // iterating from most significant number to the least significant one
		int new_dp[105][2]; mem(new_dp);
		for (int sum = 0; sum < d; ++sum) { // iterating from 0 to all the achievable values of summation of the string
			for (int digit = 0; digit <= 9; ++digit) { // iterating on all the posiible values of digits
				if (digit < k[i] - '0') new_dp[(sum + digit) % d][0] += dp[sum][1];
				if (digit == k[i] - '0') new_dp[(sum + digit) % d][1] += dp[sum][1];
				new_dp[(sum + digit) % d][0] += dp[sum][0];
				new_dp[(sum + digit) % d][1] %= mod, new_dp[(sum + digit) % d][0] %= mod;
			}
		}
		fr0(j, 105) dp[j][0] = new_dp[j][0], dp[j][1] = new_dp[j][1];
	}
	cout << (dp[0][0] + dp[0][1] + mod - 1) % mod;
}


int32_t main()
{
	auto start = chrono::high_resolution_clock::now();
	boost;
	fio();
	int t = 1;
	//cin >> t;
	while (t--) solve();
	auto end = chrono::high_resolution_clock::now();
	TIME(start, end);
	return 0;
}