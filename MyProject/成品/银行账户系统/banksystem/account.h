#pragma once
#ifndef __ACCOUNT_H__
class SavingsAccount {
	private:
		int id;
		double balance;
		double rate;
		int lastDate;
		double sum;
		double total;
		void record(int date, double amount);
		double accumulate(int date) const {
			return sum + balance * (date - lastDate);
		}
	public:
		SavingsAccount(int date, int id, double rate);
		int getID() const { return id; }
		double getBalance() const { return balance; }
		double getRate() const { return rate; }
		double getTotal() { return total; }
		void deposit(int date, double amount);
		void withdraw(int date, double amount);
		void settle(int date);
		void show() const;
};
#endif __ACCOUNT_H__