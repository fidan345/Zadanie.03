#include <iostream>
#include <vector>
using namespace std;

// Функция для слияния двух отсортированных частей массива
vector<int> mergeArrays(const vector<int>& left, const vector<int>& right) {
    vector<int> result;
    int i = 0, j = 0;

    // Сравниваем элементы из обеих частей и добавляем меньший в результат
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            result.push_back(left[i]);
            i++;
        } else {
            result.push_back(right[j]);
            j++;
        }
    }

    // Добавляем оставшиеся элементы (если есть)
    while (i < left.size()) {
        result.push_back(left[i]);
        i++;
    }

    while (j < right.size()) {
        result.push_back(right[j]);
        j++;
    }

    return result;
}

// Рекурсивная функция сортировки слиянием
vector<int> mergeSort(const vector<int>& arr) {
    // Базовый случай: массив длиной 0 или 1 уже отсортирован
    if (arr.size() <= 1)
        return arr;

    // Находим середину массива
    int mid = arr.size() / 2;

    // Делим массив на две части
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());

    // Рекурсивно сортируем каждую часть
    left = mergeSort(left);
    right = mergeSort(right);

    // Сливаем отсортированные части
    return mergeArrays(left, right);
}

// Функция для вывода массива
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Основная функция
int main() {
    vector<int> array = {38, 27, 43, 3, 9, 82, 10};

    cout << "Исходный массив: ";
    printArray(array);

    vector<int> sortedArray = mergeSort(array);

    cout << "Отсортированный массив: ";
    printArray(sortedArray);

    return 0;
}
