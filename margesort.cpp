#include <iostream>
using namespace std;

// Слияние двух отсортированных подмассивов
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Временные массивы
    int* L = new int[n1];
    int* R = new int[n2];

    // Копирование данных
    for (int i = 0; i < n1; i++)
     L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
     R[j] = arr[mid + 1 + j];

    // Слияние
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }

    // Остаток элементов
    while (i < n1)
     arr[k++] = L[i++];
    while (j < n2)
     arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

// Рекурсивная сортировка
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left +right)/2; 
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
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

    mergeSort(arr, 0, n-1);

    cout << "отсортированный массив : ";
    printArray(arr,n);

    delete[] arr;
    return 0;
}
    
   
    
