#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;
union cj {
	char grade;
	bool pass;
	int percent;
};
enum khmode { 考察,认定,考试 };
struct kccj {
	string xh;
	string kch;
	string kcm;
	enum khmode khfs;
	union cj pscj, qmcj, zpcj;
	int kkxq;
};
class ExamInfo {
	private:
		string xh;
		string kch;
		string kcm;
		enum khmode khfs;
		union cj pscj, qmcj, zpcj;
		int kkxq;
		vector<ExamInfo*> stuinfo;
	public:
		ExamInfo();
		ExamInfo(string xh, string kch, string kcm, enum khmode khfs, char pscj, char qmcj, char zpcj, int kkxq);
		ExamInfo(string xh, string kch, string kcm, enum khmode khfs, bool pscj, bool qmcj, bool zpcj, int kkxq);
		ExamInfo(string xh, string kch, string kcm, enum khmode khfs, int pscj, int qmcj, int zpcj, int kkxq);
		void show1();
		void show2();
		void txtstore();
		void txtread();
		void show_menu();
		void add();
		void del();
		void edit();
		void find();
		int getxhlen();
		void setinfo(string xh, string kch, string kcm, enum khmode khfs, char pscj, char qmcj, char zpcj, int kkxq); 
		void setinfo(string xh, string kch, string kcm, enum khmode khfs, bool pscj, bool qmcj, bool zpcj, int kkxq);
		void setinfo(string xh, string kch, string kcm, enum khmode khfs, int pscj, int qmcj, int zpcj, int kkxq);
};
void ExamInfo::txtstore() {
		ofstream ofs1;
		ofs1.open("1.txt", ios::out);
		for (int i = 0; i < this->stuinfo.size(); i++) {
			switch (this->stuinfo[i]->khfs) {
				case 考察: ofs1 << this->stuinfo[i]->xh <<" "<< this->stuinfo[i]->kch <<" "<< this->stuinfo[i]->kcm << " " << 1 << " " << this->stuinfo[i]->pscj.grade << " " << this->stuinfo[i]->qmcj.grade << " " << this->stuinfo[i]->zpcj.grade << " " << this->stuinfo[i]->kkxq << endl; break;
				case 认定:ofs1 << this->stuinfo[i]->xh << " " << this->stuinfo[i]->kch << " " << this->stuinfo[i]->kcm << " " << 2 << " " << this->stuinfo[i]->pscj.pass << " " << this->stuinfo[i]->qmcj.pass << " " << this->stuinfo[i]->zpcj.pass << " " << this->stuinfo[i]->kkxq << endl; break;
				case 考试:ofs1 << this->stuinfo[i]->xh <<" "<< this->stuinfo[i]->kch << " " << this->stuinfo[i]->kcm << " " << 3 << " " << this->stuinfo[i]->pscj.percent << " " << this->stuinfo[i]->qmcj.percent << " " << this->stuinfo[i]->zpcj.percent << " " << this->stuinfo[i]->kkxq << endl; break;
			}
		}
		ofs1.close();
}
void ExamInfo::txtread() {
	ifstream ifs1;
	ifs1.open("1.txt", ios::in);
	string line;
	while (getline(ifs1, line)) {
		istringstream iss(line);
		string xh;
		string kch;
		string kcm;
		int kkxq,khfsn;
		iss >> xh >> kch >> kcm >> khfsn;
		ExamInfo* e1 = NULL;
		char pscj, qmcj, zpcj;
		bool pscj1=0, qmcj1=0, zpcj1=0;
		int pscj2=0, qmcj2=0, zpcj2=0;
		switch(khfsn){
			case 1:
				iss >> pscj >> qmcj >> zpcj >> kkxq;
				e1 = new ExamInfo(xh, kch, kcm, 考察, pscj, qmcj, zpcj, kkxq);
				this->stuinfo.push_back(e1);
				break;
			case 2:
				iss >> pscj1 >> qmcj1 >> zpcj1 >> kkxq;
				e1 = new ExamInfo(xh, kch, kcm, 认定, pscj1, qmcj1, zpcj1, kkxq);
				this->stuinfo.push_back(e1);
				break;
			case 3:
				iss >> pscj2 >> qmcj2 >> zpcj2 >> kkxq;
				e1 = new ExamInfo(xh, kch, kcm, 考试, pscj2, qmcj2, zpcj2, kkxq);
				this->stuinfo.push_back(e1);
				break;
		}
	}
	ifs1.close();
}
void ExamInfo::add() {
	string xh;
	string kch;
	string kcm;
	int kkxq, khfsn;
	cout << "请依次输入学号、课程编号、课程名称" << endl;
	cin >> xh >> kch >> kcm;
	cout << "请选择考核方式：1.考察，2.认定，3.考试" << endl;
	cin>>khfsn;
	ExamInfo* e1 = NULL;
	char pscj, qmcj, zpcj;
	bool pscj1 = 0, qmcj1 = 0, zpcj1 = 0;
	int pscj2 = 0, qmcj2 = 0, zpcj2 = 0;
	switch (khfsn) {
	case 1:
		cout << "请依次输入平时、期末、总评成绩（请输入成绩等级A~F），学期" << endl;
		cin >> pscj >> qmcj >> zpcj >> kkxq;
		e1 = new ExamInfo(xh, kch, kcm, 考察, pscj, qmcj, zpcj, kkxq);
		this->stuinfo.push_back(e1);
		break;
	case 2:
		cout << "请依次输入平时、期末、总评成绩（通过（1）/不通过（0）），学期" << endl;
		cin >> pscj1 >> qmcj1 >> zpcj1 >> kkxq;
		e1 = new ExamInfo(xh, kch, kcm, 认定, pscj1, qmcj1, zpcj1, kkxq);
		this->stuinfo.push_back(e1);
		break;
	case 3:
		cout << "请依次输入平时、期末、总评成绩（请输入成绩（0~100）），学期" << endl;
		cin >> pscj2 >> qmcj2 >> zpcj2 >> kkxq;
		e1 = new ExamInfo(xh, kch, kcm, 考试, pscj2, qmcj2, zpcj2, kkxq);
		this->stuinfo.push_back(e1);
		break;
	}
	cout << "添加成功" << endl;
	system("pause");
	this->txtstore();
}
void ExamInfo::del() {
	string num,bh;
	int l=0, c = 0;
	cout << "请输入要删除的学生学号和科目名称：" << endl;
	cin >> num >> bh;
	for (int i = 0; i < this->stuinfo.size(); i++) {
		if (this->stuinfo[i]->xh == num && this->stuinfo[i]->kcm == bh) {
			l = i;
			c = 1;
		}
	}
	if (c == 0) {
		cout << "成绩不存在" << endl;
		system("pause");
	}
	else {
		this->stuinfo.erase(this->stuinfo.begin() + l);
		cout << "删除成功" << endl;
		system("pause");
	}
	this->txtstore();
}
void ExamInfo::edit() {
	string num, bh;
	int l = 0, c = 0;
	cout << "请输入要修改的学生学号和科目名称：" << endl;
	cin >> num >> bh;
	for (int i = 0; i < this->stuinfo.size(); i++) {
		if (this->stuinfo[i]->xh == num && this->stuinfo[i]->kcm == bh) {
			string xh;
			string kch;
			string kcm;
			int kkxq, khfsn;
			cout << "请选择新的考核方式：1.考察，2.认定，3.考试" << endl;
			cin >> khfsn;
			switch (khfsn) {
			case 1:
				cout << "请依次输入平时、期末、总评成绩（请输入成绩等级A~F），学期" << endl;
				cin >> this->stuinfo[i]->pscj.grade >> this->stuinfo[i]->qmcj.grade >> this->stuinfo[i]->zpcj.grade >> kkxq;
				this->stuinfo[i]->khfs = 考察;
				break;
			case 2:
				cout << "请依次输入平时、期末、总评成绩（通过（1）/不通过（0）），学期" << endl;
				cin >> this->stuinfo[i]->pscj.pass >> this->stuinfo[i]->qmcj.pass >> this->stuinfo[i]->zpcj.pass >> kkxq;
				this->stuinfo[i]->khfs = 认定;
				break;
			case 3:
				cout << "请依次输入平时、期末、总评成绩（请输入成绩（0~100）），学期" << endl;
				cin >> this->stuinfo[i]->pscj.percent >> this->stuinfo[i]->qmcj.percent >> this->stuinfo[i]->zpcj.percent >> kkxq;
				this->stuinfo[i]->khfs = 考试;
				break;
			}
			c = 1;
			break;
		}
	}
	if (c == 0) {
		cout << "学生成绩不存在" << endl;
		system("pause");
	}
	else {
		cout << "修改成功" << endl;
		system("pause");
	}
	this->txtstore();
}
void ExamInfo::find() {
	string num, bh;
	int l = 0, c = 0;
	cout << "请输入要查找的学生学号和科目名称：" << endl;
	cin >> num >> bh;
	for (int i = 0; i < this->stuinfo.size(); i++) {
		if (this->stuinfo[i]->xh == num && this->stuinfo[i]->kcm == bh) {
			cout << "学号：" << this->stuinfo[i]->xh << "\t\t" << "课程：" << this->stuinfo[i]->kcm << "\t\t";
			cout << "考核方式:";
			switch (this->stuinfo[i]->khfs) {
			case 考察: cout << "考察"; break;
			case 认定: cout << "认定"; break;
			case 考试: cout << "考试"; break;
			}
			cout << "\t\t";
			cout << "总评成绩：";
			switch (this->stuinfo[i]->khfs) {
			case 考察:cout << this->stuinfo[i]->zpcj.grade; break;
			case 认定:cout << (this->stuinfo[i]->zpcj.pass ? "PASS" : "FAIL"); break;
			case 考试:cout << this->stuinfo[i]->zpcj.percent; break;
			}
			cout << endl;
			c = 1;
			break;
		}
			
	}
	if (c == 0) {
		cout << "学生成绩不存在" << endl;
		system("pause");
	}
	else {
		system("pause");
	}
}
void ExamInfo::show1() {
	cout << "学号：" << xh << endl << "课程：" << kcm << endl;
	cout << "考核方式:";
	switch (khfs) {
	case 考察: cout << "考察"; break;
	case 认定: cout << "认定"; break;
	case 考试: cout << "考试"; break;
	}
	cout << endl;
	cout << "总评成绩：";
	switch (khfs) {
	case 考察:cout << zpcj.grade; break;
	case 认定:cout << (zpcj.pass ? "PASS" : "FAIL"); break;
	case 考试:cout << zpcj.percent; break;
	}
	cout << endl << endl;

}
void ExamInfo::show2() {
	for (int i = 0; i < this->stuinfo.size(); i++) {
		cout << "学号：" << this->stuinfo[i]->xh << "\t\t" << "课程：" << this->stuinfo[i]->kcm << "\t\t";
		cout << "考核方式:";
		switch (this->stuinfo[i]->khfs) {
		case 考察: cout << "考察"; break;
		case 认定: cout << "认定"; break;
		case 考试: cout << "考试"; break;
		}
		cout << "\t\t";
		cout << "总评成绩：";
		switch (this->stuinfo[i]->khfs) {
		case 考察:cout << this->stuinfo[i]->zpcj.grade; break;
		case 认定:cout << (this->stuinfo[i]->zpcj.pass ? "PASS" : "FAIL"); break;
		case 考试:cout << this->stuinfo[i]->zpcj.percent; break;
		}
		cout << endl;
	}
	system("pause");
}
int ExamInfo::getxhlen() {
	return xh.length();
}
void ExamInfo::show_menu() {
	cout << "******************************" << endl;
	cout << "******** 0.退出管理系统 ********" << endl;
	cout << "******** 1.增加学生成绩 ********" << endl;
	cout << "******** 2.显示学生成绩 ********" << endl;
	cout << "******** 3.删除学生成绩 ********" << endl;
	cout << "******** 4.修改学生成绩 ********" << endl;
	cout << "******** 5.查找学生成绩 ********" << endl;
	cout << "******************************" << endl;
	cout << "请输入你的选择：" << endl;
}
ExamInfo::ExamInfo() {

	this->xh = "";
	this->kch = "";
	this->kcm = "";
	this->khfs = khmode(2);
	this->pscj.percent = 0;
	this->qmcj.percent = 0;
	this->zpcj.percent = 0;
	this->kkxq = 1;
}
ExamInfo::ExamInfo(string xh, string kch, string kcm, enum khmode khfs, char pscj, char qmcj, char zpcj, int kkxq) {
	this->xh = xh;
	this->kch = kch;
	this->kcm = kcm;
	this->khfs = khfs;
	this->pscj.grade = pscj; 
	this->qmcj.grade = qmcj;
	this->zpcj.grade = zpcj;
	this->kkxq = kkxq;
}
ExamInfo::ExamInfo(string xh, string kch, string kcm, enum khmode khfs, bool pscj, bool qmcj, bool zpcj, int kkxq) {
	this->xh = xh;
	this->kch = kch;
	this->kcm = kcm;
	this->khfs = khfs;
	this->pscj.pass = pscj;
	this->qmcj.pass = qmcj;
	this->zpcj.pass = zpcj;
	this->kkxq = kkxq;
}
ExamInfo::ExamInfo(string xh, string kch, string kcm, enum khmode khfs, int pscj, int qmcj, int zpcj, int kkxq) {
	this->xh = xh;
	this->kch = kch;
	this->kcm = kcm;
	this->khfs = khfs;
	this->pscj.percent = pscj;
	this->qmcj.percent = qmcj;
	this->zpcj.percent = zpcj;
	this->kkxq = kkxq;
}
void ExamInfo::setinfo(string xh, string kch, string kcm, enum khmode khfs, char pscj, char qmcj, char zpcj, int kkxq) {

	this->xh = xh;
	this->kch = kch;
	this->kcm = kcm;
	this->khfs = khfs;
	this->pscj.grade = pscj;
	this->qmcj.grade = qmcj;
	this->zpcj.grade = zpcj;
	this->kkxq = kkxq;
}
void ExamInfo::setinfo(string xh, string kch, string kcm, enum khmode khfs, bool pscj, bool qmcj, bool zpcj, int kkxq) {
	this->xh = xh;
	this->kch = kch;
	this->kcm = kcm;
	this->khfs = khfs;
	this->pscj.pass = pscj;
	this->qmcj.pass = qmcj;
	this->zpcj.pass = zpcj;
	this->kkxq = kkxq;
}
void ExamInfo::setinfo(string xh, string kch, string kcm, enum khmode khfs, int pscj, int qmcj, int zpcj, int kkxq) {
	this->xh = xh;
	this->kch = kch;
	this->kcm = kcm;
	this->khfs = khfs;
	this->pscj.grade = pscj;
	this->qmcj.grade = qmcj;
	this->zpcj.grade = zpcj;
	this->kkxq = kkxq;
}
int main(){
	ExamInfo E;
	E.txtread();
	int choice = 0;
	while (1) {
		system("cls");
		E.show_menu();
		cin >> choice;
		switch (choice) {
			case 0: {
				system("pause");
				exit(0);
				break;
			}
			case 1: {
				E.add();
				break;
			}
			case 2: {
				E.show2();
				break;
			}
			case 3: {
				E.del();
				break;
			}
			case 4: {
				E.edit();
				break;
			}
			case 5: {
				E.find();
				break;
			}
		}
	}

}

