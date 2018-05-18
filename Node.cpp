#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;
void Slogn();
int main();
#include"Information.h"
#include"Student.h"
#include"Master.h"
#include"Node.h"
#include"trans.h"

Node::Node()
{
	head = new Information;
	end=head;			//end指针总是指向链表的最后 
	int z=0;
    ifstream in("information.dat",ios::binary);

    in.read((char *)end,1);
    while(!in.eof())  
    {  	
    	z=1;
		end->next = new Information;
        in.read((char *)end->next,sizeof(*end->next));
        if(in.eof())
        	break;
        end=end->next;
    }
    
    if(z==0)
    {
    	cout<<"\n没有原始数据\n\n";
	}
    in.close();
}


Node::~Node()
{
	cout<<"调用析构函数\n";
    Information *pos = head->next;
    Information *temp;
    
	Save();
    while(pos!=end)  
    {  
        temp = pos;
        pos = pos->next;
        if(pos!=end){
        	delete temp;
		}
    }
}

void Node::Add_Node(Information &i)
{
	end->next = new Information;
    end->next=&i;
	end = end->next;
}

void Node::Del_node()//不能删除最后一个同学信息 
{
	int z=0;
	char name[20];
	Information *p=head->next;
	Information *q=head;
	
	cout<<"请输入你要删除学生的姓名: ";
	cin>>name;
	
	while(p!=NULL) 
    {  
        if(strcmp(p->getName(),name)==0){
        	z=1;
        	if(p!=end){
	            q->next=p->next;
	            break;
			}else{ 
				end=NULL;
				break;
			}
        }  
        else{  
            q=q->next;  
            p=p->next;
        }  
    }
    if(z==0){
    	cout<<endl<<"没有找到数据！"<<endl
		<<endl;
	}else{
		cout<<endl<<"删除数据成功！"<<endl
		<<endl;
	}
}

void Node::Find()
{
	int z=0;
	char name[20];
	cout<<"请输入你要查询的学生姓名: ";
	cin>>name;
	Information *p=head->next;
	
	while(p!=end)
	{
		if(strcmp(name,p->getName())==0){
			cout<<"----------------------你查询的学生信息为-----------------------"<<endl
				<<"-	姓    名："<<setw(20)<<left<<p->getName()<<setw(20)<<left<<"性    别："<<p->getSex()<<endl
				<<"-	学    号："<<setw(20)<<left<<p->getId()<<setw(20)<<left<<"民    族："<<p->getPeople()<<endl
				<<"-	出生日期："<<setw(20)<<left<<p->getBirthday()<<setw(20)<<left<<"分    数："<<p->getScore()<<endl
				<<"-	出 生 地："<<setw(20)<<left<<p->getBirthPlace()<<setw(20)<<left<<"年    龄："<<p->getAge()<<endl
				<<"-	身份证号："<<setw(20)<<left<<p->getPhone()<<setw(20)<<left<<"班    级："<<p->getClass()<<endl
				<<"-	健康状况："<<setw(20)<<left<<p->getHealth()<<setw(20)<<left<<"就读学校："<<p->getPrime()<<endl	
				<<"-	住    址："<<p->getAddress()<<endl
				<<"----------------------------------------------------------------"<<endl
				<<endl;
			z=1;	
			break;
		}else{
			p=p->next;
		}
	}
	
	if(strcmp(name,end->getName())==0){
			cout<<"----------------------你查询的学生信息为-----------------------"<<endl
				<<"-	姓    名："<<setw(20)<<left<<p->getName()<<setw(20)<<left<<"性    别："<<p->getSex()<<endl
				<<"-	学    号："<<setw(20)<<left<<p->getId()<<setw(20)<<left<<"民    族："<<p->getPeople()<<endl
				<<"-	出生日期："<<setw(20)<<left<<p->getBirthday()<<setw(20)<<left<<"分    数："<<p->getScore()<<endl
				<<"-	出 生 地："<<setw(20)<<left<<p->getBirthPlace()<<setw(20)<<left<<"年    龄："<<p->getAge()<<endl
				<<"-	身份证号："<<setw(20)<<left<<p->getPhone()<<setw(20)<<left<<"班    级："<<p->getClass()<<endl
				<<"-	健康状况："<<setw(20)<<left<<p->getHealth()<<setw(20)<<left<<"就读学校："<<p->getPrime()<<endl	
				<<"-	住    址："<<p->getAddress()<<endl
				<<"----------------------------------------------------------------"<<endl
				<<endl;
		z=1;
	}
	
	if(z==0){
		cout<<endl<<"没有该学生的信息！"<<endl
			<<endl; 
	}
}

void Node::Find(char *a)			//学生版，传入账号,以便直接读出登陆学生的信息 
{
	Information *p=head->next;
	
	while(p!=NULL)
	{
		if(strcmp(a,p->getId())==0){
			cout<<"----------------------你查询的学生信息为-----------------------"<<endl
				<<"-	姓    名："<<setw(20)<<left<<p->getName()<<setw(20)<<left<<"性    别："<<p->getSex()<<endl
				<<"-	学    号："<<setw(20)<<left<<p->getId()<<setw(20)<<left<<"民    族："<<p->getPeople()<<endl
				<<"-	出生日期："<<setw(20)<<left<<p->getBirthday()<<setw(20)<<left<<"分    数："<<p->getScore()<<endl
				<<"-	出 生 地："<<setw(20)<<left<<p->getBirthPlace()<<setw(20)<<left<<"年    龄："<<p->getAge()<<endl
				<<"-	身份证号："<<setw(20)<<left<<p->getPhone()<<setw(20)<<left<<"班    级："<<p->getClass()<<endl
				<<"-	健康状况："<<setw(20)<<left<<p->getHealth()<<setw(20)<<left<<"就读学校："<<p->getPrime()<<endl	
				<<"-	住    址："<<p->getAddress()<<endl
				<<"----------------------------------------------------------------"<<endl
				<<endl;
			//输出学生信息 
			int i;
			cout<<"1.修改密码"<<endl
				<<"2.获得班级考试情况"<<endl 
				<<"3.退出登陆"<<endl
				<<"请选择1-3："<<endl;
			cin>>i;
			switch(i){
				case 1:{
					system("cls");
					char pass[20];
					cout<<"请输入修改后的密码: ";
					cin>>pass; 
					p->setPassword(pass);
					char password[20]="123456";
					p=head->next;
					ofstream file("password.dat",ios::binary);
					while(p!=NULL)
					{
						if(strcmp(a,p->getId())==0){
							file.write((char *)&pass,sizeof(pass));
							p=p->next;
						}else{
							file.write((char *)password,sizeof(password));
							p=p->next;
						}
					}
					file.close();
					cout<<endl<<"修改密码成功！"<<endl;
					break;
				}
				case 2:{
					Student stu;
					stu.setData(p->getClass(),p->getScore(),head->next);
					trans(&stu,p);
					cout<<"班级总人数："<<stu.getNum()<<" "
						<<"及格人数："<<stu.getPassNum()<<" "
						<<"及格率："<<stu.getPass()<<" "
						<<"你的排名："<<stu.getRank()<<endl
						<<endl;
					break;
				}
				case 3:{
					system("cls");
					exit(0);
					break;
				}
			}
			system("pause");
			system("cls"); 
			break;
		}else{
			p=p->next;
		}
	}
	
}

void Node::Modify(Master &m)
{
	int flag;
	int z=0;
	char name[20];
	cout<<"请输入你要修改的学生姓名: ";
	cin>>name;
	Information *p=head->next;
	
	while(p!=NULL){
		if(strcmp(name,p->getName())==0){
			z=1;
			//展示修改前的信息 
			cout<<"-----------------------修改前的学生信息为-----------------------"<<endl
				<<"-	姓    名："<<setw(20)<<left<<p->getName()<<setw(20)<<left<<"性    别："<<p->getSex()<<endl
				<<"-	学    号："<<setw(20)<<left<<p->getId()<<setw(20)<<left<<"民    族："<<p->getPeople()<<endl
				<<"-	出生日期："<<setw(20)<<left<<p->getBirthday()<<setw(20)<<left<<"分    数："<<p->getScore()<<endl
				<<"-	出 生 地："<<setw(20)<<left<<p->getBirthPlace()<<setw(20)<<left<<"年    龄："<<p->getAge()<<endl
				<<"-	身份证号："<<setw(20)<<left<<p->getPhone()<<setw(20)<<left<<"班    级："<<p->getClass()<<endl
				<<"-	健康状况："<<setw(20)<<left<<p->getHealth()<<setw(20)<<left<<"就读学校："<<p->getPrime()<<endl	
				<<"-	住    址："<<p->getAddress()<<endl
				<<"----------------------------------------------------------------"<<endl
				<<endl;
			//展示管理员可以进行的操作 
			cout<<setw(10)<<left<<"1.修改姓名"<<setw(10)<<left<<"7.修改民族"<<endl
				<<setw(10)<<left<<"2.修改性别"<<setw(10)<<left<<"8.修改出生地"<<endl
				<<setw(10)<<left<<"3.修改年龄"<<setw(10)<<left<<"9.修改出生日期"<<endl
				<<setw(10)<<left<<"4.修改班级"<<setw(10)<<left<<"10.修改身份证号"<<endl
				<<setw(10)<<left<<"5.修改学号"<<setw(10)<<left<<"11.修改健康状况"<<endl
				<<setw(10)<<left<<"6.修改分数"<<setw(10)<<left<<"12.修改就读学校"<<endl
				<<"13.修改地址"<<endl
				<<"请选择1-13："<<endl;
			cin>>flag;
			switch(flag){
				case 1:{
					system("cls");
					cout<<"请输入修改后的姓名：";
					cin>>name;	
					m.setName(name,*p);
					break;
				}
				case 2:{
					system("cls");
					char sex[5];
					cout<<"请输入修改后的性别：";
					cin>>sex;	
					m.setSex(sex,*p);
					break;
				}
				case 3:{
					system("cls");
					int age;
					cout<<"请输入修改后的年龄：";
					cin>>age;	
					m.setAge(age,*p);
					break;
				}
				case 4:{
					system("cls");
					int Class;
					cout<<"请输入修改后的班级：";
					cin>>Class;	
					m.setClass(Class,*p);
					break;
				}
				case 5:{
					system("cls");
					char id[20];
					cout<<"请输入修改后的学号：";
					cin>>id;
					m.setId(id,*p);
					break;
				}
				case 6:{
					system("cls");
					float score;
					cout<<"请输入修改后的成绩：";
					cin>>score;
					m.setScore(score,*p); 
					break;
				}
				case 7:{
					system("cls");
					char people[5];
					cout<<"请输入修改后的民族：";
					cin>>people;
					m.setPeople(people,*p); 
					break;
				}
				case 8:{
					system("cls");
					char birthPlace[20];
					cout<<"请输入修改后的出生地：";
					cin>>birthPlace;
					m.setBirthPlace(birthPlace,*p);
					break;
				}
				case 9:{
					system("cls");
					char birthday[20];
					cout<<"请输入修改后的出生日期：";
					cin>>birthday;
					m.setBirthday(birthday,*p); 
					break;
				}
				case 10:{
					system("cls");
					char phone[20];
					cout<<"请输入修改后的身份证号：";
					cin>>phone;
					m.setPhone(phone,*p);
					break;
				}
				case 11:{
					system("cls");
					char health[20];
					cout<<"请输入修改后的健康状况：";
					cin>>health;
					m.setHealth(health,*p); 
					break;
				}
				case 12:{
					system("cls");
					char prime[20];
					cout<<"请输入修改后的就读学校：";
					cin>>prime;
					m.setPrime(prime,*p);
					break;
				}
				case 13:{
					system("cls");
					char address[50];
					cout<<"请输入修改后的住址：";
					cin>>address;
					m.setAddress(address,*p);
					break;
				}
			}
			break;
		}else{
			p=p->next;
		}
	}
	 
	if(z==0){
    	cout<<endl<<"没有该学生信息！"<<endl
			<<endl;
	}else{
		cout<<endl<<"修改数据成功！"<<endl
			<<endl;
	}
	
	
}


void Node::Save()
{
	Information *p;
	p=head->next;
	end->next=new Information;
	end->next=NULL;
	char a=' ';
	
	ofstream out("information.dat",ios::out|ios::binary);
	out.write((char *)&a,sizeof(a));
	while(p!=NULL)
	{
		out.write((char *)p,sizeof(*p));
		p=p->next;
	}
  	out.close();
}
