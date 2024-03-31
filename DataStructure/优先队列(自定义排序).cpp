#include<queue>
#include<iostream>
using namespace std;
struct jb {
	int x, y;
};
template <class T>
struct cmp {
	bool operator()(const T &_Left, const T &_Right){
		return _Left.x < _Right.x;
	}
};
int main() {
	vector<jb> a{ {5,6},{9,7},{0,1234},{2341,657654} };
	priority_queue<jb,vector<jb>,cmp<jb>> q(a.begin(), a.end());
	while (!q.empty()) {
		cout << q.top().x << " " << q.top().y << endl;
		q.pop();
	}
}