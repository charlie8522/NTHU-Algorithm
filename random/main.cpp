#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <fstream>
#include <stdlib.h>
#include <math.h>
using namespace std;
int main()
{
	//生成文件的名字
	string fileName="input.txt";
	stringstream sstr;
	fstream fin;
	long long tmp;
	//設定隨機數種子
	srand((unsigned)time(NULL));
    sstr<<"200"<<endl;
    cerr<<"10000"<<endl;
	for(int i=0;i<10000;i++)
	{
		//產生隨機數
		tmp = 1+rand()%125;
		//將隨機數放在流sstr中
		sstr<<tmp<<' ';
		//向屏幕輸出，如果不需要，可以將其刪除
		cerr<<tmp<<' ';
	}
	sstr<<"3512"<<endl;
	//打開文件，如果文件存放，清空，如果不存在，新建一個文件
	fin.open(fileName.c_str(),ios::in|ios::trunc|ios::out);
	if(!fin)
	{
		cerr<<"Error opening "<<fileName<<" failed\n"<<endl;
	}
	//將生成的數寫入文件
	fin<<sstr.str();
	fin.close();
	return 0;
}
