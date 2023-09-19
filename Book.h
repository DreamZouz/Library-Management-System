#include<string>
#include<fstream>
#include<iostream>
#include<cstdio>
#include <windows.h>
#include <conio.h>
using namespace std;
const int N = 1001;
const int CanHave = 10;
struct node {//时间 
	int year, month, day;
};
class Book {
protected:
	int num;//剩余容量 
	string id, name;//编号，书名 
	node borrow_time;//借出时间 
	int borrow_num;//借阅这种书的人数 
public:
	int get_num() { return this->num; };
	string get_id() { return this->id; };
	string get_name() { return this->name; };
	int get_borrownum() { return this->borrow_num; }
	void add_borrownum(){
		borrow_num++;
	}
	void minus_borrownum(){
		borrow_num--;
	}
	void set_name(string x) {
		name = x;
	}
	void set_id(string x) {
		id = x;
	}
	void set_num(int x) {
		num = x;
	}
	void show() {
		cout << "书名：" << name << endl;
		cout << "编号：" << id << endl;
		cout << "剩余容量：" << num << endl;
	}
	void user_show() {
		cout << "书名：" << name << endl;
		cout << "编号：" << id << endl;
		cout << "借阅时间：" << borrow_time.year << "." << borrow_time.month << "." << borrow_time.day << endl;
		cout << endl;
	}
	void add(string newname, string newid, int newnum, int a) {
		name = newname;
		id = newid;
		num = newnum;
		borrow_num = a;
	}
	void set(string newname, string newid, int a, int b, int c) {
		name = newname;
		id = newid;
		borrow_time.year = a;
		borrow_time.month = b;
		borrow_time.day = c;
	}
	void add_num() {
		num++;
	}
	void minus_num() {
		num--;
	}
	void add_borrowtime() {
		SYSTEMTIME st;//定义本地时间变量，该变量为结构体 
		GetLocalTime(&st);//获取本地时间函数，参数为时间变量指针 
		borrow_time.year = st.wYear;
		borrow_time.month = st.wMonth;
		borrow_time.day = st.wDay;
	}
	int get_year(){
		return borrow_time.year;
	}
	int get_month(){
		return borrow_time.month;
	}
	int get_day(){
		return borrow_time.day;
	}
};
class All_book {
protected:
	Book book[N];
	static int totalNum;
public:
	void add_all_book() {
		fstream inOutFile;
		inOutFile.open("图书.txt");
		string name, id;
		int num = 0;
		int a;
		string b;
		while (inOutFile >> name) {
			inOutFile >> id >> num >> a;
			totalNum++;
			book[totalNum].add(name, id, num, a);
		}
		inOutFile.clear();
		inOutFile.close();
	}
	static int get_totalNum(){return totalNum;}
	void show_all() {
		for (int i = 1; i <= totalNum; i++)
			book[i].show();
	}
	~All_book() {
		ofstream file1;
		file1.open("图书.txt"); 
		for(int i = 1 ; i <= totalNum; i++){
			file1<<book[i].get_name()<<" "<<book[i].get_id()<<" "<<book[i].get_num()<<" ";
			file1<<book[i].get_borrownum()<<endl;
		}
		file1.clear();
		file1.close();
	}
};
int All_book::totalNum = 0;
