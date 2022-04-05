#include <iostream>
#include <string>

using namespace std;

// 通讯录最大容量
const int MAX = 1000;

// 菜单界面
void showMenu();

// 联系人结构体
struct Person {
	string m_name;
	int m_Sex;
	int m_Age;
	string m_Address;
	string m_Phone;
};

// 通讯录结构体
struct Addressbook {
	Person personArray[MAX];
	int m_Size;
};

// 添加联系人
void addPerson(Addressbook* abs);

// 显示联系人
void showPerson(Addressbook* abs);

// 判断联系人是否在通讯录中
int isExist(Addressbook* abs, string name);

// 删除联系人
void delPerson(Addressbook* abs);

// 查找联系人
void findPerson(Addressbook* abs);

// 修改联系人
void verifyPerson(Addressbook* abs);

int main() {

	Addressbook book;
	book.m_Size = 0;

	int select = 0;
	while (true) {
		showMenu();
		cin >> select;
		switch (select) {
		case 0:
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		case 1:
			addPerson(&book);
			break;
		case 2:
			showPerson(&book);
			break;
		case 3:
			delPerson(&book);
			break;
		case 4:
			findPerson(&book);
			break;
		case 5:
			break;
		case 6:
			book.m_Size = 0;
			break;
		}
	}
	return 0;
}

void showMenu() {
	cout << "*************************" << endl;
	cout << "***** 1、添加联系人 *****" << endl;
	cout << "***** 2、显示联系人 *****" << endl;
	cout << "***** 3、删除联系人 *****" << endl;
	cout << "***** 4、查找联系人 *****" << endl;
	cout << "***** 5、修改联系人 *****" << endl;
	cout << "***** 6、清空联系人 *****" << endl;
	cout << "***** 0、退出通讯录 *****" << endl;
	cout << "*************************" << endl;
	cout << "请选择操作:" << endl;
}

void addPerson(Addressbook* abs) {
	if (abs->m_Size >= MAX) {
		cout << "通讯录已满！" << endl;
		return;
	}
	else {
		string name;
		cout << "请输入姓名:" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_name = name;
		int sex;
		cout << "请输入性别：" << endl;
		cout << "0 -- 男" << endl;
		cout << "1 -- 女" << endl;
		while (cin>>sex)
		{
			if (sex == 0 || sex == 1) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else {
				cout << "性别输入有误，请重新输入" << endl;
			}
		}
		int age;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		string phone;
		cout << "请输入联系方式：" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		string address;
		cout << "请输入地址：" << endl;
		cin >> address;
		abs->personArray[abs->m_Size].m_Address = address;
		abs->m_Size += 1;
		system("cls");
	}
}

void showPerson(Addressbook* abs) {
	if (abs->m_Size == 0) {
		cout << "当前记录为空" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "姓名：" << abs->personArray[i].m_name << "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "性别：" << (abs->personArray[i].m_Sex == 0 ? "男" : "女") << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "住址：" << abs->personArray[i].m_Address << endl;
		}
	}
}

int isExist(Addressbook* abs, string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_name == name) {
			return i;
		}
	}
	return -1;
}

void delPerson(Addressbook* abs) {
	string name;
	cout << "请输入要删除的联系人姓名：" << endl;
	cin >> name;
	int index = isExist(abs, name);

	if (index == -1) {
		cout << "查无此人" << endl;
	}
	else {
		for (int i = index; i < abs->m_Size - 1; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
	}
}

void findPerson(Addressbook* abs) {
	string name;
	cout << "请输入要查找的联系人姓名：" << endl;
	cin >> name;
	int index = isExist(abs, name);
	if (index == -1) {
		cout << "查无此人" << endl;
	}
	else {
		cout << "姓名：" << abs->personArray[index].m_name << "\t";
		cout << "年龄：" << abs->personArray[index].m_Age << "\t";
		cout << "性别：" << (abs->personArray[index].m_Sex == 0 ? "男" : "女") << "\t";
		cout << "电话：" << abs->personArray[index].m_Phone << "\t";
		cout << "住址：" << abs->personArray[index].m_Address << endl;
	}
}

void verifyPerson(Addressbook* abs) {

}