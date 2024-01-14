try:
    from sympy import *
except:
    print('\nsympy module not found. Installing it now.\n')
    import os
    os.system('python -m pip install sympy')
    from sympy import *


print('''
----------------------------------
Convert matrix to its RRE form.

1. Enter number of equations [SPACE] number of coefficients.
2. Type the augmented matrix.
3. Get its RRE form lightning fast. ⚡⚡⚡
----------------------------------
''')

eqns, coeff = map(int, input('Enter no. of step 1: ').split())
mat = []
print('Enter matrix')
for i in range(eqns):
    temp = list(map(int, input().split()))
    while (len(temp) != coeff + 1):
        print('Incorrect number of coefficients. Try again!')
        temp = list(map(int, input().split()))
    mat.append(temp)

m = Matrix(mat)
m_rref = m.rref()

print("The Row echelon form of matrix M and the pivot columns : {}".format(m_rref))   