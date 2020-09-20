/*
https://www.spoj.com/problems/SHPATH/
*/

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
#define    pii          pair<int, int>
#define    FO           find_by_order
#define    OK           order_of_key
#define    mem(a)       memset(a,0,sizeof(a))
#define    F            first
#define    S            second
#define    sp           " "
#define    vi           vector<int>
#define    vii          vector<pair<int, int>>
#define    all(a)       a.begin(), a.end()

/*
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree <
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update >
set_t;
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
	double time_taken =  chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	cout << "\nExecuted in: " << fixed
	     << time_taken << setprecision(9);
	cout << " sec";
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

///----------------------------- | START FROM HERE | --------------------------------------///

#define int long long //change int main to int32_t main

const int N = 1e4 + 5;
const int INF = 1e9 + 5;
vector<pii> adj[N];

void dijkstra(int s, vi &d, vi &p)
{
	d.assign(N, INF);
	p.assign(N, -1);

	d[s] = 0;

	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({0, s});
	while (!q.empty()) {
		int v = q.top().second;
		int d_v = q.top().first;
		q.pop();
		if (d_v != d[v])
			continue;

		for (auto edge : adj[v]) {
			int to = edge.first;
			int len = edge.second;

			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				p[to] = v;
				q.push({d[to], to});
			}
		}
	}
}

vector<int> restore_path(int s, int t, vi &p)
{
	vector<int> path;
	if (p[t] == -1) {
		path.push_back(-1);
		return path;
	}

	for (int v = t; v != s; v = p[v])
		path.push_back(v);
	path.push_back(s);

	reverse(path.begin(), path.end());
	return path;
}

void solve()
{
	int n; cin >> n;
	unordered_map<string, int> mp; //could be changed to unordered/map
	fr(i, 1, n + 1) {
		string s; cin >> s;
		mp[s] = i;
		int neigh; cin >> neigh;
		while (neigh--) {
			int nr, cost; cin >> nr >> cost;
			adj[i].pb({nr, cost});
			//adj[nr].pb({i, cost}); // directed graph
		}
	}
	int r; cin >> r;
	while (r--) {
		string s1, s2; cin >> s1 >> s2;
		int x1 = mp[s1], x2 = mp[s2];
		vi d, p;
		dijkstra(min(x1, x2), d, p);
		cout << d[max(x2, x1)] << nl;
	}
	mem(adj);

}


int32_t main()
{
	auto start = chrono::high_resolution_clock::now();
	boost;
	fio();
	int t;
	t = 1;
	cin >> t;
	while (t--) solve();
	auto end = chrono::high_resolution_clock::now();
	TIME(start, end);
	return 0;
}