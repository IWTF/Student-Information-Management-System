#include<iostream>
#include<fstream>
using namespace std;
#include"Master.h"
#include"Node.h"
extern void cao(Master &m);
extern Node n;
void del(Master &m){									//此函数结构和add()函数相同 
	int z=0;
	cout<<"          删除学生信息模块"<<endl
		<<"-------------------------------------"<<endl;
	n.Del_node();
	 
	cout<<"1.返回首页"<<endl
		<<"2.继续删除"<<endl
		<<"请选择1-2："<<endl;
	cin>>z; 
	while(1)
	{
		if(z==1){
			system("cls");
			cao(m);
			break;
		}else{
			if(z==2){
				system("cls");
				del(m);
				break;
			}else{
				cout<<"请从1-2中选择：";
				cin>>z;
			}
		}
	}
}
