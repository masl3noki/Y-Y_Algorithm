n, m = list(map(int, input().split(' ')))
nums = list(map(int, input().split(' ')))

# Константы для хеширования
P = 1000000007
h = {}
h[0] = 0
h_reverse = {}
h_reverse[0] = 0
x = {}
x[0] = 1

# Заполнение хеш-таблицы
for i in range(n):
    x[i+1] = (x[i]*(m+1)) % P
    h_reverse[i+1] = (h_reverse[i]*(m+1) + nums[n-i-1]) % P
    # Заполняем h до половины, т.к. дальше он не понадобится
    if i < n//2:
        h[i+1] = (h[i]*(m+1) + nums[i]) % P

# В зеркале не может быть больше кубиков, чем перед зеркалом, а значит
# terminate loop дальше n//2

answer = []
for i in range(n//2, 0, -1):
    if (h[i] == (h_reverse[n-i] - h_reverse[n-i-i]*x[i]) % P):
        answer.append(n-i)
answer.append(n)

print(' '.join(map(str, answer)))
