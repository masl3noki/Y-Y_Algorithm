def triangle(items):
    '''
    Решение задачи

        Parameters:
            items (list<tuple<int, string>): Список наблюдений Максима
        
        Returns:
            solution (tuple<int, int>): Интервал, в котором лежат частоты

        Note:   Цикл, в котором ищем число x:
            Шаг 1) Определить положение точек prev, curr (определяет bool isLess)
                *) Если равны, то prev=curr, иначе шаг 2)
            Шаг 2) Если информация, что curr "ближе" подтверждается в двух источниках (isLess и bool isCloser, который обрабатывает ввод), то 
                   x может находиться (30.0; \eta), где \eta = |a-b|/2, либо 4000.0 (смотря что меньше)
                *) Иначе, если curr "абсолютно дальше", т.е. (!isLess && !isCloser) == true, то все ровно наоборот.
                   Другие случаи не интересны
    '''
    freq_min = 30
    freq_max = 4000
    freq_prev = items[0][0]
    for i in range(1, len(items)):
        # Инициализация
        freq, nearness = items[i]
        isCloser = (nearness == 'closer')
        isLess = (freq < freq_prev)

        if freq != freq_prev:
            if (isCloser and isLess) or (not isCloser and not isLess):
                freq_max = max(freq_min, min((freq_prev + freq) / 2, freq_max))
            else:
                freq_min = min(freq_max, max((freq_prev + freq) / 2, freq_min))

        freq_prev = freq

    return [freq_min, freq_max]

def main():
    # Инициализация
    n = int(input())
    input_items = []
    for _ in range(n):
        input_item = input().split()
        input_items.append((float(input_item[0]), input_item[1] if len(input_item) > 1 else None))
    
    # Тело
    result = triangle(input_items)
    print(f'{result[0]:.6f} {result[1]:.6f}') # Точность не хуже 10**-6


if __name__ == '__main__':
    main()