def det(m):
    if(len(m)==1):
        return m[0][0]
    
    print(m)
    out=0
    for i in range(len(m)):
        out += (1 if i%2==0 else -1)*m[0][i]*det([o[:i]+o[i+1:] for o in m[1:]])
    # print(out)
    return out


print(det([[1,2,3],[4,1,6],[7,8,9]]))