#include<fstream>
using namespace std;
#include"Master.h"
#include"Node.h"
extern Node n;
extern void cao(Master &m);
void Modify(Master &m1){
	int z=0;
	cout<<"          修改学生信息模块"<<endl
		<<"-------------------------------------"<<endl;
	n.Modify(m1);
	cout<<"__1.返回首页"<<endl
		<<"__2.继续修改"<<endl;
	cin>>z;
	while(1)
	{
		if(z==1){
			system("cls");
			cao(m1);
			break;
		}else{
			if(z==2){
				system("cls");
				Modify(m1);
				break; 
			}else{
				cout<<"请从1-2中选择：";
				cin>>z;
			}
		}
	}
}
