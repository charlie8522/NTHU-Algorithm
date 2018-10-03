#include<iostream>
#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
int arr1[20],arr2[20];
int sheet[20][20];

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");

    int Str_size,Str1,Str2;
    fin >> Str_size;

    for(int i = 0; i < Str_size; i++)
    {
        fin >> Str1;
        arr1[i] = Str1;
    }
    for(int j = 0; j < Str_size; j++)
    {
        fin >> Str2;
        arr2[j] = Str2;
    }

    for (int i = 0; i <= Str_size; i++) sheet[i][0] = 0;
    for (int j = 0; j <= Str_size; j++) sheet[0][j] = 0;
    for (int i = 1; i <= Str_size; i++)
    {
        for (int j = 1; j <= Str_size; j++)
        {
            if (arr1[i] == arr2[j])
                sheet[i][j] = sheet[i-1][j-1] + 1;
            else
                sheet[i][j] = max(sheet[i-1][j],sheet[i][j-1]);
        }
    }

    fout << sheet[Str_size][Str_size] << endl;
    return 0;
}
