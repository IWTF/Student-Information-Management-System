#include<iostream>
#include<string.h>
using namespace std;

//*************************引入头文件**************************** 
#include"Information.h"
#include"Master.h"
#include"Student.h"

//************************声明函数******************************* 
void MainBoard(Master &m);		//主版面 
void masterBoard(Master &m);	//管理者版面 
void Mlogn(Master &m);			//管理者版面登陆界面 
void cao(Master &m);			//管理者登陆后的操作界面 
void stuBoard();				//学生版面
void Slogn();					//学生版面登陆界面
void stucao(char *a);			//学生登陆后的操作界面 


//***************************main函数***************************** 
int main()
{
	Master m;
	while(1){
		MainBoard(m);		
	}
	return 0; 
}

//***************************主版面****************************** 
void MainBoard(Master &m)		//主界面函数 
{
	int z;
	cout<<"------------------学籍管理系统-----------------"<<endl
		<<"-   1.管理端                                  -"<<endl
		<<"-   2.学生端                                  -"<<endl
		<<"-   请选择 1 或 2                             -"<<endl
		<<"-----------------------------------------------"<<endl;
		
	cin>>z;
	while(1)
	{
		if(z==1){
			system("cls");
			masterBoard(m);
			break;
		}else{
			if(z==2){
				system("cls");
				stuBoard(); 
				break;
			}else{
				cout<<"请从1-2中选择：";
				cin>>z;
			}
		}
	}
}

//***********************管理者模块相关函数********************** 
void masterBoard(Master &m)		//管理员界面函数 
{
	cout<<endl;
	cout<<"-------------欢迎来到管理模式--------------"<<endl;
	Mlogn(m);
}

void Mlogn(Master &m)		//管理员登陆界面及登陆验证函数 
{
	char password[20];
	cout<<"请输入管理员权限码：";
	cin>>password;
	if(strcmp(password,m.getPass())==0){
		cao(m);
	}else{
		cout<<" 权限码错误!!!!"<<endl
			<<endl; 
		Mlogn(m);//密码输入错误保持该页面 
	}
}

// ************************学生端相关函数************************* 
void stuBoard(){		//学生操作界面 
	cout<<endl;
	cout<<"------------------欢迎来到学生模式-------------------"<<endl
		<<"-注意：                                			-"<<endl
		<<"-	账号为学号，初始密码为123456    		-"<<endl
		<<"-                                			-"<<endl
		<<"--------------------------------------------------"<<endl;
	Slogn();
}

void Slogn()			//学生登陆界面及登陆验证函数
{
	int i;
	char curAccount[20];		//用于储存用户输入的账号 
	char curPassword[20];		//用于储存用户输入的密码6 
	char account[20];
	char password[20];
	//打开两个用于储存账号，密码的文件，用于验证登陆
	ifstream a("account.dat",ios::binary); 
	ifstream p("password.dat",ios::binary);
	
	 
	cout<<"请输入帐号: ";
	cin>>curAccount;
	cin.get();
	cout<<"请输入密码：";
	cin>>curPassword;
	cin.get();
	
	//循环找到账号信息，并获得匹配的密码 
	a.read((char *)account,sizeof(account));
	for(i=0;!a.eof();i++)
	{	
		if(strcmp(curAccount,account)==0){
			p.read((char *)password,sizeof(password));
			break;
		}else{
			p.read((char *)password,sizeof(password));
			a.read((char *)account,sizeof(account));
		}
	}
	
	//判断用户输入的密码和文件中存的密码是否相同 
	if(strcmp(curPassword,password)==0){
		stucao(curAccount);
	}else{
		cout<<"\n账号或密码错误！！"<<endl
			<<"请重新输入！\n"<<endl
			<<endl;
		Slogn();
	}
}
