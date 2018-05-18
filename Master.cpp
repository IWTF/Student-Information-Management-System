#include"Master.h"
#include"Information.h"
Master::Master(){
	ifstream file;
	file.open("master.txt");
	file.getline(pass,20);
	file.close();
}

void Master::setPass(char *p){
	pass=p;
	ofstream file;
	file.open("master.txt");
	file<<pass;
}

char *Master::getPass(){
	return pass;
}

void Master::setName(char *n,Information &i){
	i.setName(n);
}

void Master::setBirthday(char *d,Information &i)
{
	i.setBirthday(d);
}

void Master::setBirthPlace(char *b,Information &i)
{
	i.setBirthPlace(b);
}

void Master::setPeople(char *p,Information &i)
{
	i.setPeople(p);
}

void Master::setHealth(char *h,Information &i)
{
	i.setHealth(h);
}

void Master::setPhone(char *p,Information &i)
{
	i.setPhone(p);
}

void Master::setAddress(char *a,Information &i)
{
	i.setAddress(a);
}

void Master::setPrime(char *s,Information &i)
{
	i.setPrime(s);
}

void Master::setId(char *id,Information &i){
	i.setId(id);
} 

void Master::setAge(int a,Information &i){
	i.setAge(a); 
};
void Master::setClass(int c,Information &i){
	i.setClass(c);
};
void Master::setSex(char *s,Information &i){
	i.setSex(s);
};
void Master::setScore(float s,Information &i){
	i.setScore(s);
}; 
