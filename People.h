#include<string>
#include<iostream>
#include<fstream>
#include"Book.h"
using namespace std;
class People {
protected:
	string name, password;
	int credit;//����ֵ 
	int cur_have;//��ǰӵ��������� 
	Book have_book[20];//���������Ϣ 
	int current_user;//�Ƿ��ǵ�ǰ�Ĳ����û� 
public:
	People() {
		credit = 10;
		cur_have = 0;
		current_user = 0;
	}
	void addmin(string newname, string newpassword) {
		name = newname;
		password = newpassword;
	}
	void add(string newname, string newpassword, int a, int b) {
		name = newname;
		password = newpassword;
		credit = a;
		cur_have = b;
	}
	void book_add(int x, string a, string b, int p, int q, int r){
		have_book[x].set(a, b, p, q, r);
	}
	string getname() { return this->name; };
	string getpassword() { return this->password; };
	int getcur_have() { return cur_have; }
	int get_current() { return current_user; }
	int get_credit() { return this->credit; }
	Book *get_havebook() {
		return this->have_book;
	}
	void set_credit(int x) {
		credit = x;
	}
	void is_current() {
		current_user = 1;
	}
	void delete_current() {
		current_user = 0;
	}
	void add_havebook(Book b) {
		have_book[++cur_have] = b;
		have_book[cur_have].add_borrowtime();
	}
	void minus_havebook(string s) {
		int flag = 0;
		for(int i=1; i<=cur_have; ++i){
			if(have_book[i].get_name() == s){
				flag = 1;
				for(int j=i; j<=cur_have-1; ++j){
					have_book[j] = have_book[j+1];
				}
			}
			if(flag == 1)
				break;
		}	
		cur_have--;
	}
	void show() {
		cout << "�û�����" << name << endl;
		cout << "���룺" << password << endl;
	}
	void show_borrow() {
		cout << "��ǰ���������" << endl;
		for (int i = 1; i <= cur_have; ++i)
			have_book[i].user_show();
	}
	bool borrow_checkname(Book x){
		for(int i=1; i<=cur_have; ++i){
			if(have_book[i].get_name() == x.get_name())
				return true;
		}
		return false;
	}
	bool borrow_checkid(Book x){
		for(int i=1; i<=cur_have; ++i){
			if(have_book[i].get_id() == x.get_id())
				return true;
		}
		return false;
	}
	~People() {
	}
};
class All_admin {
protected:
	People ad[N];//����Ա���� 
	static int ad_sum;//����Ա���� 
public:
	All_admin() {}
	void add_all_admin() {//ȫ������ 
		string name, password;
		fstream inOutFile;
		inOutFile.open("����Ա.txt");
		while (inOutFile >> name && name != "End") {
			inOutFile >> password;
			ad_sum++;
			ad[ad_sum].addmin(name, password);
		}
		inOutFile.clear();
		inOutFile.close();
	}
	void show_all() {
		for (int i = 1; i <= ad_sum; i++) ad[i].show();
	}
	bool check(string name, string password);
	void add(string name, string password) {
		ad_sum++;
		ad[ad_sum].addmin(name, password);
	}
	~All_admin() {
		ofstream file1;
		file1.open("����Ա.txt"); 
		for(int i = 1 ; i <= ad_sum ; i ++)
			file1 <<ad[i].getname()<<" "<<ad[i].getpassword()<<endl;
		file1.clear();
		file1.close();
	}
};
bool All_admin::check(string name, string password) {
	for (int i = 1; i <= ad_sum; i++)
		if (ad[i].getname() == name && ad[i].getpassword() == password) return true;
	return false;
}
int All_admin::ad_sum = 0;
class All_user {
protected:
	People us[N];
	static int us_sum;//�û����� 
public:
	void add_all_user() {//ȫ������
		SYSTEMTIME st;//���屾��ʱ��������ñ���Ϊ�ṹ�� 
		GetLocalTime(&st);//��ȡ����ʱ�亯��������Ϊʱ�����ָ�� 
		int borrow_time = st.wYear;
		string name, password;
		fstream inOutFile;
		int a,b;
		inOutFile.open("�û�.txt");
		while (inOutFile >> name) {
			inOutFile >> password >> a >> b;//a������ 
			us_sum++;
			int p,q,s;
			if(b != 0){
				for(int i=1; i<=b; ++i){
					string c,d;
					inOutFile>>c>>d>>p>>q>>s;
					us[us_sum].book_add(i,c,d,p,q,s);
				}
			}
			if(borrow_time - p >= 1) a --; 
			us[us_sum].add(name, password, a, b);
		}
		inOutFile.clear();
		inOutFile.close();
	}
	int getsum() { return us_sum; }
	void show_all() {
		for (int i = 1; i <= us_sum; i++) us[i].show();
	}
	bool check(string name, string password);
	void add(string name, string password) {
		us_sum++;
		us[us_sum].add(name, password, 10, 0);
	}
	~All_user() {
		ofstream file1;
		file1.open("�û�.txt"); 
		for(int i = 1 ; i <= us_sum ; i ++){
			file1 <<us[i].getname()<<" "<<us[i].getpassword()<<" "<<us[i].get_credit()<<" "<<us[i].getcur_have()<<endl;
			Book *p=us[i].get_havebook();
			for(int j=1; j<=us[i].getcur_have(); ++j){
				++p;
				file1<<p->get_name()<<" "<<p->get_id()<<" "<<p->get_year()<<" "<<p->get_month()<<" "<<p->get_day()<<endl;
			}
		}
		file1.clear();
		file1.close();
	}
};
int All_user::us_sum = 0;
bool All_user::check(string name, string password) {
	for (int i = 1; i <= us_sum; i++)
		if (us[i].getname() == name && us[i].getpassword() == password) {
			us[i].is_current();
			return true;
		}
	return false;
}
