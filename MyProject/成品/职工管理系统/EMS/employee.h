#pragma once
#include"worker.h"
#include<iostream>
#include<string>
class employee:public worker {
	public:
		employee(int id, string name, int dpm);
		virtual void showinfo();
		virtual string getdpm();
};