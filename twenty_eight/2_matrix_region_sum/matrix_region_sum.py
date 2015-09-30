# Time complexity   :	O(m * n)
# Space complexity  :	O(m * n)

def print_matrix(matrix):
    for row in matrix:
	print(row)

def matrix_sum(matrix):
    #x = 0, y=0
    n_rows = len(matrix)
    n_cols = len(matrix[0])
    print("Rows = ", n_rows, "	Columns = ", n_cols)

    # Create sum_matrix with all 0's
    sum_matrix = [[0]*n_cols for rows in range(n_rows)]

    # Initialize first row to row sum
    sum_matrix[0][0] = matrix[0][0]
    for row in range(1, len(matrix)):
	sum_matrix[row][0] = matrix[row][0] + sum_matrix[row-1][0]

    print("Initialized rows...")
    print_matrix(sum_matrix)

    for col in range(1, n_cols):
	sum_matrix[0][col] = sum_matrix[0][col-1] + matrix[0][col]

    print("Initialized rows...")
    print_matrix(sum_matrix)
    
    for row in range(1, len(matrix)):
	for col in range(1, n_cols):
	    sum_matrix[row][col] = matrix[row][col] + sum_matrix[row-1][col] + sum_matrix[row][col-1] - sum_matrix[row-1][col-1]

    print("Sum Matrix	:   ")
    print_matrix(sum_matrix)

    return sum_matrix

def matrix_region_sum(matrix, A, D):
    sum_matrix = matrix_sum(matrix)

    row1, col1 = A
    row2, col2 = D
    
    if row1 == row2 and col1 == col2:
	return matrix[row1][col1]

    if row1 == 0 or col1 == 0:
	OA = 0
    else:
	OA = sum_matrix[row1-1][col1-1]

    if row1 == 0:
	OB = 0
    else:
	OB = sum_matrix[row1-1][col2]

    if col1 == 0:
	OC = 0
    else:
	OC = sum_matrix[row2][col1-1]

    OD = sum_matrix[row2][col2]

    return (OD - OB - OC + OA)


matrix = [[1, 2, 3], [4, 5, 6]]
for row in matrix:
    print(row)

matrix_sum(matrix)

region_sum =  matrix_region_sum(matrix, [0, 1], [1, 2])
print("Region sum (0, 1) to (2, 2)  :	", region_sum)  
