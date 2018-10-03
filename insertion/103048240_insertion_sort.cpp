#include<iostream>
#include<fstream>
using namespace std;
int insertion(int length);
int arr[100000000];

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");

    int num,select,length = 0;
    int data;

    fin >> num;
    fin >> select;
    while (fin >> data)
    {
        arr[length] = data;
        length++;
    }
    insertion(length);
    fout << arr[select-1];

    return 0;
}

insertion(int length)
{
    int i, j, temp;
    for(i = 1; i < length; i++)
    {
        temp = arr[i];
        for( j=i; j > 0 && temp < arr[j-1]; j--)
        {
            arr[j] = arr[j-1];
        }
        arr[j] = temp;
    }
}
