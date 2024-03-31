#pragma once
#include<iostream>
#include<string>
#include"worker.h"
class manager:public worker{
	public:
		manager(int id, string name, int dpm);
		virtual void showinfo();
		virtual string getdpm();
};