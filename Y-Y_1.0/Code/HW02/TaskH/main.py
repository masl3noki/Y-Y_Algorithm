def sol(a):
	a.sort() # Попробуем отсортировать, мб зайдет

	Mx1 = a[-1]
	mx2 = a[-2]
	mx3 = a[-3]

	mn1 = a[0]
	mn2 = a[1]

	mul1 = Mx1 * mx2 * mx3
	mul2 = Mx1 * mn1 * mn2
	if mul1 > mul2:
		print(Mx1, mx2, mx3)
	else:
		print(Mx1, mn1, mn2)

def main():
    a = list(map(int, input().split()))

    sol(a)
	
if __name__ == "__main__":
	main()