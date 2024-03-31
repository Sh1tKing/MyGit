#include<bits/stdc++.h>
using namespace std;
int mp[7][7] = {
	{0,0,1,1,0,1,0},
	{0,0,1,0,0,0,0},
	{1,1,0,1,0,0,0},
	{0,0,0,0,0,0,1},
	{0,0,0,0,0,0,1},
	{1,0,0,0,0,0,1},
	{0,0,0,0,1,1,0},
};
bool vis[7];
void bfs() {
	queue<int> q; 
	q.push(0);
	vis[0] = 1;
	while (!q.empty()) {
		for (int i = 0; i < 7; i++) {
			if (mp[q.front()][i] == 1 && !vis[i]) {
				q.push(i);
				vis[i] = 1;
			}
				
		}
		cout << char(q.front() + 'A');
		q.pop();
	}
}
int main() {
	bfs();
}