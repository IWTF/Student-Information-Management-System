#include<fstream>
using namespace std;
#include"Master.h"
#include"node.h"
extern void cao(Master &m);
extern Node n;
void search(Master &m){				//此函数和add()函数相同 
	int z=0;
	cout<<"          查询学生信息模块"<<endl
		<<"-------------------------------------"<<endl; 
	n.Find();
	cout<<"1.返回首页"<<endl
		<<"2.继续查询"<<endl
		<<"请选择1-2："<<endl;;
	cin>>z;
	if(z==1){
		system("cls");
		cao(m);
	}else{
		system("cls");
		search(m);
	}
}
