def silly_alg(tgt_text, tgt_len, tgt_iter1, tgt_iter2):
    word1 = tgt_text[tgt_iter1:tgt_iter1+tgt_len-1]
    word2 = tgt_text[tgt_iter2:tgt_iter2+tgt_len-1]
    if word1 == word2:
        return "yes"
    return "no"


def is_equal(tgt_text, tgt_len, tgt_iter1, tgt_iter2):
    # Строим базу
    h = [0] * (len(tgt_text) + 1)  # Хеш для префиксов
    p_module = 100#10**9 + 7  # модуль для облегчения подсчета
    x_probe = 10  # "Точка" для нахождения значения хеш-функции
    for i in range(1, len(h)):
        h[i] = ( h[i-1] * x_probe + ord(tgt_text[i-1]) ) % p_module

    print(h)



target = "acabaca"
is_equal(target, 4, 3, 2)
#print(silly_alg(target, 4, 3, 2))
#print(silly_alg(target, 3, 4, 0))
#print(silly_alg(target, 2, 0, 1))