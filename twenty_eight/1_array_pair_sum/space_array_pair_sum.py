# Time complexity   :	O(n)
# Space complexity  :	O(n)

def array_pair_sum(array, sum):
    if(len(array) < 2):
	return None

    seen = set()
    output = set()

    for num in array:
	num2 = sum - num
	if num2 in seen:
	    output.add((num,num2))
	else:
	    seen.add(num)
    
    print("\n".join(map(str, list(output))))
    return None

array = [32, 45, 12, 9, 12, 8, 11, 14, 6, 10, 15, 5, 16, 0, 4]
array_pair_sum(array, 20)

