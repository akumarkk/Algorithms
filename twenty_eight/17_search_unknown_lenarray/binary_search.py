# Given a sorted array of unknown length and a number to search for, return the index of the number in the array. 
# Accessing an element out of bounds throws exception. 
# If the number occurs multiple times, return the index of any occurrence. 
# If it isnt present, return -1.


def binary_search(array, key):

    # To check for first element
    index = -1
    while key >= array[int(2**index)]:
	
	try:
	    if key == array[int(2**index)]:
		return int(2**index)
	    else:
		index = index + 1

		# This is just to check for exception
		if array[2**index]:
		    pass
	except IndexError:
	    print("Exception for index = ", 2**index)
	    break

    # It is either exception or key < array[2**index]
    # high will remain same
    high = (2**index) - 1
    low = (2**(index-1)) + 1
    
    print("index = ", index, "low = ", low, " high = ", high)
    while low <= high:
	try:
	    mid = (low + high) / 2
	    print("mid = ", mid, "low = ", low, " high = ", high)
	    if(array[mid] == key):
		return mid
	    elif array[mid] > key:
		high = mid - 1
		print("now high = ", high)
	    else:
		low = mid + 1
		print("now low = ", low)
	except IndexError:
	    print("Mid index Error ", mid)
	    mid = mid - 1

    return -1

array = [1, 3, 45, 67, 78, 89, 90, 100]

print("***key = 10	    ret	= ", binary_search(array, 10));
print("***key = 89	    ret	= ", binary_search(array, 89));
print("***key = 1	    ret	= ", binary_search(array, 1));



