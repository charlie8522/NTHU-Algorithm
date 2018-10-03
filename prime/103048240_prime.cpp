#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
bool check_prime(int n);
int find_factor(int n);
int str[100000000]={0};

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("input_prime.txt");
    fout.open("output_prime.txt");

    int number;
    fin >> number;
    check_prime(number);
    if (check_prime(number) == true){fout << "T" << endl;}
    else {fout << "F" << endl;}
    find_factor(number);
    for (int c = 0; str[c]!= 0; c++)
    {
        fout << str[c] << ' ';
    }
    fout << endl;
    return 0;
}

bool check_prime(int n)
{
    for(int a = 2; a <= sqrt(n); a++)
    {
        if(n % a == 0)
        {
            return false;
        }
    }
    return true;
}

int find_factor(int n)
{
    str[0] = 1;
    int b = 1;
    for(int a = 2; a < n; a++)
    {
        if(n % a == 0)
        {
            str[b] = a;
            b++;
        }
    }
    str[b] = n;
    return 1;
}
