#include<iostream>
#include<fstream>
#include<math.h>
#include<algorithm>
int arr[100000000];
using namespace std;
int GetMax(int arr[], int length);

int GetMax(int arr[], int length)
{
    int max_sum = arr[0], sum;
    for (int start = 0; start < length; ++start)
        for (int end = 0; end < length; ++end)
        {
            sum = 0;
            for (int i = start; i <= end; ++i)
                sum += arr[i];
            max_sum = max(max_sum, sum);
        }
    return max_sum;
}
int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");

    int arr_size,data;
    int length = 0;
    fin >> arr_size;
    while (fin >> data)
    {
        arr[length] = data;
        length++;
    }
    fout << GetMax(arr, arr_size);
    return 0;
}
