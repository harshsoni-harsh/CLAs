test_cases = int(input('Enter number of matrices'))
for _ in range(test_cases):
    eqns, coeff = map(int, input('Enter no of columns and rows in [A:b] : ').split())
    mat = []
    print('Enter matrix:')
    for i in range(eqns):
        temp = list(map(float, input().split()))
        while (len(temp) != coeff + 1):
            print('Incorrect number of coefficients. Try again!')
            temp = list(map(float, input().split()))
        mat.append(temp)

    cursor_v, cursor_h = 0, 0

    def step1(v,h):
        if (h == coeff+1):
            return 0
        found = 0
        i,j = 0,0
        for j in range(h,coeff+1):
            for i in range(v, eqns):
                if (mat[i][j] != 0):
                    found = 1
                    break 
            if (found):
                break
        mat[i],mat[v] = mat[v],mat[i]
        global cursor_v, cursor_h
        cursor_v, cursor_h = i, j
        if (found == 0):
            found = step1(v,h+1)
        return found

    def step2(v,h):
        num = mat[v][h]
        if (num != 0):
            for j in range(coeff+1):
                mat[v][j] /= num

    def step3(v,h):
        for i in range(eqns):
            num = mat[v]
            times = mat[i][h]
            if (i != v and times != 0):
                for j in range(coeff+1):
                    mat[i][j] -= num[j] * times

    def step4():
        global cursor_v, cursor_h
        cursor_v += 1
        cursor_h += 1

    def run():
        while (cursor_v < eqns and cursor_h < coeff + 1):
            step1(cursor_v, cursor_h)
            step2(cursor_v, cursor_h)
            step3(cursor_v, cursor_h)
            step4()
        print('printing for mat {}'.format(_))
        for i in mat:
            st = ''
            for j in i:
                if (j == 0):
                    st += '0\t'
                elif (j == int(j)):
                    st += str(int(j)) + '\t'
                else:
                    st += str(j) + '\t'
            print(st)
        print()
    run()