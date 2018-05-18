#include<string.h>
using namespace std;
#include"Information.h"

//set函数的实现 
void Information::setBirthday(char *d)
{
	strcpy(birthday,d);
} 

void Information::setBirthPlace(char *b)
{
	strcpy(birthPlace,b);
}

void Information::setPeople(char *p)
{
	strcpy(people,p);
}

void Information::setHealth(char *h)
{
	strcpy(health,h);
}

void Information::setPhone(char *p)
{
	strcpy(phone,p);
}

void Information::setAddress(char *a)
{
	strcpy(address,a);
}

void Information::setPrime(char *s)
{
	strcpy(prime_school,s);
}

void Information::setName(char *n)
{
	strcpy(name,n);
}

void Information::setId(char *i)
{
	strcpy(id,i);
}

void Information::setAge(int a)
{
	age=a;
}

void Information::setClass(int c)
{
	Class=c;
}

void Information::setSex(char *Sex)
{
	strcpy(sex,Sex);
}

void Information::setScore(float Score)
{
	score=Score;
}

void Information::setPassword(char *p){
	strcpy(password,p);
}

//get函数的实现 
char *Information::getBirthday()
{
	return birthday;
}

char *Information::getBirthPlace()
{
	return birthPlace;
}

char *Information::getPeople()
{
	return people;
}

char *Information::getHealth()
{
	return health;
}

char *Information::getPhone()
{
	return phone;
}

char *Information::getAddress()
{
	return address;
}

char *Information::getPrime()
{
	return prime_school;
}



char *Information::getName()
{
	return name;
}

char *Information::getId()
{
	return id;
}

int Information::getClass(){
	return Class;
}

int Information::getAge()
{
	return age;
}

char *Information::getSex()
{
	return sex; 
} 

char *Information::getPassword()
{
	return password;
}

float Information::getScore()
{
	return score;
}


//重载 = 运算符 
void Information::operator = (Information &obj)
{
	strcpy(name,obj.getName());
	strcpy(id,obj.getId());
	strcpy(password,obj.getPassword());
	strcpy(sex,obj.getSex());
	age=obj.getAge();
	score=obj.getScore();
	next=obj.next;
}
