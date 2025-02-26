inp=input()
inp=inp.split()
month_days = (31,28,31,30,31,30,31,31,30,31,30,31)
day_sum=0
i=int(inp[0])
for j in range(i-1):
    day_sum+=month_days[j]
day_sum+=int(inp[1])
#print(day_sum)

mod_week=day_sum%7 #일주일인 7로 나눈 나머지만큼이 요일이다

match mod_week:
    case 1:
        print("MON")
    case 2:
        print("TUE")
    case 3:
        print("WED")
    case 4:
        print("THU")
    case 5:
        print("FRI")
    case 6:
        print("SAT")
    case 0:
        print("SUN")
