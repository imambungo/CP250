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

############################################################
def theNewGetLeadingZero(aNum):
    totalLeadingZero = 0
    i = 5
    while i <= aNum:
        # In Python 3.0, 5 / 2 will return 2.5 and 5 // 2 will return 2
        totalLeadingZero += aNum//i 
        i *= 5

    return totalLeadingZero
############################################################

leadingZero = 0
for i in range (1, 101):
    #newLeadingZero = getLeadingZero(factorial(i))
    newLeadingZero = theNewGetLeadingZero(i)
    if newLeadingZero > leadingZero:
        forPrint = str(i) + '\t= ' + str(newLeadingZero)

        if newLeadingZero - leadingZero > 1:
            forPrint += ' -> ' + str(newLeadingZero - leadingZero)

        leadingZero = newLeadingZero
        print(forPrint)
