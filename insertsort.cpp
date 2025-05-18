#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];  // элемент для вставки
        int j = i - 1;

        // сдвигаем элементы, которые больше key, вправо
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        // вставляем key на нужное место
        arr[j + 1] = key;
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

    insertionSort(arr, n);

    cout << "отсортированный массив : ";
    printArray(arr,n);

    delete[] arr;
    return 0;
}