def silly_alg(tgt_text, tgt_len, tgt_iter1, tgt_iter2):
    word1 = tgt_text[tgt_iter1:tgt_iter1+tgt_len-1]
    word2 = tgt_text[tgt_iter2:tgt_iter2+tgt_len-1]
    if word1 == word2:
        return "yes"
    return "no"


def is_equal(from1, from2, slen, h, x):
    return (
        (h [from1 + slen - 1] + h[from2 - 1] * x[slen]) % p_module ==
        (h [from2 + slen - 1] + h[from1 - 1] * x[slen]) % p_module
    )

# Вносим данные
tgt_text = input()
Q = int(input())

# Обработка запросов
for i in range(Q):

    txt_len, from1, from2 = map(int, (input().split(sep=" ")))

    # Строим базу
    n = len(tgt_text)  # длина строки
    h = [0] * (n + 1)  # Хеш (массив) для префиксов
    p_module = 10 ** 9 + 7  # высокое простое число - модуль для облегчения подсчета
    x_probe = 10#257  # "Точка" для нахождения значения хеш-функции (> размера алфавита)
    x = [0] * (n + 1)  # массив степеней x (aka полином)
    x[0] = 1  # x_0 = a^0 => x_0 = 1
    tgt_text = ' ' + tgt_text
    for i in range(1, n + 1):  # Заполняем Хеш и массив степеней x за O(n)
        h[i] = (h[i - 1] * x_probe + ord(tgt_text[i])) % p_module
        x[i] = (x[i - 1] * x_probe) % p_module

    print(h)
    print(x)

    print("yes" if is_equal(from1, from2, txt_len, h, x) else "no")



target = "acabaca"
#print(silly_alg(target, 4, 3, 2))
#print(silly_alg(target, 3, 4, 0))
#print(silly_alg(target, 2, 0, 1))