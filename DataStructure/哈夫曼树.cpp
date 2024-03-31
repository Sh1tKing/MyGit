
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct htree {
	int wei;
	htree* lc;
	htree* rc;
	htree(int w, htree* l, htree* r) {
		wei = w;
		lc = l;
		rc = r;
	}
};
template <class T>
struct cmp {
	bool operator()(const T _Left, const T _Right) {
		return _Left->wei > _Right->wei;
	}
};
htree* create_htree(vector<int> a) {
	priority_queue<htree*,vector<htree*>,cmp<htree*>> b;
	for (int i = 0; i < a.size(); i++) {
		htree* tmp = new htree(a[i], NULL, NULL);
		//b.push_back(tmp);
		b.push(tmp);
	}
	htree* l = NULL, * r = NULL, * p = NULL;
	while (b.size() > 1) {
		/*sort(b.begin(), b.end(), [=](htree* a, htree* b) {
			return a->wei > b->wei;
			});*
			/*l = b[b.size() - 1];
			b.pop_back();
			r = b[b.size() - 1];
			b.pop_back();*/
		//555555
			l = b.top();
			b.pop();
			r = b.top();
			b.pop();
			p = new htree(l->wei + r->wei, l, r);
			b.push(p);
			//nlogn->2logn
	}
	return p;
}
void layerorder(htree* root) {
	queue<htree*> m;
	m.push(root);
	htree* last=root;
	htree* nlast=NULL;
	while (!m.empty()) {
		htree* tmp = m.front();
		cout << tmp->wei << " ";
		m.pop();
		if (tmp->lc != NULL) {
			m.push(tmp->lc);
			nlast = tmp->lc;
		}
		if (tmp->rc != NULL) {
			m.push(tmp->rc);
			nlast = tmp->rc;
		}
		if (tmp == last) {
			cout << endl;
			last = nlast;
		}
	}
}
int weight(htree* root) {
	int l = 0,wpl=0;
	queue<htree*> m;
	m.push(root);
	htree* last = root;
	htree* nlast = NULL;
	while (!m.empty()) {
		htree* tmp = m.front();
		m.pop();
		if (tmp->lc == NULL && tmp->rc == NULL) {
			wpl += tmp->wei * l;
		}
		if (tmp->lc != NULL) {
			m.push(tmp->lc);
			nlast = tmp->lc;
		}
		if (tmp->rc != NULL) {
			m.push(tmp->rc);
			nlast = tmp->rc;
		}
		if (tmp == last) {
			l++;
			last = nlast;
		}
	}
	return wpl;
}
int main() {
	vector<int> a = { 10,20,50,100 ,150};
	vector<int> b = { 10,20,35,100 ,123,130};
	vector<int> c = { 10,20,35,100 ,123,130};
	htree* root=create_htree(a);
	htree* root1 = create_htree(b);
	layerorder(root);
	cout<<weight(root);
}