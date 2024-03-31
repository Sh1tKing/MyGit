#include"workermanage.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<vector>
#include<iterator>
#include<algorithm>
#include<sstream>
workermanage::workermanage() {
	this->workernum = 0;
}
workermanage::~workermanage() {

}
void workermanage::txt_read() {
	ifstream ifs1;
	ifs1.open("database.txt", ios::in);
	string line;
	while (getline(ifs1, line)) {
		istringstream iss(line);
		int id, dpm;
		string name;
		worker* a=NULL;
		iss >> id >> name >> dpm;
		switch (dpm) {
		case 1: {
			a = new employee(id, name, dpm);
			break;
		}
		case 2: {
			a = new manager(id, name, dpm);
			break;
		}
		case 3: {
			a = new boss(id, name, dpm);
			break;
		}
		}
		this->workerspace.push_back(a);
		this->workernum++;
	}
}
void workermanage::txt_storage() {
	ofstream ofs1;
	ofs1.open("database.txt", ios::out);
	for (int i = 0; i < this->workerspace.size(); i++) {
		ofs1 << this->workerspace[i]->w_id << " " << this->workerspace[i]->w_name << " " << this->workerspace[i]->w_dpm << endl;
	}
	ofs1.close();
}
void workermanage::worker_find() {
	cout << "1.按姓名查找\t2.按职工编号查找" << endl;
	int choice, c = 0;
	cin >> choice;
	switch (choice) {
		case 1: {
			string name1;
			cout << "请输入要查找的职工姓名" << endl;
			cin >> name1;
			for (int i = 0; i < this->workerspace.size(); i++) {
				if (this->workerspace[i]->w_name == name1) {
					c = 1;
					cout << this->workerspace[i]->w_id << "\t" << this->workerspace[i]->w_name << "\t";
					switch (this->workerspace[i]->w_dpm)
					{
						case 1: {
							cout << "普通职工" << endl;
							break;
						}case 2: {
							cout << "员工经理" << endl;
							break;
						}case 3: {
							cout << "总裁" << endl;
							break;
						}
					}
					system("pause");
					break;
				}
			}
			break;
		}
		case 2: {
			int id1;
			cout << "请输入要查找的职工编号" << endl;
			cin >> id1;
			for (int i = 0; i < this->workerspace.size(); i++) {
				if (this->workerspace[i]->w_id == id1) {
					c = 1;
					cout << this->workerspace[i]->w_id << "\t" << this->workerspace[i]->w_name << "\t";
					switch (this->workerspace[i]->w_dpm)
					{
						case 1: {
							cout << "普通职工" << endl;
							break;
						}case 2: {
							cout << "员工经理" << endl;
							break;
						}case 3: {
							cout << "总裁" << endl;
							break;
						}
					}
					system("pause");
					break;
				}
			}
			break;
		}
	}
	if (c == 0) {
		cout << "不存在此职工" << endl;
		system("pause");
	}
}
void workermanage::worker_edit() {
	cout << "请输入要修改的职工编号：" << endl;
	int num, c = 0;
	cin >> num;
	for (int i = 0; i < this->workerspace.size(); i++) {
		if (this->workerspace[i]->w_id == num) {
			c = 1;
			int id, dpm;
			string name;
			cout << "请输入新的编号：" << endl;
			cin >> id;
			cout << "请输入新的姓名：" << endl;
			cin >> name;
			cout << "1.普通职工" << endl << "2.员工经理" << endl << "3.总裁" << endl;
			cout << "请选择新的部门编号：" << endl;
			cin >> dpm;
			this->workerspace[i]->w_id = id;
			this->workerspace[i]->w_name = name;
			this->workerspace[i]->w_dpm = dpm;
			cout << "修改成功！" << endl;
			this->txt_storage();
			break;
		}
	}
	if (c == 0) cout << "不存在此职工" << endl;
	system("pause");
}
void workermanage::worker_sort() {
	if (this->workerspace.empty()) {
		cout << "当前无员工" << endl;
		system("pause");
		return;
	}
	cout << "1.降序排序 2.升序排序" << endl;
	int num;
	cin >> num;
	switch (num) {
		case 1: {
			for (int i = 0; i < this->workerspace.size()-1; i++) {
				for (int j = 0; j < this->workerspace.size()-i-1; j++) {
					if (this->workerspace[j]->w_id < this->workerspace[j + 1]->w_id) swap(this->workerspace[j], this->workerspace[j + 1]);
				}
			}
			this->txt_storage();
			break;
		}
		case 2: {
			for (int i = 0; i < this->workerspace.size() - 1; i++) {
				for (int j = 0; j < this->workerspace.size() - i - 1; j++) {
					if (this->workerspace[j]->w_id > this->workerspace[j + 1]->w_id) swap(this->workerspace[j], this->workerspace[j + 1]);
				}
			}
			this->txt_storage();
			break;
		}
	}
	this->worker_show();
}
void workermanage::worker_add() {
	cout << "请输入要添加的人数:" << endl;
	int addnum = 0;
	cin >> addnum;
	if (addnum > 0) {
		//add
		for (int i = 0; i < addnum; i++) {
			int id, dpm;
			string name;
			cout << "请输入第" << i + 1 << "个职工的编号：" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个职工的姓名：" << endl;
			cin >> name;
			cout << "1.普通职工" << endl << "2.员工经理" << endl << "3.总裁" << endl;
			cout << "请选择第" << i + 1 << "个职工的部门：" << endl;
			cin >> dpm;
			worker* w1 = NULL;
			switch (dpm) {
				case 1: {
					w1 = new employee(id, name, dpm);
					break;
				}
				case 2: {
					w1 = new manager(id, name, dpm);
					break;
				}
				case 3: {
					w1 = new boss(id, name, dpm);
					break;
				}
			}
			this->workerspace.push_back(w1);
			system("cls");
			this->show_menu();
		}
		cout << "成功添加" << addnum << "个职工" << endl;
		this->workernum += addnum;
		system("pause");
		system("cls");
	}
	else {
		cout << "输入有误" << endl;
		system("pause");
		system("cls");
	}
	txt_storage();
}
void workermanage::worker_show() {
	for (int i = 0; i < this->workerspace.size(); i++) {
		cout << this->workerspace[i]->w_id << " " << this->workerspace[i]->w_name << " ";
		switch (this->workerspace[i]->w_dpm)
		{
			case 1: {
				cout << "普通职工" << endl;
				break;
			}case 2: {
				cout << "员工经理" << endl;
				break;
			}case 3: {
				cout << "总裁" << endl;
				break;
			}
		}
	}
	system("pause");
	system("cls");
}
void workermanage::worker_datacls() {
	cout << "确定删除全部职工信息?(Y/N)" << endl;
	char c;
	cin >> c;
	switch (c) {
		case 'Y': {
			ofstream ofs2;
			ofs2.open("database.txt", ios::out);
			ofs2 << "";
			this->workerspace.clear();
			cout << "删除成功" << endl;
			break;
		}
		case 'N': {
			break;
		}
	}

}
void workermanage::exitsystem() {
	cout << "谢谢使用" << endl;
	system("pause");
	exit(0);
}
void workermanage::del_worker() {
	cout << "请输入要删除职工的编号:" << endl;//
	int num,c=0;
	cin >> num;
	for (int i = 0; i < this->workerspace.size(); i++) {
		if (this->workerspace[i]->w_id == num) {
			num = i;
			c = 1;
			break;
		}
		
	}
	if (c == 0) {
		cout << "职工不存在" << endl;
		system("pause");
		return;
	}
	this->workerspace.erase(this->workerspace.begin() + num);
	this->workernum--;
	this->txt_storage();
	cout << "删除成功！" << endl;
	system("pause");
}
void workermanage::show_menu() {
	cout << "******************************" << endl;
	cout << "********欢迎使用职工系统********" << endl;
	cout << "******** 0.退出管理系统 ********" << endl;
	cout << "******** 1.增加职工信息 ********" << endl;
	cout << "******** 2.显示职工信息 ********" << endl;
	cout << "******** 3.删除离职职工 ********" << endl;
	cout << "******** 4.修改职工信息 ********" << endl;
	cout << "******** 5.查找职工信息 ********" << endl;
	cout << "******** 6.按照编号排序 ********" << endl;
	cout << "******** 7.清空所有文档 ********" << endl;
	cout << "******************************" << endl;
	cout << "请输入你的选择：" << endl;
}