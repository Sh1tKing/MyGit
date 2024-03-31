#include<iostream>
#include<string>
#define MAX 1000
using namespace std;
struct person {
	string m_name, m_sex, m_address, m_age, m_num;
};
struct CArray {
	struct person perArray[MAX];
	int m_size;
};
int isExit(CArray* ca, string name) {
	for (int i = 0; i < ca->m_size; i++) {
		if (ca->perArray[i].m_name == name) {
			return i;
		}
	}
	return -1;
}
void RewirteP(CArray * ca) {
	cout << "������Ҫ�޸�ͨѶ¼��Ϣ������" << endl;
	string name;
	cin >> name;
	int ret = isExit(ca, name);
	if (ret != -1) {
		string address;
		cout << "�������ַ" << endl;
		cin >> address;
		ca->perArray[ret].m_address = address;

		//age
		int age;
		cout << "����������" << endl;
		cin >> age;
		ca->perArray[ret].m_age = age;

		//name
		string sex;
		cout << "�������Ա�" << endl;
		cin >> sex;
		ca->perArray[ret].m_sex = sex;

		//name
		int num;
		cout << "������绰����" << endl;
		cin >> num;
		ca->perArray[ret].m_num = num;
		system("pause");
	}
	else {
		cout << "�����ڸ���ϵ��" << endl;
		system("pause");
		system("cls");
	}
}
void FindP(CArray * ca) {
	cout << "������Ҫ���ҵ���ϵ������" << endl;
	string name;
	cin >> name;
	int ret = isExit(ca, name);
	if (ret != -1) {
		cout << ca->perArray[ret].m_name << " " << ca->perArray[ret].m_age << " " << ca->perArray[ret].m_sex << " " << ca->perArray[ret].m_num << " " << ca->perArray[ret].m_address << endl;
	}
	else {
		cout << "�����ڸ���ϵ��" << endl;
		system("pause");
		system("cls");
	}
}
void DeleteP(CArray * ca) {
	cout << "������Ҫɾ������ϵ������" << endl;
	string name;
	cin >> name;
	int ret = isExit(ca, name);
	if (ret!=-1) {
		for (int i = ret; i < ca->m_size; i++) {
			ca->perArray[i] = ca->perArray[i + 1];
		}
		ca->m_size--;
		cout << "ɾ���ɹ�" << endl;
		system("pause");
	}
	else {
		cout << "�����ڸ���ϵ��" << endl;
		system("pause");
		system("cls");
	}
}
void AddP(CArray * ca) {
	if (ca->m_size == 1000) cout << "�����������޷����";
	else {
		//name
		string name;
		cout << "����������" << endl;
		cin >> name;
		ca->perArray[ca->m_size].m_name = name;

		//address
		string address;
		cout << "�������ַ" << endl;
		cin >> address;
		ca->perArray[ca->m_size].m_address = address;

		//age
		string age;
		cout << "����������" << endl;
		cin >> age;
		ca->perArray[ca->m_size].m_age = age;

		//name
		string sex;
		cout << "�������Ա�" << endl;
		cin >> sex;
		ca->perArray[ca->m_size].m_sex = sex;

		//name
		string num;
		cout << "������绰����" << endl;
		cin >> num;
		ca->perArray[ca->m_size].m_num = num;

		ca->m_size++;
		system("pause");
		system("cls");

	}
}
void ShowP(CArray * ca) {
	for (int i = 0; i < ca->m_size; i++) {
		cout << ca->perArray[i].m_name << " " << ca->perArray[i].m_age << " " << ca->perArray[i].m_sex << " " << ca->perArray[i].m_num << " " << ca->perArray[i].m_address << endl;
	}
	system("pause");
	system("cls");
}
void ClearP(CArray* ca) {
	ca->m_size = 0;
	cout << "����ɹ�" << endl;
	system("pause");
}
void show() {
	cout << "***********" << endl;
	cout << "1.�����ϵ��" << endl;
	cout << "2.��ʾ��ϵ��" << endl;
	cout << "3.ɾ����ϵ��" << endl;
	cout << "4.������ϵ��" << endl;
	cout << "5.�޸���ϵ��" << endl;
	cout << "6.�����ϵ��" << endl;
	cout << "0.�˳�ͨѶ¼" << endl;
	cout << "***********" << endl;
}
int select;
int main() {
	CArray ca;
	ca.m_size = 0;
	while (true) {
		show();
		cin >> select;
		switch (select) {
			case 1: {
				AddP(&ca);
				break;
			}
			case 2: {
				ShowP(&ca);
				break;
			}
			case 3: {
				DeleteP(&ca);
				break;
			}
			case 4: {
				FindP(&ca);
				break;
			}
			case 5: {
				RewirteP(&ca);
				break;
			}
			case 6: {
				ClearP(&ca);
				break;
			}
			case 0: {
				cout << "�˳��ɹ�"<<endl;
				system("pause");
				return 0;
			}
		}
			
	}
}