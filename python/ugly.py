
def isUgly(num):
    for p in 2,3,5:
        while num%p==0 and num>0:
            num /= p;
    return num == 1;

assert isUgly(55) == False
assert isUgly(2) == True
assert isUgly(14) == False

