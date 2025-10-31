# Быстрая сортировка (Quick Sort)
# Алгоритм выбирает опорный элемент и рекурсивно сортирует элементы слева и справа от него

def quick_sort(array, low, high):
    if low < high:
        # pi — индекс разделения, array[pi] находится на своём месте
        pi = partition(array, low, high)

        # Сортируем элементы до и после разделения
        quick_sort(array, low, pi - 1)
        quick_sort(array, pi + 1, high)


def partition(array, low, high):
    # Выбираем последний элемент как опорный
    pivot = array[high]
    i = low - 1  # Индекс меньшего элемента

    for j in range(low, high):
        # Если текущий элемент меньше или равен опорному
        if array[j] <= pivot:
            i += 1
            # Меняем местами элементы array[i] и array[j]
            array[i], array[j] = array[j], array[i]

    # Меняем местами опорный элемент и элемент после последнего меньшего
    array[i + 1], array[high] = array[high], array[i + 1]

    return i + 1


def print_array(array):
    for value in array:
        print(value, end=" ")
    print()


# Основной блок программы
if __name__ == "__main__":
    array = [10, 7, 8, 9, 1, 5]
    print("Исходный массив:")
    print_array(array)

    quick_sort(array, 0, len(array) - 1)

    print("\nОтсортированный массив:")
    print_array(array)
