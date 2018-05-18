#include<string.h>
#include<stdlib.h>
using namespace std;
#include"Student.h"
void Student::setData(int Class,float score,Information *p)//初始化班级数据 
{
	num=0;
	passNum=0;
	rank=1; 
	 
	while(p!=NULL)
	{
		if(Class==p->getClass())
		{
			if(num<30){
				if(p->getScore()>60)
					passNum++;
				if(p->getScore()>score)
					rank++;
				num++;
			}else{
				break;
			}
		}
		p=p->next;
	}
	pass=(float)passNum/num;
}
