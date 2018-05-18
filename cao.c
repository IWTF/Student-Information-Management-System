#include<iostream>
using namespace std;
#include"Master.h"
extern void MainBoard(Master &m);
extern void add(Master &m);
extern void del(Master &m);
extern void Modify(Master &m1);
extern void search(Master &m);
void cao(Master &m){
	int z;
	char p[20];
	cout<<"--------------------欢迎登陆-----------------------"<<endl 
		<<"-    	1.添加学生信息模块			  -"<<endl
		<<"-    	2.删除学生信息模块			  -"<<endl
		<<"-	3.修改学生信息模式			  -"<<endl
		<<"-	4.查找学生信息模式			  -"<<endl
		<<"-	5.修改管理员密码			  -"<<endl
		<<"-	6.退出登陆				  -"<<endl
		<<"---------------------------------------------------"<<endl
		<<"-请选择(1-6)：" <<endl;
	cin>>z;
	switch(z){
		case 1:{
			system("cls");
			add(m);
			break;
		}
		case 2:{
			del(m);
			break;
		}
		case 3:{
			system("cls");
			Modify(m);
			break;
		}
		case 4:{
			system("cls");
			search(m);
			break;
		}
		case 5:{
			system("cls");
			cout<<"请输入你要设置的密码：";
			cin>>p;
			m.setPass(p);
			cout<<"密码修改成功！"<<endl<<endl;
			cao(m);
			break;
		}
		case 6:{
			system("cls");           
			exit(0);
			break;
		}
	}
}
