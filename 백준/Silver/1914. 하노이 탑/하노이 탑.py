def hanoi(num, a, b, c):
    if num==1:
        print(a, c)
        return
    hanoi(num-1,a,c,b)
    print(a,c)
    hanoi(num-1,b,a,c)
    
result=0
input_num=int(input())
result=2**input_num-1
print(result)

if input_num <= 20:
    hanoi(input_num, 1, 2, 3)