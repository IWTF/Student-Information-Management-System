//******************************************************************
//介绍：节点类，用于生成链表（模仿C语言链表的生成） 
//Information，Student用于储存内容，并生成next，用于储存下一个节点的首地址 
//*****************************************************************
#ifndef _HZW_NODE_H_
#define _HZW_NODE_H_
#include"Information.h"
#include"Master.h"
class Node{
	private:
		Information *head;		//头节点 
		Information *end;		//尾节点 
	public:
		Node();
		~Node();
	    void Add_Node(Information &i);//增  
	    void Del_node();//删 
	    void Display(); //显示节点 
	    void Find();//查
		void Find(char *a); 
	    void Modify(Master &m);//管理员改 
	    void Modify(Information *p);//学生改 
	    void Save(); //保存到文件 
	    int getNum();//获得某班级的学生数 
};
#endif
