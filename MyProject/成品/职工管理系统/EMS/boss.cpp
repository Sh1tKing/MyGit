#include"boss.h"
boss::boss(int id, string name, int dpm) {
	this->w_id = id;
	this->w_name = name;
	this->w_dpm = dpm;
}
void boss::showinfo() {
	cout << "职工编号：" << w_id
		<< "\t职工姓名：" << w_name
		<< "\t职工部门：" << this->getdpm()
		<< "\t岗位：掌管所有事务" << endl;
}
string boss::getdpm() {
	return string("总裁");
}
