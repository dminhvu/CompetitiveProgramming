#Generator=)))))))


st=str(input("Input something here: "))
MaxTimes=int(input("Input max times: "))
def CircleStringGen(s):
    while True:
        for hehe in list(s):
            yield hehe
c=CircleStringGen(st)
for i in range(MaxTimes):
    print(next(c))