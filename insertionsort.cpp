#include <iostream>
using namespace std; 

// Функция слияния двух отсортированных подмассивов
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Выделяем память для временных массивов
    int* L = new int[n1];
    int* R = new int[n2];

    // Копируем данные во временные массивы
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }
    // Слияние временных массивов обратно в arr[]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        } 
        else
        {
            arr[k++] = R[j++];
        }
    }

    // Копируем оставшиеся элементы
    while (i < n1)
    {
        arr[k++] = L[i++];
    }
    while (j < n2)
    { 
        arr[k++] = R[j++];
    }
    // Освобождаем память
    delete[] L;
    delete[] R;
}

// Рекурсивная функция сортировки слиянием
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // Сортируем первую и вторую половины
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Сливаем отсортированные половины
        merge(arr, left, mid, right);
    }
}

// ВЫвод массива
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    
    cout << "количество элементов : ";
    cin >> n;

    int* arr = new int[n];

    cout << "элементы в массиве : ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "исходный массив: ";
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);  

    cout << "отсортированный массив : ";
    printArray(arr, n);

    delete[] arr;
    return 0;
}