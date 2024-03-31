#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class worker {
	public:
		virtual void showinfo() = 0;
		virtual string getdpm() = 0;
		int w_id,w_dpm;
		string w_name;
};