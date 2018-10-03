#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
#include<fstream>
using namespace std;
int selectionAlgorithm(int[], int, int, int);
int medianOfMedians(int[], int, int);
int arr[100000000];

int selectionAlgorithm(int arr[], int l, int r, int k)
{
    if(r-l+1 <= 5)
    {
        int i, j, v;
        for(i = l+1; i <= r; i++)
        {
            v = arr[i], j = i;
            while(j-1 >= l && arr[j-1] > v)
            {
                arr[j] = arr[j-1], j--;
            }
            arr[j] = v;
        }
        return l+k;
    }

    int pivot = medianOfMedians(arr, l, r);

    swap(arr[l], arr[pivot]);
    int i, j, t = arr[l];
    for(i = l, j = l+1; j <= r; j++)
    {
        if(arr[j] <= t)
        {
            i++, swap(arr[i], arr[j]);
        }
    }
    swap(arr[l], arr[i]);

    int position = i;
    if(position-l == k)
    {
        return position;
    }
    if(position-l < k)
    {
        return selectionAlgorithm(arr, position+1, r, k-(position-l+1));
    }
    else
    {
        return selectionAlgorithm(arr, l, position, k);
    }
}

int medianOfMedians(int arr[], int l, int r)
{
    int numMedians = (r-l+4)/5;
    int i, subl, subr;
    int medianIdx;
    for(i = 0; i < numMedians; i++)
    {
        subl = l + i*5;
        subr = subl + 4;
        if(subr > r)    subr = r;
        medianIdx = selectionAlgorithm(arr, subl, subr, (subr-subl)/2);
        swap(arr[l+i], arr[medianIdx]);
    }
    return selectionAlgorithm(arr, l, l+numMedians, numMedians/2);
}

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");

    int arr_size,data,target;
    fin >> arr_size;
    for(int i = 0; i < arr_size; i++)
    {
        fin >> data;
        arr[i] = data;
    }
    fin >> target;

    int idx = selectionAlgorithm(arr, 0, arr_size-1, target);
    fout << arr[target-1] << endl;

    return 0;
}
