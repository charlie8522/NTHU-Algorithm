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
	//�ͦ���󪺦W�r
	string fileName="input.txt";
	stringstream sstr;
	fstream fin;
	long long tmp;
	//�]�w�H���ƺؤl
	srand((unsigned)time(NULL));
    sstr<<"200"<<endl;
    cerr<<"10000"<<endl;
	for(int i=0;i<10000;i++)
	{
		//�����H����
		tmp = 1+rand()%125;
		//�N�H���Ʃ�b�ysstr��
		sstr<<tmp<<' ';
		//�V�̹���X�A�p�G���ݭn�A�i�H�N��R��
		cerr<<tmp<<' ';
	}
	sstr<<"3512"<<endl;
	//���}���A�p�G���s��A�M�šA�p�G���s�b�A�s�ؤ@�Ӥ��
	fin.open(fileName.c_str(),ios::in|ios::trunc|ios::out);
	if(!fin)
	{
		cerr<<"Error opening "<<fileName<<" failed\n"<<endl;
	}
	//�N�ͦ����Ƽg�J���
	fin<<sstr.str();
	fin.close();
	return 0;
}
