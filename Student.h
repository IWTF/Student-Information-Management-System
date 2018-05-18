//******************************************
//*Student类属于多继承
//*Student分别继承了Information和ClassIn两个基类 
//*新增属性 排名
//*新增方法 得到某同学的排名
//****************************************** 
#ifndef _HZW_STUDENT_H_
#define _HZW_STUDENT_H_
#include<iostream>
using namespace std;
#include"classIn.h"
#include"Information.h"
class Master;
class Student : public Information,public classIn
{
	public:
		void setData(int Class,float score,Information *p);		//由传入的学生的信息，对其对应班级进行初始化  
		friend void trans(Student *stu,Information *i);
};
#endif
