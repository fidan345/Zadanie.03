# Бинарный (двоичный) поиск
# Работает только с отсортированными массивами

def binary_search(array, target):
    left = 0               # Левая граница поиска
    right = len(array) - 1 # Правая граница поиска

    while left <= right:
        # Находим середину массива
        mid = left + (right - left) // 2

        # Проверяем средний элемент
        if array[mid] == target:
            return mid  # Элемент найден

        # Если искомый элемент меньше среднего — сдвигаем правую границу
        elif array[mid] > target:
            right = mid - 1

        # Если больше — сдвигаем левую границу
        else:
            left = mid + 1

    return -1  # Элемент не найден


# Пример использования
if __name__ == "__main__":
    sorted_array = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19]
    target = 7

    result = binary_search(sorted_array, target)

    if result != -1:
        print(f"Элемент найден на позиции: {result}")
    else:
        print("Элемент не найден")
