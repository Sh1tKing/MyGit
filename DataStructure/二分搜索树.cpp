#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct treenode {
	int val;
	struct treenode* lc;
	struct treenode* rc;
	struct treenode(int v) {
		val = v;
		lc = NULL;
		rc = NULL;
	}
};
treenode* predict(int back[], int mid[], int num) {
	if (num == 0) return NULL;
	int i = 0;
	int c = back[num - 1];
	while (c != mid[i] && i < num)i++;
	treenode* root = new treenode(c);
	int right = num - i - 1;
	root->lc = predict(&back[0], &mid[0], i);
	root->rc = predict(&back[i], &mid[i + 1], right);
	return root;
}
struct treenode* build_bstree(vector<int> a) {
	treenode* root = new treenode(a[0]);
	for (int i = 1; i < a.size(); i++) {
		treenode* tmp = new treenode(a[i]);
		treenode* troot = root;
		while (troot) {
			if (tmp->val < troot->val) {
				if (troot->lc == NULL) {
					troot->lc = tmp;
					break;
				}
				else troot = troot->lc;
			}
			if (tmp->val > troot->val) {
				if (troot->rc == NULL) {
					troot->rc = tmp;
					break;
				}
				else troot = troot->rc;
			}
		}
	}
	return root;
}
void inorder(treenode* root) {
	if (root == NULL) return;
	inorder(root->lc);
	cout << root->val;
	inorder(root->rc);
}
void layerorder(treenode* root) {
	queue<treenode*> m;
	m.push(root);
	while (!m.empty()) {
		treenode* tmp = m.front();
		cout << tmp->val << " ";
		m.pop();
		if (tmp->lc != NULL) {
			m.push(tmp->lc);
		}
		if (tmp->rc != NULL) {
			m.push(tmp->rc);
		}
	}
}
bool isCompleteTree(treenode* root) {
	queue<treenode*>q;
	q.push(root);
	bool flag = false;
	while (!q.empty()) {
		treenode* node = q.front();
		q.pop();
		if (node == NULL) {
			flag = true;
			continue;
		}
		if (flag) return false;
		q.push(node->lc);
		q.push(node->rc);

	}
	return true;
}
int main() {
	vector<int> a = {5,4,3,1,2,6,8,9,7};
	treenode* root = build_bstree(a);
	inorder(root);
	layerorder(root);
	return 0;
}