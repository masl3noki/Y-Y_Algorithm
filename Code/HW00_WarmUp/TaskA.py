'''
A. Не минимум на отрезке
'''
"""
Задана последовательность целых чисел a1, a2, …, an. Задаются запросы: сказать любой элемент
последовательности на отрезке от L до R включительно, не равный минимуму на этом отрезке.

Формат ввода
В первой строке содержатся два целых числа N, 1 ≤ N ≤ 100 и M, 1 ≤ M ≤ 1000 — длина последовательности
и количество запросов соответственно.

Во второй строке — сама последовательность, 0 ≤ ai ≤ 1000.

Начиная с третьей строки перечисляются M запросов, состоящих из границ отрезка L и R,
где L, R - индексы массива, нумеруются с нуля.

Формат вывода
На каждый запрос выведите в отдельной строке ответ — любой элемент на [L, R], кроме минимального.
В случае, если такого элемента нет, выведите "NOT FOUND".

Пример 1
Ввод
10 5
1 1 1 2 2 2 3 3 3 10
0 1
0 3
3 4
7 9
3 7

Вывод
NOT FOUND
2
NOT FOUND
10
3

Пример 2
Ввод
4 2
1 1 1 2
0 2
0 3

Вывод
NOT FOUND
2

"""

# input
n, m = map(int, input().split(sep=" "))
nums = input().split(sep=" ")

# initialisation
ar = []
for i in nums:
    ar.append(int(i))

# loop for each request (known number of requests)
for request in range(m):
    # input
    L, R = map(int, input().split(sep=" "))

    # get subarray depending on L&R and find min element
    targetAr = ar[L:R+1]
    minEl = min(targetAr)

    # get any element != min => print first element > min
    flagFounded = False
    for j in targetAr:
        if (j > minEl):
            print(j)
            flagFounded = True
            break

    if (not flagFounded): print("NOT FOUND")
