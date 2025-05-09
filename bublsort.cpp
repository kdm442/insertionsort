#include<iostream>
using namespace std;

// функция обмена двух элементов
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// функция сортировки пузырьком
void bubble_sort(int* a, size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}





//функция вывода массива 
void printArray(const int* arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int n;
    

    cout << "количество элементов : ";
    cin >> n;

    int* arr = new int[n];

    cout << "элементы в массиве : ";
    for (int i = 0;i < n; i++){
        cin >> arr[i];
    }

    cout << "исходный массив: ";
    printArray(arr, n);

    bubble_sort(arr, n);

    cout << "отсортированный массив : ";
    printArray(arr,n);

    delete[] arr;
    return 0;
}