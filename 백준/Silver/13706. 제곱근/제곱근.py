a=int(input())
s=1
e=a

while(s<=e):
    m=(s+e)//2
    total=m**2

    if total==a:
        print(m)
        break
    elif total<a :
        s=m+1
    elif total>a:
        e=m-1

