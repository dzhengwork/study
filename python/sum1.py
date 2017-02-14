

sum = 0
fh = open("sum1.txt", 'r')
for line in fh:
	l = line.split(' ')
	if len(l) > 3:
		sum += int(l[3])


print sum

