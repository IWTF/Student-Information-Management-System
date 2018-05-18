//**************************************************************
//介绍：学生信息类 
//************************************************************* 
#ifndef _HZW_INFORMATION_H_
#define _HZW_INFORMATION_H_
#include"stdlib.h"
class Information
{
	protected:
		char name[20];
		char id[20];
		char birthday[20];		//出生日期 
		char birthPlace[20];
		char people[5];			//出生地 
		char health[5];			//健康状况 
		char phone[20];			//身份证号 
		char address[40];
		char prime_school[20];
		char password[20];
		int age;
		char sex[5];
		int Class;
		float score;
	private:								//禁止Student子类对设置学生信息函数的访问 
		void setBirthday(char *d);
		void setBirthPlace(char *b);
		void setPeople(char *p);
		void setHealth(char *h);
		void setPhone(char *p);
		void setAddress(char *a);
		void setPrime(char *s);
		void setName(char *n);
		void setId(char *i);
		void setAge(int a);
		void setClass(int c);
		void setSex(char *s);
		void setScore(float s); 
	public:								//一些获得类中变量的函数 
		Information *next=NULL;			//Information指针，用于指向下一个对象的地址 
		char *getBirthday();
		char *getBirthPlace();
		char *getPeople();
		char *getHealth();
		char *getPhone();
		char *getAddress();
		char *getPrime();
		void setStu(struct stu *obj);
		void setPassword(char *p);
		char *getName();
		char *getId();
		int getClass();
		int getAge();
		char *getSex();
		char *getPassword();
		float getScore();
		void operator = (Information &obj);		//重载 = 运算符 
		friend class Master;					//定义友元类 
};
#endif
