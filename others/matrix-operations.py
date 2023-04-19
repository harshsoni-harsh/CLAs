def rotate(m, times):
    temp=[]
    for i in m:
        temp1=[]
        for j in i:
            temp1.append(j)
        temp.append(temp1)
    
    i=len(m)-1
    j=len(m[0])-1
    times = int(int(times)/90)
    times%=4
    if(times==1):
        for a in range(i+1):
            for b in range(j+1):
                temp[a][b] = m[j-b][a]
    elif(times==2):
        for a in range(i+1):
            for b in range(j+1):
                temp[a][b] = m[i-a][j-b]
    elif(times==3):
        for a in range(i+1):
            for b in range(j+1):
                temp[i-a][j-b] = m[j-b][a]
    return temp            

def update(m, i, j, new):
    m[int(i)][int(j)] = int(new)
    return m
def query(m, i, j):
    print(m[int(i)][int(j)])

n=int(input())
m=[]
initial=[]
rotation=0
for i in range(n):
    y = list(map(int, input().split()))
    m.append(y)
    initial.append(y)
initial_2=[]
for items in initial:
    temp1=[]
    for item in items:
        temp1.append(item)
    initial_2.append(temp1)
operation = [0]
while(operation[0] != "-1"):
    operation = input().split()
    if(operation[0]=='R'):
        rotation+=int(operation[1])
        m = rotate(m, operation[1])
    elif(operation[0]=='U'):
        m = update(initial, operation[1], operation[2], operation[3])
        m = rotate(m, rotation)
        initial=[]
        for items in initial_2:
            temp1=[]
            for item in items:
                temp1.append(item)
            initial.append(temp1)
    elif(operation[0]=='Q'):
        query(m, operation[1], operation[2])