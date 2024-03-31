#include"employee.h"
employee::employee(int id, string name, int dpm) {
	this->w_id = id;
	this->w_name = name;
	this->w_dpm = dpm;
}
void employee::showinfo() {
	cout << "职工编号：" << w_id 
		<< "\t职工姓名：" << w_name 
		<< "\t职工部门：" <<this->getdpm()
		<<"\t岗位：完成经理分配的任务" << endl;
}
string employee::getdpm() {
	return string("普通员工");
}
