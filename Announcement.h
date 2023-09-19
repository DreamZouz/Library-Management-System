#include<string>
#include<fstream>
#include<iostream>
using namespace std;
const int M = 101;
class Announcement {
protected:
	string content;
public:
	string get_content() {
		return this->content;
	}
	void set_content(string newcontent) {
		content = newcontent;
	}
};
class All_announcement {
protected:
	Announcement annoncement[M];
	static int totalNumOfAnnouncement;
public:
	~All_announcement(){
		ofstream file1;
		file1.open("公告.txt"); 
		for (int i = 1; i <= totalNumOfAnnouncement; i++)
			file1 << annoncement[i].get_content() << endl;
	} 
	void show_all() {
		for (int i = 1; i <= totalNumOfAnnouncement; i++)
			cout << annoncement[i].get_content() << endl;
	}
	static int get_totalNumOfAnnouncement(){	return totalNumOfAnnouncement;	}
	void add_all_announcement() {
		string s="";
		fstream inOutFile;
		inOutFile.open("公告.txt");
		while(inOutFile>>s){
			totalNumOfAnnouncement++;
			annoncement[totalNumOfAnnouncement].set_content(s);
		}
	}
};
int All_announcement::totalNumOfAnnouncement = 0;

