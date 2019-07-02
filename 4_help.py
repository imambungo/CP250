def factorial(aNumber):
    result = 1
    for i in range(2, aNumber+1):
        result *= i

    return result

def reverseNum(aNum):
    return int(str(aNum)[::-1])

def removeLeadingZero(aNum):
    return reverseNum(reverseNum(aNum))

def getLeadingZero(aNum):
    return len(str(aNum)) - len(str(removeLeadingZero(aNum)))

#f = open('data.out', 'r')
#isiFile = f.readlines()
#
#for i in isiFile:
#    print(factorial(int(i)-1))
#    print(factorial(int(i)))
#    print


leadingZero = 0
for i in range (1, 1025):
    newLeadingZero = getLeadingZero(factorial(i))
    if newLeadingZero > leadingZero:
        forPrint = str(i) + '\t= ' + str(leadingZero)

        if newLeadingZero - leadingZero > 1:
            forPrint += ' -> ' + str(newLeadingZero - leadingZero)

        leadingZero = newLeadingZero
        print(forPrint)
