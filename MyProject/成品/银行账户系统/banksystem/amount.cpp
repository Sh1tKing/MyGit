#include<iostream>
#include<math.h>
#include"account.h"
using namespace std;
SavingsAccount::SavingsAccount(int date, int id, double rate)
	:id(id), rate(rate), balance(0), lastDate(date), sum(0) {
	cout << date << "\t#" << id << "is created" << endl;
}
void SavingsAccount::record(int date, double amount) {
	sum = accumulate(date);
	lastDate = date;
	amount = floor(amount * 100 + 0.5) / 100;
	balance += amount;
	total += amount;
	cout << date << "\t#" << id << "\t" << amount << "\t" << balance << endl;
}
void SavingsAccount::deposit(int date, double amount) {
	record(date, amount);
}
void SavingsAccount::withdraw(int date, double amount) {
	if (amount > balance) cout << "Error: not enough money" << endl;
	else record(date, -amount);
}
void SavingsAccount::settle(int date) {
	double yearrate = accumulate(date) * rate / 365;
	if (yearrate != 0) record(date, yearrate);
	sum = 0;
}
void SavingsAccount::show() const {
	cout << "#" << id << "\tBalance: " << balance << endl;
}
