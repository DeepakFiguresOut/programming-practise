# create a function to add and multiply a matrix of nxn order
# work in progress
m,n=3,3
def row(m,index):
    return m[index]

def column(m,index):
    col=[]
    for i in range (3):
        col.append(m[i][index])


mat1= [
    [1,2,3],
    [4,5,6],
    [7,8,9]
]
mat2=[
    [2,4,5],
    [32,45,5],
    [43,5,3]
]
def add_matrix(mat1,mat2):
    sum=init_matrix(m,n)
    for i in range(m):
        for j in range(n):
            sum[i][j]=(mat1[i][j]+mat2[i][j])
    return sum
    
# def mul_matrix(mat1,mat2):
#     product=init_matrix(m,n)
#     for i in range(3):
#         for j in range(3):
#             for k in range(3)
#                 product= row(mat1,k)*column(mat2,k)
#             product[i][j]=row(mat1,i)*column(mat2,j)
#     return product ###############
    


def init_matrix(m,n):
    nullmatrix=[]
    for i in range(m):
        nullmatrix.append([])
        for j in range(m):
            nullmatrix[i].append(0)
    return nullmatrix

print(mul_matrix(mat1,mat2))