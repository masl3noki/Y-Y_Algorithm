# E. Пирамида

[]()|[]()
-------------------|---
Ограничение времени|	1 секунда
Ограничение памяти |	64Mb
Ввод               |	стандартный ввод или input.txt
Вывод              |	стандартный вывод или output.txt
[]()|[]()

## Условие задачи
Для строительства двумерной пирамиды используются прямоугольные блоки, каждый из которых характеризуется шириной и высотой.
Можно поставить один блок на другой, только если ширина верхнего блока строго меньше ширины нижнего (блоки нельзя поворачивать). Самым нижним в пирамиде может быть блок любой ширины.
По заданному набору блоков определите, пирамиду какой наибольшей высоты можно построить из них.

## Формат ввода
В первой строке входных данных задается число $N$ — количество блоков $(1 \leq N \leq 100000$.
В следующих $N$ строках задаются пары натуральных чисел $w_i$ и $h_i\ (1 \leq w_i, h_i \leq 10^9)$ — ширина и высота блока соответственно.

## Формат вывода
Выведите одно целое число — максимальную высоту пирамиды.

### Пример 1
Ввод | Вывод
---| ---
3 <br> 3 1 <br> 2 2 <br> 3 3 | 5 <br> <br> <br> <br>
[]()|[]()

## Примечания
В примере пирамида будет состоять из двух блоков: нижним блоком будет блок номер 3, а верхним — блок номер 2. Блок номер 1 нельзя использовать вместе с блоком номер 3.
