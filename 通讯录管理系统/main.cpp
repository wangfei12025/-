#include <iostream>
#include <string>

using namespace std;

// ͨѶ¼�������
const int MAX = 1000;

// �˵�����
void showMenu();

// ��ϵ�˽ṹ��
struct Person {
	string m_name;
	int m_Sex;
	int m_Age;
	string m_Address;
	string m_Phone;
};

// ͨѶ¼�ṹ��
struct Addressbook {
	Person personArray[MAX];
	int m_Size;
};

// �����ϵ��
void addPerson(Addressbook* abs);

// ��ʾ��ϵ��
void showPerson(Addressbook* abs);

// �ж���ϵ���Ƿ���ͨѶ¼��
int isExist(Addressbook* abs, string name);

// ɾ����ϵ��
void delPerson(Addressbook* abs);

// ������ϵ��
void findPerson(Addressbook* abs);

// �޸���ϵ��
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
			cout << "��ӭ�´�ʹ�ã�" << endl;
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
	cout << "***** 1�������ϵ�� *****" << endl;
	cout << "***** 2����ʾ��ϵ�� *****" << endl;
	cout << "***** 3��ɾ����ϵ�� *****" << endl;
	cout << "***** 4��������ϵ�� *****" << endl;
	cout << "***** 5���޸���ϵ�� *****" << endl;
	cout << "***** 6�������ϵ�� *****" << endl;
	cout << "***** 0���˳�ͨѶ¼ *****" << endl;
	cout << "*************************" << endl;
	cout << "��ѡ�����:" << endl;
}

void addPerson(Addressbook* abs) {
	if (abs->m_Size >= MAX) {
		cout << "ͨѶ¼������" << endl;
		return;
	}
	else {
		string name;
		cout << "����������:" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_name = name;
		int sex;
		cout << "�������Ա�" << endl;
		cout << "0 -- ��" << endl;
		cout << "1 -- Ů" << endl;
		while (cin>>sex)
		{
			if (sex == 0 || sex == 1) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else {
				cout << "�Ա�������������������" << endl;
			}
		}
		int age;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		string phone;
		cout << "��������ϵ��ʽ��" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		string address;
		cout << "�������ַ��" << endl;
		cin >> address;
		abs->personArray[abs->m_Size].m_Address = address;
		abs->m_Size += 1;
		system("cls");
	}
}

void showPerson(Addressbook* abs) {
	if (abs->m_Size == 0) {
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "������" << abs->personArray[i].m_name << "\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "�Ա�" << (abs->personArray[i].m_Sex == 0 ? "��" : "Ů") << "\t";
			cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
			cout << "סַ��" << abs->personArray[i].m_Address << endl;
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
	cout << "������Ҫɾ������ϵ��������" << endl;
	cin >> name;
	int index = isExist(abs, name);

	if (index == -1) {
		cout << "���޴���" << endl;
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
	cout << "������Ҫ���ҵ���ϵ��������" << endl;
	cin >> name;
	int index = isExist(abs, name);
	if (index == -1) {
		cout << "���޴���" << endl;
	}
	else {
		cout << "������" << abs->personArray[index].m_name << "\t";
		cout << "���䣺" << abs->personArray[index].m_Age << "\t";
		cout << "�Ա�" << (abs->personArray[index].m_Sex == 0 ? "��" : "Ů") << "\t";
		cout << "�绰��" << abs->personArray[index].m_Phone << "\t";
		cout << "סַ��" << abs->personArray[index].m_Address << endl;
	}
}

void verifyPerson(Addressbook* abs) {

}