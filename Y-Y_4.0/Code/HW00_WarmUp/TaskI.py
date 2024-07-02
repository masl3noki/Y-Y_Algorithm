# Инициализация структуры
open_list = ["[", "{", "("]
close_list = ["]", "}", ")"]


# Используя стек, проверим на сохранение порядка
def isValid(line):
    stack = []
    for i in line:
        if i in open_list:
            stack.append(i)
        elif i in close_list:
            pos = close_list.index(i)
            if ((len(stack) > 0) and
                    (open_list[pos] == stack[len(stack) - 1])):
                stack.pop()
            else:
                return False
    if len(stack) == 0:
        return True
    else:
        return False


# main
line = input()
if isValid(line):
    print("yes")
else:
    print("no")