# I. Сапер

[]()|[]()
-------------------|---
Ограничение времени|	1 секунда
Ограничение памяти |	64Mb
Ввод               |	стандартный ввод или input.txt
Вывод              |	стандартный вывод или output.txt
[]()|[]()

## Условие задачи
Вам необходимо построить поле для игры "Сапер" по его конфигурации – размерам и координатам расставленных на нем мин.

Вкратце напомним правила построения поля для игры "Сапер":

>Поле состоит из клеток с минами и пустых клеток;
>
>Клетки с миной обозначаются символом $*$;
>
>Пустые клетки содержат число $k_{i,j}: 0≤ k_{i, j} ≤ 8$ – количество мин на соседних клетках. Соседними клетками являются восемь клеток, имеющих смежный угол или сторону.

## Формат ввода
В первой строке содержатся три числа: $N, 1 ≤ N ≤ 100$ - количество строк на поле, $M, 1 ≤ M ≤ 100$ - количество столбцов на поле, $K, 0 ≤ K ≤ N \times M$ - количество мин на поле.

В следующих $K$ строках содержатся по два числа с координатами мин: $p, 1 ≤ p ≤ N$ - номер строки мины, $q, 1 ≤ 1 ≤ M$ - номер столбца мины.

## Формат вывода
Выведите построенное поле, разделяя строки поля переводом строки, а столбцы - пробелом.

### Пример 1
Ввод|Вывод
---|---
3 2 2<br>1 1<br>2 2|* 2<br>2 *<br>1 1<br>
[]()

### Пример 2
Ввод|Вывод
---|---
2 2 0<br><br>|0 0<br>0 0
[]()

### Пример 3
Ввод|Вывод
---|---
4 4 4<br>1 3<br>2 1<br>4 2<br>4 4|1 2 * 1<br>* 2 1 1<br>2 2 2 1<br>1 * 2 *<br><br>
[]()