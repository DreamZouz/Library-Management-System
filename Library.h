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
void gotoxy(short x, short y) {//画坐标系 
	COORD position = { x, y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, position);
}
//图书馆信息和处理（包括用户信息，管理员信息，书籍信息） 
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
	void usermenu();//用户菜单
	void adminmenu();//管理员菜单
	void land_usermenu();//用户界面展示 
	void land_adminmenu();//管理员界面展示 
	void search_id(int in);//编号查询 
	void land_idmenu();//编号查询界面展示 
	void search_name_book(int in);//书名查询 
	void land_namemenu();//书名查询界面展示 
	void borrow_book(int in);//借书 
	void land_borrowmenu(int in);//借书界面展示 
	void return_book(int in);//还书 
	void land_returnmenu(int in);//还书界面展示 
	void search_name_user_ad();//用户查询 
	void add_announcement();//增加公告
	void del_announcement();//删除公告
	void show_announcement();//显示公告
	void credit_show();//显示信誉值
	void credit_showmenu();
	void credit_set();//设置信誉值
	void credit_setmenu();
	void add_book();//增加书籍
	void del_book();// 删减书籍
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
void Library::land_menu() {//初始菜单 
	gotoxy(X + 10, 7);
	system("color 7c");
	cout << "欢"; Sleep(shortime);
	system("color 1c");
	cout << "迎"; Sleep(shortime);
	system("color 2c");
	cout << "来"; Sleep(shortime);
	system("color 3c");
	cout << "到"; Sleep(shortime);
	system("color 5c");
	cout << "图书借阅系统" << endl; Sleep(shortime);
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
	cout << "       作者：邹杨和" << endl; Sleep(shortime);
	system("pause");
	system("cls");
	gotoxy(X + 10, 7);
	cout << "欢迎进入,系统正在加载中" << endl;
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
	cout << "*                 请最大化窗口使用                  *\n";
	gotoxy(X, 13);
	cout << "*                欢迎来到图书借阅系统               *\n";
	gotoxy(X, 15);
	cout << "*                 请选择你的身份                    *\n";
	gotoxy(X, 17);
	cout << "*                                                   *\n";
	gotoxy(X, 19);
	cout << "*                                                   *\n";
	gotoxy(X, 21);
	cout << "*   1.图书管理员    2.用户    3.新用户注册   4.退出 *\n";
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
		cout << "用户名: ";
		cin >> name;
		cout << "密码：";
		cin >> password;
		if (All_admin::check(name, password)) {
			adminmenu();
			return ;
		}
		else cout << "用户名或密码错误,请重新输入" << endl;
		system("cls");
		cnt ++;
	}
	if (cnt == 3) {
		cout << "你输入太多次错误的用户名或者密码，系统已经自动关闭" << endl;
		return;
	}
}
void Library::user_in() {
	system("cls");
	string name, password;
	int cnt = 0;
	while (cnt++ < 3) {
		cout << "用户名: ";
		cin >> name;
		cout << "密码：";
		cin >> password;
		if (All_user::check(name, password)) {
			usermenu();//用户界面 
			break;
		}
		else cout << "用户名或密码错误,请重新输入" << endl;
	}
	if (cnt == 3) {
		cout << "你输入太多次错误的用户名或者密码，系统已经自动关闭" << endl;
		exit(0);
	}
}
void Library::new_user() {
	system("cls");
	string name, password1, password2;
	cout << "请输入新用户名：";
	cin >> name;
	while (true) {
		cout << "请输入新密码：";
		cin >> password1;
		cout << "请再次输入密码：";
		cin >> password2;
		if (password1 == password2) {
			All_user::add(name, password1);
			cout << "****即将进入用户登录界面****" << endl;
			Sleep(stoptime);
			user_in();
			break;
		}
		cout << "两次密码不匹配，请重新输入" << endl;
	}
}
void Library::menu() {//总菜单 
	land_menu();
	int n;
	gotoxy(X, 29);
	cout << "请输入你的选择:";
	cin >> n;
	switch (n) {
	case 1:admin_in(); break;
	case 2:user_in(); break;
	case 3:new_user(); break;
	case 4: return; break;
	}
}
//用户部分 
void Library::land_usermenu() {//输入完用户密码后，展现的界面 
	//1.编号查询 2.书名查询 3.借书 4.还书 
	system("cls");
	gotoxy(X, 15);
	cout << "*****************************************************\n";
	gotoxy(X, 18);
	cout << "*                 请选择您需要的功能                *\n";
	gotoxy(X, 21);
	cout << "*                                                   *\n";
	gotoxy(X, 24);
	cout << "*                                                   *\n";
	gotoxy(X, 27);
	cout << "*                                                   *\n";
	gotoxy(X, 30);
	cout << "*                                                   *\n";
	gotoxy(X, 33);
	cout << "* 1.编号查询   2.书名查询   3.借书   4.还书   5.退出*\n";
	gotoxy(X, 36);
	cout << "*****************************************************\n";
}
void Library::usermenu() {//用户菜单 
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
	cout << "请输入你的选择:";
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
//用户具体功能 
void Library::land_idmenu() { //编号查询界面展示 
	system("cls");
	gotoxy(X, 15);
	cout << "*****************************************************\n";
	gotoxy(X, 18);
	cout << "*                    编号查询                       *\n";
	gotoxy(X, 21);
	cout << "* 请输入查询编号:                                   *\n";
	gotoxy(X, 24);
	cout << "*                                                   *\n";
	gotoxy(X, 27);
	cout << "*                                                   *\n";
	gotoxy(X, 30);
	cout << "*                                                   *\n";
	gotoxy(X, 33);
	cout << "*                                                   *\n";
	gotoxy(X, 35);
	cout << "                                        输入###,退出 \n";
	gotoxy(X, 36);
	cout << "*****************************************************\n";
	gotoxy(X, 22);
	cout << "                 ";
}
void Library::search_id(int in) {//编号查询 
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
	cout << endl << "查无此书" << endl << endl;
	cout << "您可能要找：" << endl;
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
	if (!flag) cout << "      无相似编号" << endl;
	system("pause");
	return;
}
void Library::land_namemenu() { //名称查询界面展示 
	system("cls");
	gotoxy(X, 15);
	cout << "*****************************************************\n";
	gotoxy(X, 18);
	cout << "*                    名称查询                       *\n";
	gotoxy(X, 21);
	cout << "* 请输入查询名称:                                   *\n";
	gotoxy(X, 24);
	cout << "*                                                   *\n";
	gotoxy(X, 27);
	cout << "*                                                   *\n";
	gotoxy(X, 30);
	cout << "*                                                   *\n";
	gotoxy(X, 33);
	cout << "*                                                   *\n";
	gotoxy(X, 35);
	cout << "                                        输入###,退出 \n";
	gotoxy(X, 36);
	cout << "*****************************************************\n";
	gotoxy(X, 22);
	cout << "                 ";
}
void Library::search_name_book(int in) {//名称查询 
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
	cout << endl << "查无此书" << endl << endl;
	cout << "您可能要找：" << endl;
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
	if (!flag) cout << "      无相似名称" << endl;
	system("pause");
	return;
}
void Library::land_borrowmenu(int in) { //借书界面展示 
	system("cls");
	gotoxy(X, 15);
	cout << "*****************************************************\n";
	gotoxy(X, 18);
	cout << "*                    借阅图书                       *\n";
	gotoxy(X, 21);
	cout << "* 当前可借阅数量：                                  *\n";
	gotoxy(X, 22);
	cout << "                  " << CanHave - us[in].getcur_have();
	gotoxy(X, 24);
	cout << "*                                                   *\n";
	gotoxy(X, 27);
	cout << "* 请输入完整名称:                                   *\n";
	gotoxy(X, 30);
	cout << "*                                                   *\n";
	gotoxy(X, 33);
	cout << "*                                                   *\n";
	gotoxy(X, 35);
	cout << "                                        输入###,退出 \n";
	gotoxy(X, 36);
	cout << "*****************************************************\n";
	gotoxy(X, 28);
	cout << "                 ";
}
void Library::borrow_book(int in) {//借书 
	land_borrowmenu(in);
	string ask_name, tmp;
	cin >> ask_name;
	system("cls");
	if(us[in].get_credit() < 3){
		cout << "您的信誉值过低，请先返还书籍！" << endl;
		us[in].show_borrow();
		cout << "是否还书？" << endl;
		cout << "1.是     2.否" << endl;
		int n;
		cin >> n;
		if (n == 1) {
			return_book(in);
		}
		return;
	}
	if (us[in].getcur_have() == CanHave) {
		cout << "借阅已达上限，请先返还！" << endl;
		us[in].show_borrow();
		cout << "是否还书？" << endl;
		cout << "1.是     2.否" << endl;
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
				cout << "书已借完，请下次再来！" << endl;
				system("pause"); 
			}
			else
			{
				book[i].minus_num();
				book[i].add_borrownum();
				us[in].add_havebook(book[i]);
				cout << "借阅成功！" << endl << endl;
				us[in].show_borrow();
				if (us[in].getcur_have() <= CanHave) {
					cout << "是否继续借阅？" << endl;
					cout << "1.是     2.否" << endl;
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
	cout << endl << "查无此书" << endl << endl;
	cout << "您可能要找：" << endl;
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
	if (!flag) cout << "      无相似名称" << endl;
	system("pause");
	return;
}
void Library::land_returnmenu(int in) {//还书界面展示 
	system("cls");
	gotoxy(X, 15);
	cout << "*****************************************************\n";
	gotoxy(X, 18);
	cout << "*                    返还图书                       *\n";
	gotoxy(X, 21);
	cout << "* 当前借阅数量：                                    *\n";
	gotoxy(X, 22);
	cout << "                  " << us[in].getcur_have();
	gotoxy(X, 24);
	cout << "*                                                   *\n";
	gotoxy(X, 27);
	cout << "* 请输入完整名称:                                   *\n";
	gotoxy(X, 30);
	cout << "*                                                   *\n";
	gotoxy(X, 33);
	cout << "*                                                   *\n";
	gotoxy(X, 35);
	cout << "                                        输入###,退出 \n";
	gotoxy(X, 36);
	cout << "*****************************************************\n";
	gotoxy(X, 28);
	cout << "                 ";
}
void Library::return_book(int in) {//还书 
	land_returnmenu(in);
	string ask_name, tmp;
	if (us[in].getcur_have() == 0) {
		system("cls");
		cout << "当前无借阅记录，可以选择继续借阅！" << endl;
		cout << "1.是     2.否" << endl;
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
			cout << "返还成功！" << endl << endl;
			us[in].show_borrow();
			if (us[in].getcur_have() > 0) {
				cout << "是否继续还书？" << endl;
				cout << "1.是     2.否" << endl;
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
	cout << endl << "查无此书" << endl << endl;
	cout << "您可能要找：" << endl;
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
	if (!flag) cout << "      无相似名称" << endl;
	system("pause");
	return;
}
//管理员部分 
void Library::adminmenu() {//管理员菜单 
	land_adminmenu();
	int n = 0;
	gotoxy(X, 45);
	cout << "请输入你的选择：";
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
void Library::land_adminmenu() {//输入完管理员密码后，展现的界面 
	//1.编号查询 2.书名查询 3.添加书籍 4.删除书籍
	//5.发布公告 6.删除公告 7.查看公告 8.查看信誉
	//9.设置信誉 10.退出系统
	system("cls");
	gotoxy(X, 15);
	cout << "*****************************************************\n";
	gotoxy(X, 18);
	cout << "*                 请选择您需要的功能                *\n";
	gotoxy(X, 21);
	cout << "*                                                   *\n";
	gotoxy(X, 24);
	cout << "*                                                   *\n";
	gotoxy(X, 27);
	cout << "*                                                   *\n";
	gotoxy(X, 30);
	cout << "*                                                   *\n";
	gotoxy(X, 33);
	cout << "* 1.编号查询   2.书名查询   3.添加书籍   4.删除书籍 *\n";
	gotoxy(X, 36);
	cout << "* 5.添加公告   6.删除公告   7.查看公告   8.查看信誉 *\n";
	gotoxy(X, 39);
	cout << "*    9.设置信誉     10.用户查询      11.退出系统    *\n";
	gotoxy(X, 42);
	cout << "*****************************************************\n";
}
void Library::search_name_book_ad() {//名称查询 
	land_namemenu();
	string ask_name, tmp;
	cin >> ask_name;
	system("cls");
	for (int i = 1; i <= totalNum; ++i)
		if (ask_name == book[i].get_name()) {
			cout << endl;
			book[i].show();
			cout<<"借阅此书的用户为："<<endl;
			for(int j=1; j<=All_user::getsum();++j){
				if(us[j].borrow_checkname(book[i]))
					cout<<us[j].getname()<<endl;
			}
			system("pause");
			return;
		}
	cout << endl << "查无此书" << endl << endl;
	cout << "您可能要找：" << endl;
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
	if (!flag) cout << "      无相似名称" << endl;
	system("pause");
	return;
}
void Library::search_id_ad() {//编号查询 
	land_idmenu();
	string ask_id, tmp;
	cin >> ask_id;
	system("cls");
	for (int i = 1; i <= totalNum; ++i)
		if (ask_id == book[i].get_id()) {
			cout << endl;
			book[i].show();
			cout<<"借阅此书的用户为："<<endl;
			for(int j=1; j<=All_user::getsum();++j){
				if(us[j].borrow_checkid(book[i]))
					cout<<us[j].getname()<<endl;
			}
			system("pause");
			return;
		}
	cout << endl << "查无此书" << endl << endl;
	cout << "您可能要找：" << endl;
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
	if (!flag) cout << "      无相似编号" << endl;
	system("pause");
	return;
}
void Library::credit_show() {//信誉查看 
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
			cout<<"没有失信人员！"<<endl;
		system("pause");
		return;
	}
}
void Library::credit_showmenu() {//信誉查看界面展示 
	system("cls");
	gotoxy(X, 15);
	cout << "*****************************************************\n";
	gotoxy(X, 18);
	cout << "*                    信誉查询                       *\n";
	gotoxy(X, 21);
	cout << "* 您想要查询的是：                                  *\n";
	gotoxy(X, 24);
	cout << "*         1.全部名单          2.失信名单            *\n";
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
void Library::credit_set() {//设置信誉 
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
	cout << "确定更改此人的信誉值吗？" << endl;
	cout << " 1.是             2.否" << endl;
	cin >> flag;
	if (flag == 1) {
		cout << "输入信誉值：" ;
		cin >> new_credit;
		us[i].set_credit(new_credit);
		cout << "设置成功" << endl;
		system("pause");
		return;
	}
	else if (flag == 2) {
		return;
	}
}
void Library::credit_setmenu() {//设置界面展示 
	system("cls");
	gotoxy(X, 15);
	cout << "*****************************************************\n";
	gotoxy(X, 18);
	cout << "*                    信誉设置                       *\n";
	gotoxy(X, 21);
	cout << "* 请输入您想要设置信誉值的用户的名称：              *\n";
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
void Library::search_name_user_ad() {//人名查询 
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
	cout << endl << "查无此人" << endl << endl;
	cout << "您可能要找：" << endl;
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
	if (!flag) cout << "无相似名称" << endl;
	system("pause");
	return;
}
void Library::search_name_usermenu() { //人名查询界面展示 
	system("cls");
	gotoxy(X, 15);
	cout << "*****************************************************\n";
	gotoxy(X, 18);
	cout << "*                    人名查询                       *\n";
	gotoxy(X, 21);
	cout << "* 请输入查询名称:                                   *\n";
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
		cout << "存在公告达到上限" << endl;
		system("pause");
		return;
	}
}
void Library::add_announcementmenu() { //添加公告界面展示 
	system("cls");
	gotoxy(X, 15);
	cout << "*****************************************************\n";
	gotoxy(X, 18);
	cout << "*                    添加公告                       *\n";
	gotoxy(X, 21);
	cout << "* 请输入公告内容（不少于20字）                      *\n";
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
	cout << "  请输入书籍的名称，编号以及数量" ;
	gotoxy(X, 23);
	cout<<"   ";
	cin >> name >> id >> num;
	book[totalNum].add(name, id, num, 0);
	cout << "已经添加书籍" << endl;
	system("pause");
	return;
}
void Library::add_bookmenu() { //添加书籍界面展示 
	system("cls");
	gotoxy(X, 15);
	cout << "*****************************************************\n";
	gotoxy(X, 18);
	cout << "*                    添加书籍                       *\n";
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
		cout << "请输入书籍名称：" << endl;
		cin >> search_name;
		for (; i < totalNum; i++)
			if (book[i].get_name() == search_name)
				break;
		if (book[i].get_num() == 0) {
			cout << "不存在该书籍" << endl;
			adminmenu();
		}
		book[i].set_num(0);
		system("pause");
		return;
	}
	else if (flag == 2) {
		cout << "请输入书籍编号：" << endl;
		cin >> search_id;
		for (; i < totalNum; i++)
			if (book[i].get_id() == search_id)
				break;
		if (book[i].get_num() == 0) {
			cout << "不存在该书籍" << endl;
			adminmenu();
		}
		book[i].set_num(0);
		system("pause");
		return;
	}
}
void Library::del_bookmenu() { //删除书籍界面展示 
	system("cls");
	gotoxy(X, 15);
	cout << "*****************************************************\n";
	gotoxy(X, 18);
	cout << "*                    删除书籍                       *\n";
	gotoxy(X, 21);
	cout << "*         请输入您想要定位书籍的方式:                *\n";
	gotoxy(X, 24);
	cout << "*              1.名称    2.编号                     *\n";
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
		cout<<"没有此公告,请重新输入"<<endl;
		cout<<"请输入公告编号：";
		cin >>choose; 
	}
	
	cout << "以下是公告内容" << endl;
	cout << annoncement[choose ].get_content() << endl;
	cout << "你确定要删除它吗？" << endl;
	cout << "1.是  2.否" << endl;
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
void Library::del_announcementmenu() { //删除公告界面展示 
	system("cls");
	gotoxy(X, 15);
	cout << "*****************************************************\n";
	gotoxy(X, 18);
	cout << "*                    删除公告                       *\n";
	gotoxy(X, 21);
	cout << "* 请输入你要删除公告的编号：                        *\n";
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
	cout << "请输入您想要查阅的公告编号：" ;
	cin >> choose;
	system("cls");
	while(choose > All_announcement::get_totalNumOfAnnouncement() ){
		cout<<"没有此公告,请重新输入"<<endl;
		cout<<"请输入公告编号：";
		cin >>choose; 
	}
		cout << "您查询的公告内容如下：" << endl;
		cout << annoncement[choose].get_content() << endl;
	system("pause");
}
void Library::show_announcementmenu() { //展示公告界面展示 

	system("cls");
	gotoxy(X, 15);
	cout << "*****************************************************\n";
	gotoxy(X, 18);
	cout << "*                    展示公告                       *\n";
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
	cout << "*                                公告                                *\n";
	for(i = 1 ; i <= All_announcement::get_totalNumOfAnnouncement();i++){
		gotoxy(X, 18+3*i);
		cout<<i<<"."<<annoncement[i].get_content();
	}
	cout << endl;
	bool flag = 0;
	gotoxy(X, 18+3*i);
	cout <<i<<".失信人员名单：";
	for(i = 1 ; i <= us_sum ; i ++){
		if(us[i].get_credit() < 3) {
			cout<<us[i].getname()<<" ";
			flag = 1; 
		}
	}
	if(!flag) cout <<"无";
	cout<<endl;
}
