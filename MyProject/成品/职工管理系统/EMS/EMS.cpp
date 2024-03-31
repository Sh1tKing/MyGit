#include<iostream>
#include"workermanage.h"
using namespace std;
int main() {
	workermanage wm1;
	wm1.show_menu();
	wm1.txt_read();
	int choice;
	while (1) {
		system("cls");
		wm1.show_menu();
		cin >> choice;
		switch (choice) {
			case 0: {
				wm1.exitsystem();
				break;
			}
			case 1: {
				wm1.worker_add();
				break;
			}
			case 2: {
				wm1.worker_show();
				break;
			}
			case 3: {
				wm1.del_worker();
				break;
			}
			case 4: {
				wm1.worker_edit();
				break;
			}
			case 5: {
				wm1.worker_find();
				break;
			}
			case 6: {
				wm1.worker_sort();
				break;
			}
			case 7: {
				wm1.worker_datacls();
				break;
			}
		}
	}
	
	return 0;
}