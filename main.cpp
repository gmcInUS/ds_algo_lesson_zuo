#include <iostream>
using namespace std;

// 选择排序，时间复杂度O(N^2)，空间复杂度O(1)
// 0~N-1, 1~N-1, 2~N-1上不断找出最小值的Index然后将它与0,1,2交换
class SelectionSort
{
public:
    SelectionSort(int arr[], int arrLength){
        if (arr == nullptr || arrLength<2){
            return;
        }
        for (int i=0; i<arrLength-1; i++){
            // i from 0 to N-1
            int minIndex = i;
            for (int j=i+1; j<arrLength; j++){
                // i ~ N-1上找最小值的下标
                minIndex = arr[j] < arr[minIndex] ? j : minIndex;
            }
            swap(arr, i, minIndex);
        }
    };

    void swap(int arr[], int i, int j){
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    };
};

// 冒泡排序，时间复杂度O(N^2),空间复杂度O(1)
// 0~N, 0~N-1, 0~N-2上不断两两对比把最大的值放到N,N-1,N-2位置上
class BubbleSort
{
public:
    BubbleSort(int arr[], int arrLength){
        if (arr == nullptr || arrLength<2){
            return;
        }
        for (int e = arrLength-1; e>0; e--){
            // 0~e
            for (int i=0; i<e; i++){
                if (arr[i]>arr[i+1]){
                    swap(arr,i,i+1);
                }
            }
        }
    };

    void swap(int arr[], int i, int j){
        // 两个值必须是在不同的两块内存，即i不能等于j否则会变成0
        arr[i] = arr[i]^arr[j];
        arr[j] = arr[i]^arr[j];
        arr[i] = arr[i]^arr[j];
    };
};

void printArray(int arr[], int arrLength){
    for (int i=0;i<arrLength;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    cout << "Hello!" << endl;
    int myArr[5] = {1,4,3,2,5};
    int len = *(&myArr+1)-myArr; // 或者 sizeof(myArr)/sizeof(myArr[0])
    cout << "Before sorting: " << endl;
    printArray(myArr, len);
    //SelectionSort selectSort(myArr,len);
    BubbleSort bubbleSort(myArr, len);
    cout << "After sorting: " << endl;
    printArray(myArr,len);
    int a=1;
    cout << "a is:" << a << endl;
    return 0;
    
}