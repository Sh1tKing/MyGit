#pragma once
#include<iostream>
#include"worker.h"
#include<vector>
#include<fstream>
using namespace std;
class workermanage {
	public:
		workermanage();
		~workermanage();
		void show_menu();
		void exitsystem();
		void worker_add();
		void worker_show();
		void txt_storage();
		void worker_edit();
		void worker_find();
		void del_worker();
		void txt_read();
		void worker_sort();
		void worker_datacls();
	private:
		vector<worker*> workerspace;
		int workernum;
};