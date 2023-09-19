#include<iostream>
#include"People.h"
#include"Announcement.h"
#include<string>
#include<cstring>
#include<cstdio>
#include <windows.h>
#include <conio.h>
#define stoptime 300
#define shortime 100
#define longtime 3000
#define X 60
using namespace std;
void gotoxy(short x, short y) {//������ϵ 
	COORD position = { x, y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, position);
}
//ͼ�����Ϣ�ʹ��������û���Ϣ������Ա��Ϣ���鼮��Ϣ�� 
class Library :public All_user, public All_admin, public All_book, public All_announcement {
public:
	Library() {
	}
	~Library() {
	}
	void build() {
		add_all_book(), add_all_user(), add_all_admin();add_all_announcement(); 
	}
	void show_all_book() {
		All_book::show_all();
	}
	void show_all_user() {
		All_user::show_all();
	}
	void show_all_admin() {
		All_admin::show_all();
	}
	void admin_in();
	void user_in();
	void new_user();
	void menu();
	void land_menu();
	void usermenu();//�û��˵�
	void adminmenu();//����Ա�˵�
	void land_usermenu();//�û�����չʾ 
	void land_adminmenu();//����Ա����չʾ 
	void search_id(int in);//��Ų�ѯ 
	void land_idmenu();//��Ų�ѯ����չʾ 
	void search_name_book(int in);//������ѯ 
	void land_namemenu();//������ѯ����չʾ 
	void borrow_book(int in);//���� 
	void land_borrowmenu(int in);//�������չʾ 
	void return_book(int in);//���� 
	void land_returnmenu(int in);//�������չʾ 
	void search_name_user_ad();//�û���ѯ 
	void add_announcement();//���ӹ���
	void del_announcement();//ɾ������
	void show_announcement();//��ʾ����
	void credit_show();//��ʾ����ֵ
	void credit_showmenu();
	void credit_set();//��������ֵ
	void credit_setmenu();
	void add_book();//�����鼮
	void del_book();// ɾ���鼮
	void add_announcementmenu();
	void add_bookmenu();
	void del_bookmenu();
	void del_announcementmenu();
	void show_announcementmenu();
	void search_name_usermenu();
	void search_id_ad();
	void search_name_book_ad();
	void update();
	void land_announcementmenu();
};
void Library::land_menu() {//��ʼ�˵� 
	gotoxy(X + 10, 7);
	system("color 7c");
	cout << "��"; Sleep(shortime);
	system("color 1c");
	cout << "ӭ"; Sleep(shortime);
	system("color 2c");
	cout << "��"; Sleep(shortime);
	system("color 3c");
	cout << "��"; Sleep(shortime);
	system("color 5c");
	cout << "ͼ�����ϵͳ" << endl; Sleep(shortime);
	system("color fc");
	bool f[9][36] = {
	0,1,1,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,
	0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,
	0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,
	0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,
	0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,
	0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,
	0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,
	0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,
	0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0 };
	bool s[9][21] = {
	0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,
	0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,1,0,
	1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,
	0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,
	0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,
	0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,
	0,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,
	0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,
	};
	bool t[9][22] = {
	0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,
	0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,
	1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,
	0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,
	0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,
	0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,
	0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,0,
	0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,
	};
	int k = 9;
	for (int i = 0; i < 9; i++) {
		gotoxy(X, k); cout << " ";
		for (int j = 0; j < 36; j++) {
			if (f[i][j] == 0)
				cout << " ";
			else
				cout << "*";
		}
		k += 1;
		Sleep(shortime);
	}
	gotoxy(X + 20, 20);
	system("color 3");
	cout << "       ���ߣ������" << endl; Sleep(shortime);
	system("pause");
	system("cls");
	gotoxy(X + 10, 7);
	cout << "��ӭ����,ϵͳ���ڼ�����" << endl;
	system("color fc");
	k = 9;
	for (int i = 0; i < 9; i++) {
		gotoxy(X + 10, k); cout << " ";
		for (int j = 0; j < 21; j++) {
			if (s[i][j] == 0)
				cout << " ";
			else
				cout << "*";

		}
		k++;
	}
	system("color fc");
	Sleep(longtime);
	system("cls");
	land_announcementmenu();
	system("pause");
	system("cls");
	gotoxy(X, 9);
	cout << "*****************************************************\n";
	gotoxy(X, 11);
	cout << "*                 ����󻯴���ʹ��                  *\n";
	gotoxy(X, 13);
	cout << "*                ��ӭ����ͼ�����ϵͳ               *\n";
	gotoxy(X, 15);
	cout << "*                 ��ѡ��������                    *\n";
	gotoxy(X, 17);
	cout << "*                                                   *\n";
	gotoxy(X, 19);
	cout << "*                                                   *\n";
	gotoxy(X, 21);
	cout << "*   1.ͼ�����Ա    2.�û�    3.���û�ע��   4.�˳� *\n";
	gotoxy(X, 23);
	cout << "*                                                   *\n";
	gotoxy(X, 25);
	cout << "*                                                   *\n";
	gotoxy(X, 27);
	cout << "*****************************************************\n";
}
void Library::admin_in() {
	system("cls");
	string name, password;
	int cnt = 1;
	while (cnt <= 3) {
		cout << "�û���: ";
		cin >> name;
		cout << "���룺";
		cin >> password;
		if (All_admin::check(name, password)) {
			adminmenu();
			return ;
		}
		else cout << "�û������������,����������" << endl;
		system("cls");
		cnt ++;
	}
	if (cnt == 3) {
		cout << "������̫��δ�����û����������룬ϵͳ�Ѿ��Զ��ر�" << endl;
		return;
	}
}
void Library::user_in() {
	system("cls");
	string name, password;
	int cnt = 0;
	while (cnt++ < 3) {
		cout << "�û���: ";
		cin >> name;
		cout << "���룺";
		cin >> password;
		if (All_user::check(name, password)) {
			usermenu();//�û����� 
			break;
		}
		else cout << "�û������������,����������" << endl;
	}
	if (cnt == 3) {
		cout << "������̫��δ�����û����������룬ϵͳ�Ѿ��Զ��ر�" << endl;
		exit(0);
	}
}
void Library::new_user() {
	system("cls");
	string name, password1, password2;
	cout << "���������û�����";
	cin >> name;
	while (true) {
		cout << "�����������룺";
		cin >> password1;
		cout << "���ٴ��������룺";
		cin >> password2;
		if (password1 == password2) {
			All_user::add(name, password1);
			cout << "****���������û���¼����****" << endl;
			Sleep(stoptime);
			user_in();
			break;
		}
		cout << "�������벻ƥ�䣬����������" << endl;
	}
}
void Library::menu() {//�ܲ˵� 
	land_menu();
	int n;
	gotoxy(X, 29);
	cout << "���������ѡ��:";
	cin >> n;
	switch (n) {
	case 1:admin_in(); break;
	case 2:user_in(); break;
	case 3:new_user(); break;
	case 4: return; break;
	}
}
//�û����� 
void Library::land_usermenu() {//�������û������չ�ֵĽ��� 
	//1.��Ų�ѯ 2.������ѯ 3.���� 4.���� 
	system("cls");
	gotoxy(X, 15);
	cout << "*****************************************************\n";
	gotoxy(X, 18);
	cout << "*                 ��ѡ������Ҫ�Ĺ���                *\n";
	gotoxy(X, 21);
	cout << "*                                                   *\n";
	gotoxy(X, 24);
	cout << "*                                                   *\n";
	gotoxy(X, 27);
	cout << "*                                                   *\n";
	gotoxy(X, 30);
	cout << "*                                                   *\n";
	gotoxy(X, 33);
	cout << "* 1.��Ų�ѯ   2.������ѯ   3.����   4.����   5.�˳�*\n";
	gotoxy(X, 36);
	cout << "*****************************************************\n";
}
void Library::usermenu() {//�û��˵� 
	int index;
	for (int i = 1; i <= getsum(); i++)
		if (us[i].get_current())
		{
			index = i;
			break;
		}
	land_usermenu();
	int n;
	gotoxy(X, 39);
	cout << "���������ѡ��:";
	cin >> n;
	switch (n) {
	case 1:search_id(index); break;
	case 2:search_name_book(index); break;
	case 3:borrow_book(index); break;
	case 4:return_book(index); break;
	case 5:us[index].delete_current(); return;
	}
	usermenu();
	return;
}
//�û����幦�� 
void Library::land_idmenu() { //��Ų�ѯ����չʾ 
	system("cls");
	gotoxy(X, 15);
	cout << "*****************************************************\n";
	gotoxy(X, 18);
	cout << "*                    ��Ų�ѯ                       *\n";
	gotoxy(X, 21);
	cout << "* �������ѯ���:                                   *\n";
	gotoxy(X, 24);
	cout << "*                                                   *\n";
	gotoxy(X, 27);
	cout << "*                                                   *\n";
	gotoxy(X, 30);
	cout << "*                                                   *\n";
	gotoxy(X, 33);
	cout << "*                                                   *\n";
	gotoxy(X, 35);
	cout << "                                        ����###,�˳� \n";
	gotoxy(X, 36);
	cout << "*****************************************************\n";
	gotoxy(X, 22);
	cout << "                 ";
}
void Library::search_id(int in) {//��Ų�ѯ 
	land_idmenu();
	string ask_id, tmp;
	cin >> ask_id;
	system("cls");
	if (ask_id == "###") {
		us[in].delete_current();
		return;
	}
	for (int i = 1; i <= totalNum; ++i)
		if (ask_id == book[i].get_id()) {
			cout << endl;
			book[i].show();
			system("pause");
			return;
		}
	cout << endl << "���޴���" << endl << endl;
	cout << "������Ҫ�ң�" << endl;
	int len = ask_id.length();
	int flag = 0;
	int xxx;
	for (int i = 1; i <= totalNum; ++i)
	{
		xxx = 0;
		tmp = book[i].get_id();
		for (int j = 0; j < len; ++j)
		{
			if (ask_id[j] != tmp[j])
				xxx++;
		}
		if (xxx <= 3)
		{
			book[i].show();
			cout << endl;
			flag = 1;
		}
	}
	if (!flag) cout << "      �����Ʊ��" << endl;
	system("pause");
	return;
}
void Library::land_namemenu() { //���Ʋ�ѯ����չʾ 
	system("cls");
	gotoxy(X, 15);
	cout << "*****************************************************\n";
	gotoxy(X, 18);
	cout << "*                    ���Ʋ�ѯ                       *\n";
	gotoxy(X, 21);
	cout << "* �������ѯ����:                                   *\n";
	gotoxy(X, 24);
	cout << "*                                                   *\n";
	gotoxy(X, 27);
	cout << "*                                                   *\n";
	gotoxy(X, 30);
	cout << "*                                                   *\n";
	gotoxy(X, 33);
	cout << "*                                                   *\n";
	gotoxy(X, 35);
	cout << "                                        ����###,�˳� \n";
	gotoxy(X, 36);
	cout << "*****************************************************\n";
	gotoxy(X, 22);
	cout << "                 ";
}
void Library::search_name_book(int in) {//���Ʋ�ѯ 
	land_namemenu();
	string ask_name, tmp;
	cin >> ask_name;
	system("cls");
	if (ask_name == "###") {
		us[in].delete_current();
		return;
	}
	for (int i = 1; i <= totalNum; ++i)
		if (ask_name == book[i].get_name()) {
			cout << endl;
			book[i].show();
			system("pause");
			return;
		}
	cout << endl << "���޴���" << endl << endl;
	cout << "������Ҫ�ң�" << endl;
	int len = ask_name.length();
	int flag = 0;
	int xxx;
	for (int i = 1; i <= totalNum; ++i)
	{
		xxx = 0;
		tmp = book[i].get_name();
		for (int j = 0; j < len; ++j)
		{
			if (ask_name[j] != tmp[j])
				xxx++;
		}
		if (xxx <= 3)
		{
			book[i].show();
			cout << endl;
			flag = 1;
		}
	}
	if (!flag) cout << "      ����������" << endl;
	system("pause");
	return;
}
void Library::land_borrowmenu(int in) { //�������չʾ 
	system("cls");
	gotoxy(X, 15);
	cout << "*****************************************************\n";
	gotoxy(X, 18);
	cout << "*                    ����ͼ��                       *\n";
	gotoxy(X, 21);
	cout << "* ��ǰ�ɽ���������                                  *\n";
	gotoxy(X, 22);
	cout << "                  " << CanHave - us[in].getcur_have();
	gotoxy(X, 24);
	cout << "*                                                   *\n";
	gotoxy(X, 27);
	cout << "* ��������������:                                   *\n";
	gotoxy(X, 30);
	cout << "*                                                   *\n";
	gotoxy(X, 33);
	cout << "*                                                   *\n";
	gotoxy(X, 35);
	cout << "                                        ����###,�˳� \n";
	gotoxy(X, 36);
	cout << "*****************************************************\n";
	gotoxy(X, 28);
	cout << "                 ";
}
void Library::borrow_book(int in) {//���� 
	land_borrowmenu(in);
	string ask_name, tmp;
	cin >> ask_name;
	system("cls");
	if(us[in].get_credit() < 3){
		cout << "��������ֵ���ͣ����ȷ����鼮��" << endl;
		us[in].show_borrow();
		cout << "�Ƿ��飿" << endl;
		cout << "1.��     2.��" << endl;
		int n;
		cin >> n;
		if (n == 1) {
			return_book(in);
		}
		return;
	}
	if (us[in].getcur_have() == CanHave) {
		cout << "�����Ѵ����ޣ����ȷ�����" << endl;
		us[in].show_borrow();
		cout << "�Ƿ��飿" << endl;
		cout << "1.��     2.��" << endl;
		int n;
		cin >> n;
		if (n == 1) {
			return_book(in);
		}
		return;
	}
	if (ask_name == "###") {
		us[in].delete_current();
		return;
	}
	for (int i = 1; i <= totalNum; ++i)
		if (ask_name == book[i].get_name())
		{
			if (book[i].get_num() == 0){
				cout << "���ѽ��꣬���´�������" << endl;
				system("pause"); 
			}
			else
			{
				book[i].minus_num();
				book[i].add_borrownum();
				us[in].add_havebook(book[i]);
				cout << "���ĳɹ���" << endl << endl;
				us[in].show_borrow();
				if (us[in].getcur_have() <= CanHave) {
					cout << "�Ƿ�������ģ�" << endl;
					cout << "1.��     2.��" << endl;
					int n;
					cin >> n;
					if (n == 1) {
						borrow_book(in);
					}
					system("pause");
				}
			}
			return;
		}
	cout << endl << "���޴���" << endl << endl;
	cout << "������Ҫ�ң�" << endl;
	int len = ask_name.length();
	int flag = 0;
	int xxx;
	for (int i = 1; i <= totalNum; ++i)
	{
		xxx = 0;
		tmp = book[i].get_name();
		for (int j = 0; j < len; ++j)
		{
			if (ask_name[j] != tmp[j])
				xxx++;
		}
		if (xxx <= 3)
		{
			book[i].show();
			cout << endl;
			flag = 1;
		}
	}
	if (!flag) cout << "      ����������" << endl;
	system("pause");
	return;
}
void Library::land_returnmenu(int in) {//�������չʾ 
	system("cls");
	gotoxy(X, 15);
	cout << "*****************************************************\n";
	gotoxy(X, 18);
	cout << "*                    ����ͼ��                       *\n";
	gotoxy(X, 21);
	cout << "* ��ǰ����������                                    *\n";
	gotoxy(X, 22);
	cout << "                  " << us[in].getcur_have();
	gotoxy(X, 24);
	cout << "*                                                   *\n";
	gotoxy(X, 27);
	cout << "* ��������������:                                   *\n";
	gotoxy(X, 30);
	cout << "*                                                   *\n";
	gotoxy(X, 33);
	cout << "*                                                   *\n";
	gotoxy(X, 35);
	cout << "                                        ����###,�˳� \n";
	gotoxy(X, 36);
	cout << "*****************************************************\n";
	gotoxy(X, 28);
	cout << "                 ";
}
void Library::return_book(int in) {//���� 
	land_returnmenu(in);
	string ask_name, tmp;
	if (us[in].getcur_have() == 0) {
		system("cls");
		cout << "��ǰ�޽��ļ�¼������ѡ��������ģ�" << endl;
		cout << "1.��     2.��" << endl;
		int n;
		cin >> n;
		if (n == 1) {
			borrow_book(in);
		}
		system("pause");
		return;
	}
	cin >> ask_name;
	system("cls");
	if (ask_name == "###") {
		us[in].delete_current();
		return;
	}
	for (int i = 1; i <= totalNum; ++i)
	{
		if (ask_name == book[i].get_name())
		{
			book[i].add_num();
			book[i].minus_borrownum();
			us[in].minus_havebook(book[i].get_name());
			cout << "�����ɹ���" << endl << endl;
			us[in].show_borrow();
			if (us[in].getcur_have() > 0) {
				cout << "�Ƿ�������飿" << endl;
				cout << "1.��     2.��" << endl;
				int n;
				cin >> n;
				if (n == 1) {
					return_book(in);
				}
				system("pause");
			}
			return;
		}
	}
	cout << endl << "���޴���" << endl << endl;
	cout << "������Ҫ�ң�" << endl;
	int len = ask_name.length();
	int flag = 0;
	int xxx;
	for (int i = 1; i <= totalNum; ++i)
	{
		xxx = 0;
		tmp = book[i].get_name();
		for (int j = 0; j < len; ++j)
		{
			if (ask_name[j] != tmp[j])
				xxx++;
		}
		if (xxx <= 3)
		{
			book[i].show();
			cout << endl;
			flag = 1;
		}
	}
	if (!flag) cout << "      ����������" << endl;
	system("pause");
	return;
}
//����Ա���� 
void Library::adminmenu() {//����Ա�˵� 
	land_adminmenu();
	int n = 0;
	gotoxy(X, 45);
	cout << "���������ѡ��";
	cin >> n;
	switch (n) {
	case 1:search_id_ad(); break;
	case 2:search_name_book_ad(); break;
	case 3:add_book(); break;
	case 4:del_book(); break;
	case 5:add_announcement(); break;
	case 6:del_announcement(); break;
	case 7:show_announcement();adminmenu(); break;
	case 8:credit_show(); break;
	case 9:credit_set(); break;
	case 10:search_name_user_ad(); break;
	case 11: return;
	}
	adminmenu();
	return;
}
void Library::land_adminmenu() {//���������Ա�����չ�ֵĽ��� 
	//1.��Ų�ѯ 2.������ѯ 3.����鼮 4.ɾ���鼮
	//5.�������� 6.ɾ������ 7.�鿴���� 8.�鿴����
	//9.�������� 10.�˳�ϵͳ
	system("cls");
	gotoxy(X, 15);
	cout << "*****************************************************\n";
	gotoxy(X, 18);
	cout << "*                 ��ѡ������Ҫ�Ĺ���                *\n";
	gotoxy(X, 21);
	cout << "*                                                   *\n";
	gotoxy(X, 24);
	cout << "*                                                   *\n";
	gotoxy(X, 27);
	cout << "*                                                   *\n";
	gotoxy(X, 30);
	cout << "*                                                   *\n";
	gotoxy(X, 33);
	cout << "* 1.��Ų�ѯ   2.������ѯ   3.����鼮   4.ɾ���鼮 *\n";
	gotoxy(X, 36);
	cout << "* 5.��ӹ���   6.ɾ������   7.�鿴����   8.�鿴���� *\n";
	gotoxy(X, 39);
	cout << "*    9.��������     10.�û���ѯ      11.�˳�ϵͳ    *\n";
	gotoxy(X, 42);
	cout << "*****************************************************\n";
}
void Library::search_name_book_ad() {//���Ʋ�ѯ 
	land_namemenu();
	string ask_name, tmp;
	cin >> ask_name;
	system("cls");
	for (int i = 1; i <= totalNum; ++i)
		if (ask_name == book[i].get_name()) {
			cout << endl;
			book[i].show();
			cout<<"���Ĵ�����û�Ϊ��"<<endl;
			for(int j=1; j<=All_user::getsum();++j){
				if(us[j].borrow_checkname(book[i]))
					cout<<us[j].getname()<<endl;
			}
			system("pause");
			return;
		}
	cout << endl << "���޴���" << endl << endl;
	cout << "������Ҫ�ң�" << endl;
	int len = ask_name.length();
	int flag = 0;
	int xxx;
	for (int i = 1; i <= totalNum; ++i)
	{
		xxx = 0;
		tmp = book[i].get_name();
		for (int j = 0; j < len; ++j)
		{
			if (ask_name[j] != tmp[j])
				xxx++;
		}
		if (xxx <= 3)
		{
			book[i].show();
			cout << endl;
			flag = 1;
		}
	}
	if (!flag) cout << "      ����������" << endl;
	system("pause");
	return;
}
void Library::search_id_ad() {//��Ų�ѯ 
	land_idmenu();
	string ask_id, tmp;
	cin >> ask_id;
	system("cls");
	for (int i = 1; i <= totalNum; ++i)
		if (ask_id == book[i].get_id()) {
			cout << endl;
			book[i].show();
			cout<<"���Ĵ�����û�Ϊ��"<<endl;
			for(int j=1; j<=All_user::getsum();++j){
				if(us[j].borrow_checkid(book[i]))
					cout<<us[j].getname()<<endl;
			}
			system("pause");
			return;
		}
	cout << endl << "���޴���" << endl << endl;
	cout << "������Ҫ�ң�" << endl;
	int len = ask_id.length();
	int flag = 0;
	int xxx;
	for (int i = 1; i <= totalNum; ++i)
	{
		xxx = 0;
		tmp = book[i].get_id();
		for (int j = 0; j < len; ++j)
		{
			if (ask_id[j] != tmp[j])
				xxx++;
		}
		if (xxx <= 3)
		{
			book[i].show();
			cout << endl;
			flag = 1;
		}
	}
	if (!flag) cout << "      �����Ʊ��" << endl;
	system("pause");
	return;
}
void Library::credit_show() {//�����鿴 
	credit_showmenu();
	int flag = 0;
	cin >> flag;
	system("cls");
	if (flag == 1) {
		for (int i = 1; i <= us_sum; i++)
			cout << i  << "." << us[i].getname() << " " << us[i].get_credit()<<endl;
		system("pause");
		return;
	}
	else if (flag == 2) {
		int cnt = 0;
		for (int i = 1; i <= us_sum; i++) {
			if (us[i].get_credit() < 3)
				cout << ++cnt << "." << us[i].getname() << " " << us[i].get_credit()<<endl;
		}
		if(cnt == 0)
			cout<<"û��ʧ����Ա��"<<endl;
		system("pause");
		return;
	}
}
void Library::credit_showmenu() {//�����鿴����չʾ 
	system("cls");
	gotoxy(X, 15);
	cout << "*****************************************************\n";
	gotoxy(X, 18);
	cout << "*                    ������ѯ                       *\n";
	gotoxy(X, 21);
	cout << "* ����Ҫ��ѯ���ǣ�                                  *\n";
	gotoxy(X, 24);
	cout << "*         1.ȫ������          2.ʧ������            *\n";
	gotoxy(X, 27);
	cout << "*                                                   *\n";
	gotoxy(X, 30);
	cout << "*                                                   *\n";
	gotoxy(X, 33);
	cout << "*                                                   *\n";
	gotoxy(X, 36);
	cout << "*                                                   *\n";
	gotoxy(X, 39);
	cout << "                                                    *\n";
	gotoxy(X, 42);
	cout << "*****************************************************\n";
	gotoxy(X, 22);
	cout << "                       ";
}
void Library::credit_set() {//�������� 
	string choose = "";
	int flag = 0,i=1;
	int new_credit = 0;
	credit_setmenu();
	cin >> choose;
	system("cls");
	for (i = 1; i <= us_sum; i++) {
		if (choose == us[i].getname()) {
			us[i].show();
			break;
		}
	}
	cout << "ȷ�����Ĵ��˵�����ֵ��" << endl;
	cout << " 1.��             2.��" << endl;
	cin >> flag;
	if (flag == 1) {
		cout << "��������ֵ��" ;
		cin >> new_credit;
		us[i].set_credit(new_credit);
		cout << "���óɹ�" << endl;
		system("pause");
		return;
	}
	else if (flag == 2) {
		return;
	}
}
void Library::credit_setmenu() {//���ý���չʾ 
	system("cls");
	gotoxy(X, 15);
	cout << "*****************************************************\n";
	gotoxy(X, 18);
	cout << "*                    ��������                       *\n";
	gotoxy(X, 21);
	cout << "* ����������Ҫ��������ֵ���û������ƣ�              *\n";
	gotoxy(X, 24);
	cout << "*                                                   *\n";
	gotoxy(X, 27);
	cout << "*                                                   *\n";
	gotoxy(X, 30);
	cout << "*                                                   *\n";
	gotoxy(X, 33);
	cout << "                                                     \n";
	gotoxy(X, 36);
	cout << "*****************************************************\n";
	gotoxy(X, 23);
	cout << "        ";
}
void Library::search_name_user_ad() {//������ѯ 
	search_name_usermenu();
	string ask_name="", tmp="";
	cin >> ask_name;
	system("cls");
	for (int i = 1; i <= us_sum; ++i)
		if (ask_name == us[i].getname()) {
			cout << endl;
			us[i].show();
			us[i].show_borrow();
			system("pause"); 
			return;
		}
	cout << endl << "���޴���" << endl << endl;
	cout << "������Ҫ�ң�" << endl;
	int len = ask_name.length();
	int flag = 0;
	int xxx;
	for (int i = 1; i <= us_sum; ++i)
	{
		xxx = 0;
		tmp = us[i].getname();
		for (int j = 0; j < len; ++j)
		{
			if (ask_name[j] != tmp[j])
				xxx++;
		}
		if (xxx <= 3)
		{
			us[i].show();
			cout << endl;
			flag = 1;
		}
	}
	if (!flag) cout << "����������" << endl;
	system("pause");
	return;
}
void Library::search_name_usermenu() { //������ѯ����չʾ 
	system("cls");
	gotoxy(X, 15);
	cout << "*****************************************************\n";
	gotoxy(X, 18);
	cout << "*                    ������ѯ                       *\n";
	gotoxy(X, 21);
	cout << "* �������ѯ����:                                   *\n";
	gotoxy(X, 24);
	cout << "*                                                   *\n";
	gotoxy(X, 27);
	cout << "*                                                   *\n";
	gotoxy(X, 30);
	cout << "*                                                   *\n";
	gotoxy(X, 33);
	cout << "*                                                   *\n";
	gotoxy(X, 35);
	cout << "                                                    *\n";
	gotoxy(X, 36);
	cout << "*****************************************************\n";
	gotoxy(X, 22);
}
void Library::add_announcement() {
	string newcontent="";
	add_announcementmenu();
	if (totalNumOfAnnouncement != 100) {
		totalNumOfAnnouncement++;
		cout<<"     ";
		cin >> newcontent;
		annoncement[totalNumOfAnnouncement].set_content(newcontent);
		system("pause");
		return;
	}
	else {
		cout << "���ڹ���ﵽ����" << endl;
		system("pause");
		return;
	}
}
void Library::add_announcementmenu() { //��ӹ������չʾ 
	system("cls");
	gotoxy(X, 15);
	cout << "*****************************************************\n";
	gotoxy(X, 18);
	cout << "*                    ��ӹ���                       *\n";
	gotoxy(X, 21);
	cout << "* �����빫�����ݣ�������20�֣�                      *\n";
	gotoxy(X, 24);
	cout << "*                                                   *\n";
	gotoxy(X, 27);
	cout << "*                                                   *\n";
	gotoxy(X, 30);
	cout << "*                                                   *\n";
	gotoxy(X, 33);
	cout << "*                                                   *\n";
	gotoxy(X, 35);
	cout << "                                                    *\n";
	gotoxy(X, 36);
	cout << "*****************************************************\n";
	gotoxy(X, 22);
}
void Library::add_book() {
	add_bookmenu();
	string name, id;
	int num;
	totalNum++;
	gotoxy(X, 22);
	cout << "  �������鼮�����ƣ�����Լ�����" ;
	gotoxy(X, 23);
	cout<<"   ";
	cin >> name >> id >> num;
	book[totalNum].add(name, id, num, 0);
	cout << "�Ѿ�����鼮" << endl;
	system("pause");
	return;
}
void Library::add_bookmenu() { //����鼮����չʾ 
	system("cls");
	gotoxy(X, 15);
	cout << "*****************************************************\n";
	gotoxy(X, 18);
	cout << "*                    ����鼮                       *\n";
	gotoxy(X, 21);
	cout << "*                                                   *\n";
	gotoxy(X, 24);
	cout << "*                                                   *\n";
	gotoxy(X, 27);
	cout << "*                                                   *\n";
	gotoxy(X, 30);
	cout << "*                                                   *\n";
	gotoxy(X, 33);
	cout << "*                                                   *\n";
	gotoxy(X, 35);
	cout << "                                                    *\n";
	gotoxy(X, 36);
	cout << "*****************************************************\n";
}
void Library::del_book() {
	del_bookmenu();
	int flag = 0;
	int i = 0;
	string search_name;
	string search_id;
	gotoxy(X, 23);
	cout<<"                              ";
	cin >> flag;
	system("cls");
	if (flag == 1) {
		cout << "�������鼮���ƣ�" << endl;
		cin >> search_name;
		for (; i < totalNum; i++)
			if (book[i].get_name() == search_name)
				break;
		if (book[i].get_num() == 0) {
			cout << "�����ڸ��鼮" << endl;
			adminmenu();
		}
		book[i].set_num(0);
		system("pause");
		return;
	}
	else if (flag == 2) {
		cout << "�������鼮��ţ�" << endl;
		cin >> search_id;
		for (; i < totalNum; i++)
			if (book[i].get_id() == search_id)
				break;
		if (book[i].get_num() == 0) {
			cout << "�����ڸ��鼮" << endl;
			adminmenu();
		}
		book[i].set_num(0);
		system("pause");
		return;
	}
}
void Library::del_bookmenu() { //ɾ���鼮����չʾ 
	system("cls");
	gotoxy(X, 15);
	cout << "*****************************************************\n";
	gotoxy(X, 18);
	cout << "*                    ɾ���鼮                       *\n";
	gotoxy(X, 21);
	cout << "*         ����������Ҫ��λ�鼮�ķ�ʽ:                *\n";
	gotoxy(X, 24);
	cout << "*              1.����    2.���                     *\n";
	gotoxy(X, 27);
	cout << "*                                                   *\n";
	gotoxy(X, 30);
	cout << "*                                                   *\n";
	gotoxy(X, 33);
	cout << "*                                                   *\n";
	gotoxy(X, 35);
	cout << "                                                    *\n";
	gotoxy(X, 36);
	cout << "*****************************************************\n";
}
void Library::del_announcement() {
	show_announcement();
	system("cls"); 
	del_announcementmenu();
	int choose = 0;
	int flag = 1;
	cin >> choose;
	system("cls");
	while(choose > All_announcement::get_totalNumOfAnnouncement() ){
		cout<<"û�д˹���,����������"<<endl;
		cout<<"�����빫���ţ�";
		cin >>choose; 
	}
	
	cout << "�����ǹ�������" << endl;
	cout << annoncement[choose ].get_content() << endl;
	cout << "��ȷ��Ҫɾ������" << endl;
	cout << "1.��  2.��" << endl;
	cin >> flag;
	if (flag) {
		for (int i = choose; i < 21; i++) {
			annoncement[i].set_content(annoncement[i + 1].get_content());
			totalNumOfAnnouncement--;
		}
		system("pause");
		return;
	}
	return;
}
void Library::del_announcementmenu() { //ɾ���������չʾ 
	system("cls");
	gotoxy(X, 15);
	cout << "*****************************************************\n";
	gotoxy(X, 18);
	cout << "*                    ɾ������                       *\n";
	gotoxy(X, 21);
	cout << "* ��������Ҫɾ������ı�ţ�                        *\n";
	gotoxy(X, 24);
	cout << "*                                                   *\n";
	gotoxy(X, 27);
	cout << "*                                                   *\n";
	gotoxy(X, 30);
	cout << "*                                                   *\n";
	gotoxy(X, 33);
	cout << "*                                                   *\n";
	gotoxy(X, 35);
	cout << "*                                                   *\n";
	gotoxy(X, 36);
	cout << "*****************************************************\n";
	gotoxy(X, 23);
	cout<<"                                "; 
}
void Library::show_announcement() {
	show_announcementmenu();
	int choose = 0;
	string some_content="";
	for (int i = 1; i <= All_announcement::get_totalNumOfAnnouncement() ; i++) {
		some_content = annoncement[i].get_content();
		some_content = some_content.substr(0, 20);
		gotoxy(X, 21+i);
		cout << i << "." << some_content << "..." << endl;
	}
	gotoxy(X, 37);
	cout << "����������Ҫ���ĵĹ����ţ�" ;
	cin >> choose;
	system("cls");
	while(choose > All_announcement::get_totalNumOfAnnouncement() ){
		cout<<"û�д˹���,����������"<<endl;
		cout<<"�����빫���ţ�";
		cin >>choose; 
	}
		cout << "����ѯ�Ĺ����������£�" << endl;
		cout << annoncement[choose].get_content() << endl;
	system("pause");
}
void Library::show_announcementmenu() { //չʾ�������չʾ 

	system("cls");
	gotoxy(X, 15);
	cout << "*****************************************************\n";
	gotoxy(X, 18);
	cout << "*                    չʾ����                       *\n";
	gotoxy(X, 21);
	cout << "*                                                   *\n";
	gotoxy(X, 24);
	cout << "*                                                   *\n";
	gotoxy(X, 27);
	cout << "*                                                   *\n";
	gotoxy(X, 30);
	cout << "*                                                   *\n";
	gotoxy(X, 33);
	cout << "                                                    *\n";
	gotoxy(X, 35);
	cout << "*                                                   *\n";
	gotoxy(X, 36);
	cout << "*****************************************************\n";
}
void Library::land_announcementmenu(){
	gotoxy(X, 15);int i;
	cout << "**********************************************************************\n";
	gotoxy(X, 18);
	cout << "*                                ����                                *\n";
	for(i = 1 ; i <= All_announcement::get_totalNumOfAnnouncement();i++){
		gotoxy(X, 18+3*i);
		cout<<i<<"."<<annoncement[i].get_content();
	}
	cout << endl;
	bool flag = 0;
	gotoxy(X, 18+3*i);
	cout <<i<<".ʧ����Ա������";
	for(i = 1 ; i <= us_sum ; i ++){
		if(us[i].get_credit() < 3) {
			cout<<us[i].getname()<<" ";
			flag = 1; 
		}
	}
	if(!flag) cout <<"��";
	cout<<endl;
}
