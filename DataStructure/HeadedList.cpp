#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct ListNode {
	int val;
	struct ListNode* next;
};
struct ListNode* list_create(int array[], int n) {
	struct ListNode* list = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* p = list;
	for (int i = 0; i < n; i++) {
		struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
		tmp->val = array[i];
		p->next = tmp;
		p = p->next;
	}
	p->next = NULL;
	return list;
}
struct ListNode* list_init() {
	struct ListNode* list = (struct ListNode*)malloc(sizeof(struct ListNode));
	return list;
}
void list_visit(struct ListNode* list) {
	if (list == NULL) return;
	for (struct ListNode* p = list->next; p; p = p->next) { 
		printf("%d ", p->val);
	}
	printf("\n");
}
bool InsertElement(struct ListNode* List, int i, int element) {
	if (i < 1) return false;
	//head link
	struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
	head->next = List;
	struct ListNode* p = List;
	int j = 0;
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	if (p == NULL) return false;
	struct ListNode* insert = (struct ListNode*)malloc(sizeof(struct ListNode));
	insert->val = element;
	insert->next = p->next;
	p->next = insert;
	return true;
}
void swapL(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
struct ListNode* swapPairs(struct ListNode* head) {
	if (head == NULL) return NULL;
	int count = 0;
	struct ListNode* p = head->next;
	while (p->next != NULL) {	
		if (count % 2 == 0) {
			int ans=p->val;
			p->val = p->next->val;
			p->next->val = ans;
		}
		count++;
		p = p->next;
	}
	return p;
}
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
	struct ListNode* p1 = list1->next;
	struct ListNode* p2 = list2->next;
	struct ListNode* ph1 = list1;
	struct ListNode* ph2 = list2;
	while (p1->next = NULL) {
		if (p1 <= p2) {
			struct ListNode* tmp = p2;
			tmp->next = p1->next;
			p1->next = tmp;
		}
		else {
			struct ListNode* tmp = ph2;
			tmp->next = ph1->next;
			ph1->next = tmp;
		}
	}

}
struct ListNode* backInsert(ListNode* list,int val) {
	struct ListNode* p = list->next;
	while (p->next != NULL) {
		p = p->next;
	}
	struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
	tmp->val = val;
	p->next = tmp;
	tmp->next = NULL;
}
int main() {
	int a[5] = { 1,2,3,4,5 };
	struct ListNode* list1 = list_create(a, 5);
	list_visit(list1);
	backInsert(list1, 5);
	list_visit(list1);
}