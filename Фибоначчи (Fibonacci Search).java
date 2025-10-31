public class FibonacciSearch {

    // Функция поиска Фибоначчи
    public static int fibonacciSearch(int[] arr, int x) {
        int n = arr.length;

        // Инициализируем числа Фибоначчи
        int fibM2 = 0; // (m-2)'е число Фибоначчи
        int fibM1 = 1; // (m-1)'е число Фибоначчи
        int fibM = fibM2 + fibM1; // m'е число Фибоначчи

        // Находим наименьшее число Фибоначчи, большее или равное n
        while (fibM < n) {
            fibM2 = fibM1;
            fibM1 = fibM;
            fibM = fibM2 + fibM1;
        }

        // Смещение для исключённых элементов
        int offset = -1;

        // Пока есть элементы для проверки
        while (fibM > 1) {
            // Проверяем возможный индекс
            int i = Math.min(offset + fibM2, n - 1);

            // Если x больше, сдвигаем три числа Фибоначчи вниз (правый подмассив)
            if (arr[i] < x) {
                fibM = fibM1;
                fibM1 = fibM2;
                fibM2 = fibM - fibM1;
                offset = i;
            }

            // Если x меньше, сдвигаем два числа вниз (левый подмассив)
            else if (arr[i] > x) {
                fibM = fibM2;
                fibM1 = fibM1 - fibM2;
                fibM2 = fibM - fibM1;
            }

            // Элемент найден
            else {
                return i;
            }
        }

        // Проверяем последний возможный элемент
        if (fibM1 == 1 && offset + 1 < n && arr[offset + 1] == x)
            return offset + 1;

        // Элемент не найден
        return -1;
    }

    // Основной метод
    public static void main(String[] args) {
        int[] arr = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100};
        int x = 85;

        int result = fibonacciSearch(arr, x);

        if (result != -1)
            System.out.println("Элемент найден на позиции: " + result);
        else
            System.out.println("Элемент не найден");
    }
}
