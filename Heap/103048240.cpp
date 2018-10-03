#include<iostream>
#include<fstream>
using namespace std;
int arr[100000000];

void heapify(int arr[], int n, int i)
{
    int largest = i,
    l = 2*i + 1,
    r = 2*i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for(int i = n/2-1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for(int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
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
    heapSort(arr,arr_size);

    fout << arr[target-1] << endl;

    return 0;
}
