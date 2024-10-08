# F. Продажи

[]()|[]()
-------------------|---
Ограничение времени|	1 секунда
Ограничение памяти |	256Mb
Ввод               |	стандартный ввод или input.txt
Вывод              |	стандартный вывод или output.txt
[]()|[]()

## Условие задачи
Дана база данных о продажах некоторого интернет-магазина. Каждая строка входного файла представляет собой запись вида Покупатель товар количество, где Покупатель — имя покупателя (строка без пробелов), товар — название товара (строка без пробелов), количество — количество приобретенных единиц товара.

Создайте список всех покупателей, а для каждого покупателя подсчитайте количество приобретенных им единиц каждого вида товаров.

## Формат ввода
Вводятся сведения о покупках в указанном формате.

## Формат вывода
Выведите список всех покупателей в лексикографическом порядке, после имени каждого покупателя выведите двоеточие, затем выведите список названий всех приобретенных данным покупателем товаров в лексикографическом порядке, после названия каждого товара выведите количество единиц товара, приобретенных данным покупателем. Информация о каждом товаре выводится в отдельной строке.

### Пример 1
Ввод | Вывод
---| ---
Ivanov paper 10 <br>Petrov pens 5<br>Ivanov marker 3<br>Ivanov paper 7<br>Petrov envelope 20<br>Ivanov envelope 5 <br><br>| Ivanov:<br>envelope 5<br>marker 3<br>paper 17<br>Petrov:<br>envelope 20<br>pens 5
[]()|[]()

### Пример 2
Ввод | Вывод
---| ---
Ivanov aaa 1<br>Petrov aaa 2<br>Sidorov aaa 3<br>Ivanov aaa 6<br>Petrov aaa 7<br>Sidorov aaa 8<br>Ivanov bbb 3<br>Petrov bbb 7<br>Sidorov aaa 345<br>Ivanov ccc 45<br>Petrov ddd 34<br>Ziborov eee 234<br>Ivanov aaa 45 | Ivanov:<br>aaa 52<br>bbb 3<br>ccc 45<br>Petrov:<br>aaa 9<br>bbb 7<br>ddd 34<br>Sidorov:<br>aaa 356<br>Ziborov:<br>eee 234<br><br>
[]()|[]()

### Пример 3
<details>
<summary> Раскрыть </summary>

Ввод | Вывод
---| ---
TKSNUU FKXYPUGQ 855146<br> TKSNUU FKXYPUGQ 930060<br> TKSNUU FKXYPUGQ 886973<br> TKSNUU FKXYPUGQ 59344<br> TKSNUU FKXYPUGQ 296343<br> TKSNUU KXYPUGQ 193166<br> TKSNUU FKXYPUGQ 211696<br> TKSNUU FKXYPUGQ 821064<br> TKSNUU FKXYPUGQ 672846<br> TKSNUU FKXYPUGQ 820341<br> TKSNUU FKXYPUGQ 350693<br> TKSNUU FKXYPUGQ 469538<br> TKSNUU FKXYPUGQ 849069<br> TKSNUU FKXYPUGQ 502007<br> TKSNUU FKXYPUGQ 961595<br> TKSNUU FKXYPUGQ 747271<br> TKSNUU FKXYPUGQ 863648<br> TKSNUU FKXYPUGQ 952069<br> TKSNUU FKXYPUGQ 286019<br> TKSNUU FKXYPUGQ 364841<br> TKSNUU FKXYPUGQ 455930<br> TKSNUU FKXYPUGQ 100486<br> TKSNUU FKXYPUGQ 335026<br> TKSNUU FKXYPUGQ 197672<br> TKSNUU FKXYPUGQ 217640<br> TKSNUU FKXYPUGQ 612549<br> TKSNUU FKXYPUGQ 622501<br> TKSNUU FKXYPUGQ 96554<br> TKSNUU FKXYPUGQ 327166<br> TKSNUU FKXYPUGQ 425399<br> TKSNUU FKXYPUGQ 362309<br> TKSNUU FKXYPUGQ 78477<br> TKSNUU FKXYPUGQ 258916<br> TKSNUU FKXYPUGQ 297923<br> TKSNUU FKXYPUGQ 8891<br> TKSNUU FKXYPUGQ 13639<br> TKSNUU FKXYPUGQ 77308<br> TKSNUU FKXYPUGQ 707620<br> TKSNUU FKXYPUGQ 68205<br> TKSNUU FKXYPUGQ 256702<br> TKSNUU FKXYPUGQ 668334<br> TKSNUU FKXYPUGQ 968673<br> TKSNUU FKXYPUGQ 138125<br> TKSNUU FKXYPUGQ 222904<br> TKSNUU FKXYPUGQ 214091<br> TKSNUU FKXYPUGQ 500231<br> TKSNUU FKXYPUGQ 19611<br> TKSNUU FKXYPUGQ 491343<br> TKSNUU FKXYPUGQ 404307<br> TKSNUU FKXYPUGQ 68367<br> TKSNUU FKXYPUGQ 287107<br> TKSNUU FKXYPUGQ 794935<br> TKSNUU FKXYPUGQ 254217<br> TKSNUU FKXYPUGQ 206370<br> TKSNUU FKXYPUGQ 202761<br> TKSNUU FKXYPUGQ 929017<br> TKSNUU FKXYPUGQ 843359<br> TKSNUU FKXYPUGQ 955269<br> TKSNUU FKXYPUGQ 134139<br> TKSNUU FKXYPUGQ 946168<br> TKSNUU FKXYPUGQ 967781<br> TKSNUU FKXYPUGQ 856474<br> TKSNUU FKXYPUGQ 465070<br> TKSNUU FKXYPUGQ 580526<br> TKSNUU FKXYPUGQ 172109<br> TKSNUU FKXYPUGQ 191703<br> TKSNUU FKXYPUGQ 207916<br> TKSNUU FKXYPUGQ 512264<br> TKSNUU FKXYPUGQ 533081<br> TKSNUU FKXYPUGQ 577208<br> TKSNUU FKXYPUGQ 831389<br> TKSNUU FKXYPUGQ 439158<br> TKSNUU FKXYPUGQ 565633<br> TKSNUU FKXYPUGQ 452643<br> TKSNUU FKXYPUGQ 164426<br> TKSNUU FKXYPUGQ 540743<br> TKSNUU FKXYPUGQ 880704<br> TKSNUU FKXYPUGQ 868529<br> TKSNUU FKXYPUGQ 240742<br> TKSNUU FKXYPUGQ 868865<br> TKSNUU FKXYPUGQ 910442<br> TKSNUU FKXYPUGQ 146737<br> TKSNUU FKXYPUGQ 820984<br> TKSNUU FKXYPUGQ 660948<br> TKSNUU FKXYPUGQ 957975<br> TKSNUU FKXYPUGQ 135847<br> TKSNUU FKXYPUGQ 401865<br> TKSNUU FKXYPUGQ 982859<br> TKSNUU FKXYPUGQ 748454<br> TKSNUU FKXYPUGQ 354734<br> TKSNUU FKXYPUGQ 525638<br> TKSNUU FKXYPUGQ 119140<br> TKSNUU FKXYPUGQ 484816<br> TKSNUU FKXYPUGQ 616539<br> TKSNUU FKXYPUGQ 682553<br> TKSNUU FKXYPUGQ 841541<br> TKSNUU FKXYPUGQ 713063<br> TKSNUU FKXYPUGQ 433453<br> TKSNUU FKXYPUGQ 465340<br> TKSNUU FKXYPUGQ 985635 | TKSNUU:<br>FKXYPUGQ 49769497 <br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
[]()|[]()

</details>