#include<iostream>
#include"account.h"
using namespace std;
int main() {
	SavingsAccount a0(1, 231110237, 0.275);
	
	a0.deposit(2, 100000);
	a0.settle(3*365);
	a0.show();
}