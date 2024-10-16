#include<iostream>
#include<string>
using namespace std;
typedef struct DNode {
	int data;
	struct DNode* prior, * next;
}DNode,*DList;
bool InitDList(DList& l) {
	l = (DNode*)malloc(sizeof(DNode));
	if (l == NULL) return false;
	l->prior = NULL;
	l->next = NULL;
	return true;
}
bool InsertNode(DNode* p, DNode* s) {
	if (p == NULL || s == NULL) return false;
	s->next = p->next;
	if (p->next != NULL) {
		p->next->prior = s;
	}
	s->prior = p;
	p->next = s;
	return true;
}
bool DeleteNode(int p,DList l) {
	DNode* ptr = l->next;
	if (ptr == NULL) return false;
	p = p - 1;
	while (p--) {
		ptr = ptr->next;
	}
	ptr->prior->next = ptr->next;
	if (ptr->next != NULL) {
		ptr->next->prior = ptr->prior;
	}
	free(ptr);
	return true;
}

void SqShowNode(DList& l) {
	DNode* p = l->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
void ReShowNode(DList& l) {
	DNode* p = l;
	while (p->prior != NULL) {
		printf("%d ", p->data);
		p = p->prior;
	}
	printf("\n");
}
bool AddNode(int val, DList& l) {
	DNode* p = l;
	while (p->next != NULL) {
		p = p->next;
	}
	DNode* tmp = (DNode*)malloc(sizeof(DNode));
	tmp->data = val;
	p->next = tmp;
	tmp->prior = p;
	tmp->next = NULL;
	return true;
}
int main() {
	DList l;
	InitDList(l);
	AddNode(123, l);
	AddNode(23, l);
	AddNode(4, l);
	AddNode(0, l);
	AddNode(34, l);
	SqShowNode(l);
	DeleteNode(5, l);
	AddNode(4, l);
	SqShowNode(l);
}