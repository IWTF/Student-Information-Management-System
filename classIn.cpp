#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;
#include"classIn.h"
//get函数，用于返回一些类中的属性 
int classIn::getRank()
{
	return rank;
}

int classIn::getNum()
{
	return num;
}

int classIn::getPassNum(){
	return passNum;
}

float classIn::getPass()
{
	float a=(float)passNum/num;
	return a;
}
