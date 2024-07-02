import math
import itertools

# input
a = int(input())
a_arr = [x for x in range(1, a+1)]
# main
combinations = math.factorial(a)
p = itertools.permutations(a_arr)
for j in list(p):

    #print(j)
    print("".join(map(str, j)))


