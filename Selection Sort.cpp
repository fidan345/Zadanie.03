#include <iostream>
#include <vector>
using namespace std;

void selection_sort(vector<int>& arr) {
    int n = arr.size();
    // Проходим по всем элементам массива
    for (int i = 0; i < n; i++) {
        // Предполагаем, что первый элемент — минимальный
        int min_index = i;

        // Ищем минимальный элемент в оставшейся части массива
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        // Меняем найденный минимальный элемент с текущим
        swap(arr[i], arr[min_index]);
    }
}

int main() {
    // Создаём тестовый массив
    vector<int> test_array = {64, 25, 12, 22, 11};

    cout << "Исходный массив: ";
    for (int x : test_array) cout << x << " ";
    cout << endl;

    // Сортируем массив
    selection_sort(test_array);

    cout << "Отсортированный массив: ";
    for (int x : test_array) cout << x << " ";
    cout << endl;

    return 0;
}
