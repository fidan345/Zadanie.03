#include <iostream>
#include <vector>
using namespace std;

// Функция для преобразования поддерева в кучу (heapify)
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;          // Инициализируем наибольший элемент как корень
    int left = 2 * i + 1;     // Левый дочерний элемент
    int right = 2 * i + 2;    // Правый дочерний элемент

    // Проверяем, существует ли левый дочерний элемент и больше ли он корня
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Проверяем, существует ли правый дочерний элемент и больше ли он текущего наибольшего
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Если наибольший элемент не корень — меняем местами и рекурсивно heapify вниз
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Основная функция пирамидальной сортировки
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Построение max-heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Извлечение элементов из кучи по одному
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]); // Меняем корень (максимум) с последним элементом
        heapify(arr, i, 0);   // Применяем heapify к уменьшенной куче
    }
}

// Функция для вывода массива
void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

// Основная функция
int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Исходный массив: ";
    printArray(arr);

    heapSort(arr);

    cout << "Отсортированный массив: ";
    printArray(arr);

    return 0;
}
