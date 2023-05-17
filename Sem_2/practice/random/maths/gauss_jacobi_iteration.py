from numpy import matmul, diag
print("Using Jacobi Iteration method")
mat=[]
h=[]
for i in range(3):
    x=list(map(float, input().split()))
    x=x[:4]
    h.append(x[:3])
    mat.append(x)
d=list(diag(mat))

put=list(map(float, input("Enter x0: ").split()))
it=input("Enter number of iterations to perform: ")
for i in range(3):
    for j in range(3):
        if(i==j):
            h[i][j]=0
        else:
            h[i][j]/=d[i]*-1
c=[mat[i][3] for i in range(3)]
for i in range(3):
    c[i]/=d[i]

print("\nh: ", h,"\nc: ", c,"\n")
#calculating
it=int(it)
print("\n")
while(it>0):
    put=matmul(h, put)+c
    print(put)
    it-=1
