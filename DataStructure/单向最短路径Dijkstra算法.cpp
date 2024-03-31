#include<iostream>
#include<vector>
using namespace std;
const int N = 1e6+10;
struct edge { int zd, cost; };
vector<edge> e[N];
int d[N], vis[N], n;
void dijkstra(int s) {
	for (int i = 0; i <= n; i++) d[i] = 99999999;
	d[s] = 0;
	for (int i = 1; i < n; i++) {
		int u = 0;
		for (int j = 1; j <= n; j++) {
			if (vis[j] != 1 && d[j] < d[u])u = j;
		}
		vis[u] = 1;
		for (auto ed : e[u]) {
			int v = ed.zd, w = ed.cost;
			if (d[u] + w < d[v]) d[v] = d[u] + w;
		}
	}
}
int main() {
	int m, s;
	int a, b, c;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		e[a].push_back({ b,c });
	}
	dijkstra(s);
}