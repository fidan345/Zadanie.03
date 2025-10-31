#include <iostream>
#include <vector>
using namespace std;

// Функция интерполяционного поиска
int interpolationSearch(const vector<int>& arr, int lo, int hi, int x) {
    if (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
        // Вычисляем предполагаемую позицию
        int pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));

        // Проверяем, найден ли элемент
        if (arr[pos] == x)
            return pos;

        // Если x больше, ищем в правом подмассиве
        if (arr[pos] < x)
            return interpolationSearch(arr, pos + 1, hi, x);

        // Если x меньше, ищем в левом подмассиве
        if (arr[pos] > x)
            return interpolationSearch(arr, lo, pos - 1, x);
    }
    return -1; // Элемент не найден
}

int main() {
    vector<int> arr = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
    int n = arr.size();
    int x = 18; // Искомый элемент
    int result = interpolationSearch(arr, 0, n - 1, x);

    if (result != -1)
        cout << "Элемент найден на позиции: " << result << endl;
    else
        cout << "Элемент не найден" << endl;

    return 0;
}
