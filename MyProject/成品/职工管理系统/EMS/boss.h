#pragma once
#include"worker.h"
#include<iostream>
#include<string>
class boss :public worker {
public:
	boss(int id, string name, int dpm);
	virtual void showinfo();
	virtual string getdpm();
};