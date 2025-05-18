#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // индекс минимального элемента в неотсортированной части

        // Ищем минимальный элемент в подмассиве arr[i+1..n-1]
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Меняем местами текущий элемент и найденный минимум
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}


//Функция вывода массива 
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

   selectionSort(arr, n);

    cout << "отсортированный массив : ";
    printArray(arr,n);

    delete[] arr;
    return 0;
}
