import math
a = []
n = int(input())

for i in range(0,n):
    temp = int(input())
    a.append(temp)


def checkPrime(number):
    for i in range(2,int(number/2)):
        # print(i)
        if number % i == 0:
            return 0
    return 1

def checkSquare(number):
    temp = math.sqrt(number)
    if int(temp + 0.5) ** 2 == number:
        return 1
    else:
        return 0

counter = 0
for t in a:
    if counter == 0:
        if checkPrime(t):
            

    
