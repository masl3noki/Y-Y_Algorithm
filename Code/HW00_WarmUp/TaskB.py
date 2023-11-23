'''
Сложить две дроби
'''
"""
Даны две рациональные дроби: a/b и c/d. Сложите их и результат представьте в виде несократимой дроби m/n.

Формат ввода
Программа получает на вход 4 натуральных числа a, b, c, d, каждое из которых не больше 100.

Формат вывода
Программа должна вывести два натуральных числа m и n такие, что m/n=a/b+c/d и дробь m/n – несократима.

Пример
Ввод	
1 2 1 2

Вывод
1 1
"""

# здесь Вы пишете свой код

class Float:

    def __init__(self, numerator, denominator):
        self.__numerator__ = numerator
        self.__denominator__ = denominator

    def __findMultipliers__(self, number):
        """
        Поиск множителей
        :param number: числитель или знаменатель
        :return: массив уникальных множителей
        """
        arr = []

        if number == 0:
            return None

        while number != 1:
            i = 2
            while number % i != 0:
                i += 1
            arr.append(i)
            number /= i

        arr.append(1)

        return arr

    def __sortMinMax__(self, arr):
        """
        for i in range(len(arr)):
            for j in range(len(arr)-1):
                if arr[j] > arr[j+1]:
                    buff = arr[j]
                    arr[j] = arr[j+1]
                    arr[j+1] = buff

        return arr
        """
        return sorted(arr)

    def __simplify__(self):
        """
        Упрощение дроби (перевод в несократимый вид)
        :return: None
        """
        arrNum = self.__sortMinMax__(self.__findMultipliers__(self.__numerator__))
        arrDen = self.__sortMinMax__(self.__findMultipliers__(self.__denominator__))

        for i in arrNum:
            if i in arrDen:
                arrNum.remove(i)
                arrDen.remove(i)

        for j in arrDen:
            if j in arrNum:
                arrNum.remove(j)
                arrDen.remove(j)

        self.__numerator__ = 1
        self.__denominator__ = 1

        for i in arrNum:
            self.__numerator__ *= i

        for j in arrDen:
            self.__denominator__ *= j

    def numerator(self, number=None):
        """
        Вернуть числитель
        :param number: None по умолчанию. Иначе любой int - тогда изменится числитель
        :return: int числитель (по умолчанию), иначе None
        """
        if number is None:
            return self.__numerator__
        else:
            self.__numerator__ = number
            self.__simplify__()

    def denominator(self, number=None):
        """
        Вернуть знаменатель
        :param number: None по умолчанию. Иначе любой int - тогда изменится знаменатель
        :return: int знаменатель (по умолчанию), иначе None
        """
        if number is None:
            return self.__denominator__
        else:
            self.__denominator__ = number
            self.__simplify__()

    def __add__(self, other):
        if (self.denominator() == other.denominator()):
            num = self.numerator() + other.numerator()
            return Float(num, self.denominator())

        # если все плохо, то идем напролом
        self.__simplify__()
        other.__simplify__()

        den1 = self.denominator()
        den2 = other.denominator()

        self.__numerator__ *= den2
        self.__denominator__ *= den2
        other.__numerator__ *= den1
        other.__denominator__ *= den1

        num = self.__numerator__ + other.__numerator__
        return Float(num, self.__denominator__)


    def __str__(self):
        return str(self.__numerator__)+" "+str(self.__denominator__)

    def __repr__(self):
        return ("Fraction(" + str(self.__numerator__) + ", " + str(self.__denominator__) + ")")


# input
a, b, c, d = map(int, input().split(sep=" "))

flt_1 = Float(a, b)
flt_2 = Float(c, d)

flt_3 = flt_1 + flt_2
flt_3.__simplify__()

print(flt_3)

