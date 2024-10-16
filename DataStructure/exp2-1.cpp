#include "sqlist.cpp"

int main() {
	
	struct ListNode* list1 = list_init();
	backInsert(list1, 1);
	backInsert(list1, 2);
	backInsert(list1, 3);
	backInsert(list1, 4);
	backInsert(list1, 5);
	list_visit(list1);
	list_visit_reverse(list1);
	backInsert(list1, 5);
	backInsert(list1, 5);
	backInsert(list1, 6);
	backInsert(list1, 6);
	backInsert(list1, 7);
	backInsert(list1, 7);
	backInsert(list1, 7);
	list_visit(list1);
	list_delete(list1, 3);
	list_visit(list1);
	list_delreapeat(list1);
	list_visit(list1);
	list_free(list1);
}