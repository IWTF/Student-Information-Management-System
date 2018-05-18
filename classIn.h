//**************************************************** 
//*classIn类， 继承自Information类，指班级信息
//*新增属性 班级总分，及格率
//*新增方法 获得总分，获得班级及格率
//**************************************************** 
#ifndef _HZW_CLASSIN_H_
#define _HZW_CLASSIN_H_
#include"Information.h"
#include"Node.h"

class classIn{
	protected:
		int rank;			//学生排名 
		int passNum;		//及格人数 
		float pass;			//及格率 
		int num;			//总人数 
	public:
		int getRank();
		int getNum();
		int getPassNum();
		float getPass();
}; 
#endif
