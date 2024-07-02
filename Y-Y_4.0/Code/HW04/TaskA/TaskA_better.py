from math import factorial
# Вообще была идея создать рекурсию: если дано число n, то спускаемся сначала для n!/n одинаковых чисел,
# для каждой такой цифры у нас еще (n-1)!/(n-1) следующих цифр и т.д. Последняя итерация - 2!/2.
# Внутри каждой строки пишем оставшуюся цифру (все цифры уникальны и в количестве n).


# Если в контесте выпадает ML, то одно из решений - сразу печатать строки, не сохраняя их
def lexicographical_permutations(arr):
    # Из комбинаторики известно, что количество перестановок без повторения равно n!
    for p in range(factorial(len(arr))):
        # Вывод *предыдущей* строки
        print(''.join(arr))

        # Далее идет лишь построение следующей строки
        i = len(arr) - 1

        # Сохранение лексикографического порядка
        while i > 0 and arr[i-1] > arr[i]:
            i -= 1

        arr[i:] = reversed(arr[i:])

        if i > 0:
            q = i
            while arr[i-1] > arr[q]:
                q += 1

            temp = arr[i-1]
            arr[i-1] = arr[q]
            arr[q] = temp


# input
a = int(input())

# main
a_arr = [str(x) for x in range(1, a+1)]
lexicographical_permutations(a_arr)
