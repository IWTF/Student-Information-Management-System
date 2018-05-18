#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
#include"Information.h"
class Master{
	private:
		char *pass;
	public:
		Master();					//构造函数，用于打开储存密码的文件，对pass初始化，便于对pass进行之后的操作 
		void setPass(char *p);
		char *getPass();
		
		//管理员特有权限，可以对学生信息进行设置的一些函数 
		void setBirthday(char *d,Information &i);
		void setBirthPlace(char *b,Information &i);
		void setPeople(char *p,Information &i);
		void setHealth(char *h,Information &i);
		void setPhone(char *p,Information &i);
		void setAddress(char *a,Information &i);
		void setPrime(char *s,Information &i);
		void setName(char *n,Information &i);
		void setId(char *id,Information &i);
		void setAge(int a,Information &i);
		void setClass(int c,Information &i);
		void setSex(char *s,Information &i);
		void setScore(float s,Information &i); 
};
#endif
