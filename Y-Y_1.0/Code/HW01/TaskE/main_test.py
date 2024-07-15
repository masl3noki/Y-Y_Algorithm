def get_p_n(k, m, apparts_floor):
    p = (k - 1) // (apparts_floor * m) + 1
    n = (k - (p - 1) * apparts_floor * m - 1) // apparts_floor + 1
    return p, n


def decision_1(k1, m, k2, p2, n2):
    results_p = set()
    results_n = set()
    apparts_floor = 1
    while apparts_floor * (m * (p2 - 1) + (n2 - 1)) < k2 and apparts_floor < 100000:
        p, n = get_p_n(k2, m, apparts_floor)
        if p2 == p and n2 == n:
            p1, n1 = get_p_n(k1, m, apparts_floor)
            results_p.add(p1)
            results_n.add(n1)
        apparts_floor += 1

    if len(results_p) == 0:
        return -1, -1
    else:
        return (0 if len(results_p) > 1 else results_p.pop(),
                1 if m == 1 else (0 if len(results_n) > 1 else results_n.pop()))


# Измучался с избавлением о цикла. Результат получил, но переоптимизация заняла кучу времени и не дала эффект
def decision_2(k1, m, k2, p2, n2):
    # Смещение в этажах для k2-квартиры
    offset = (p2 - 1) * m + (n2 - 1)

    # Предположиттельно квартир на этаж (максимальное значение)
    apparts_floor_max = (k2 - 1) // offset

    # Проверим верно ли полченное значение квартир на этаже
    if apparts_floor_max == 0 or (k2 - 1) // apparts_floor_max != offset:
        return -1, -1

    # Предположительное минимальное значение квартира на этаж
    apparts_floor_min = (k2 - 1) // (offset + 1) + 1

    # Если не корректное значение, запишем в него корректное значение
    if (k2 - 1) // apparts_floor_min != offset:
        apparts_floor_max = apparts_floor_min

    # Вычислили возможные значения p и т для разных значений квартир на этаже
    p1_1, n1_1 = get_p_n(k1, m, apparts_floor_min)
    p1_2, n1_2 = get_p_n(k1, m, apparts_floor_max)

    return 0 if p1_1 != p1_2 else p1_1, 1 if m == 1 else (0 if n1_1 != n1_2 else n1_1)


k1, m, k2, p2, n2 = map(int, input().split())


if n2 > m:
    # Номер этажа не может быть больше количества этажей
    print(-1, -1)
elif n2 == 1 and p2 == 1:
    # Если первый подъезд и первый этаж в квартире k2, то можно не вычислять, а сразу дать ответ
    if k1 > k2:
        print(1 if k1 <= m else 0, 1 if m == 1 else 0)
    else:
        print(p2, n2)
else:
    print(*decision_2(k1, m, k2, p2, n2))