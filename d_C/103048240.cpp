#include<iostream>
#include<fstream>
#include<math.h>
#include<algorithm>
int GetMax(int arr[], int length, int start, int end);
int GetCrossMax(int arr[], int length, int start, int middle, int end);
int arr[100000000];
using namespace std;

int GetMax(int arr[], int length, int start, int end)
{
    if (start == end)
    {
        return arr[start];
    }
    int middle = (start + end) / 2;
    int leftMax = GetMax(arr, length, start, middle);
    int rightMax = GetMax(arr, length, middle + 1, end);
    int crossMax = GetCrossMax(arr, length, start, middle, end);

    return max(max(leftMax, rightMax), crossMax);
}

int GetCrossMax(int arr[], int length, int start, int middle, int end)
{
    int leftMax = arr[middle], leftSum = 0;
    int rightMax = arr[middle + 1], rightSum = 0;
    for (int i = middle; i >= start; --i)
    {
        leftSum += arr[i];
        leftMax = max(leftMax, leftSum);
    }
    for (int i = middle + 1; i <= end; ++i)
    {
        rightSum += arr[i];
        rightMax = max(rightMax, rightSum);
    }

    return max(max(leftMax, rightMax), leftMax + rightMax);
}
int main(void)
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
    fout << GetMax(arr, arr_size, 0, length) << endl;
    return 0;
}
