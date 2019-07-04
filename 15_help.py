pangkat = 30
base = 20
for b in range(1, pangkat+1):
    for a in range(1, base+1):
        print((a**b)%10, "\t", sep='', end='')
    print('^', b, sep='')
