#include <iostream>
#include <chrono>

using namespace std::chrono;
int partition(int arr[], int low, int high)
{
    int i=low+1, j = high;
    while(1)
    {
        while(arr[low] > arr[i] && i<high)
        {
            i++;
            std::cout << i;
        }
        while(arr[low] < arr[j] && j>low)
        {
            j--;
            std::cout << j;
        }
        if(i>=j)
        break;
        if(low<high)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    
    return j;
}
void quick_sort(int arr[], int low, int high)
{
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}
void merge(int* array[], int low, int mid, int high)
{
    int *arr = *array;
    int a[mid-low+1];
    int b[high-mid];
    for (int i=low; i<mid+1; i++)
    {
        a[i-low] = arr[i];
    }
    for (int i=mid+1; i<=high; i++)
    {
        b[i-mid-1] = arr[i];
    }
    int index1 = 0, index2 = 0, index = low;
    while(index1<(mid-low+1) && index2<(high-mid))
    {
        if((a[index1] <= b[index2]))
        {
            arr[index++] = a[index1++];
        }
        else
        {
            arr[index++] = b[index2++];
        }
    }
    while(index1 < mid-low+1)
    {
        arr[index++] = a[index1++];
    }
    while(index2<(high-mid))
    {
        arr[index++] = b[index2++];
    }
}
void merge_sort(int* arr[], int low, int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}
int main()
{
    int size;
    std::cout << "Enter the size of array: ";
    std::cin >> size;
    int *arr = new int[size];
    for (int i=0; i<size; i++)
    {
        arr[i] = (i*98)%size;
    }
    auto start = high_resolution_clock::now();
    for (int i=0; i<size; i++)
    {
        std::cout << arr[i] << " ";
    }std::cout << std::endl;
    quick_sort(arr, 0, size-1);
    for (int i=0; i<size; i++)
    {
        std::cout << arr[i] << " ";
    }std::cout << std::endl;
    auto end = high_resolution_clock::now();
    auto duration = duration_cast <microseconds>(end - start);
    std::cout << "Time taken by quick_sort is " << duration.count() << " microseconds" << std::endl;

    start = high_resolution_clock::now();
    merge_sort(&arr, 0, size);
    end = high_resolution_clock::now();
    duration = duration_cast <microseconds>(end - start);
    std::cout << "Time taken by merge_sort is " << duration.count() << " microseconds" << std::endl;
}