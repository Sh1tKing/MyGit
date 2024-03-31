#include"manager.h"
manager::manager(int id, string name, int dpm) {
	this->w_id = id;
	this->w_name = name;
	this->w_dpm = dpm;
}
void manager::showinfo() {
	cout << "职工编号：" << w_id
		<< "\t职工姓名：" << w_name
		<< "\t职工部门：" << this->getdpm()
		<< "\t岗位：管理职工" << endl;
}
string manager::getdpm() {
	return string("经理");
}