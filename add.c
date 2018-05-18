#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
#include"Node.h"
#include"Master.h"
#include"Information.h"
extern void cao(Master &m);
Node n;
void add(Master &m){
	int Class,age;
	float score;	
	Information i; 
	char name[20],id[20],sex[5],password[20]="123456";
	ofstream a("account.dat",ios::app|ios::binary);
	ofstream p("password.dat",ios::app|ios::binary); 

	cout<<"          添加学生信息模块"<<endl
		<<"-------------------------------------"<<endl;
	cout<<"姓名：";
	cin>>name;
	m.setName(name,i);
	
	char people[5];
	cout<<"民族：";
	cin>>people;
	m.setPeople(people,i);
	
	char birthday[20];
	cout<<"出生日期：";
	cin>>birthday;
	m.setBirthday(birthday,i);
	
	char phone[20];
	cout<<"身份证号：";
	cin>>phone;
	m.setPhone(phone,i);
	
	char health[5];
	cout<<"健康状况：";
	cin>>health;
	m.setHealth(health,i);
	
	char prime[20];
	cout<<"毕业学校：";
	cin>>prime;
	m.setPrime(prime,i);
	
	char place[40];
	cout<<"住址：";
	cin>>place;
	m.setAddress(place,i);
	
	char birthPlace[20];
	cout<<"出生地：";
	cin>>birthPlace;
	m.setBirthPlace(birthPlace,i);
	
	cout<<"年龄：";
	cin>>age;
	m.setAge(age,i);
	
	cout<<"性别：";
	cin>>sex;
	m.setSex(sex,i);
	
	cout<<"学号：";
	cin>>id;
	m.setId(id,i);
	i.setPassword(password);
	a.write((char *)id,sizeof(id));
	p.write((char *)password,sizeof(password));
	a.close();
	p.close();
	
	cout<<"班级：";
	cin>>Class;
	m.setClass(Class,i);
	
	cout<<"成绩：";
	cin>>score;
	m.setScore(score,i);
	
	
	n.Add_Node(i);						//调用相应函数将新增对象加入链表 
	cout<<endl<<"添加成功！"<<endl
		<<endl;
	
	//进行下一步操作的选择
	int z;
	cout<<"__1.返回首页"<<endl
		<<"__2.继续添加"<<endl;
	cin>>z;
	if(z==1){
		system("cls");
		cao(m);
	}else{
		system("cls");
		add(m);
	}
}
