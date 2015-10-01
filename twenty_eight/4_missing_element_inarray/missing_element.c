/* There is an array of non-negative integers. A second array is formed by shuffling the elements of the first array and deleting a random element. Given these two arrays, find which element is missing in the second array. - See more at: http://www.ardendertat.com/2011/09/27/programming-interview-questions-4-find-missing-element/#sthash.4iXf2OWx.dpuf
 */

/* Solutions :
 * 1. Naive solution : Take each element in the first array compare with every other element in second array
 *		       Time complexity = O(n^2)
 * 2. Sorting O(n logn) : Sort both the arrays. compare each of the elements using pointers
 * 3. Summation method O(n) : Take sum of all the numbers in 1st array and 2nd array. Take the difference
 *	Problem	:   Arithmatic overflow if the numbers are really big
 * 4. XOR : XOR all the elements of 1st and 2nd array to get the missing element
 */

#include <stdio.h>

int
get_missing_element(int *array1, int n1, int *array2, int n2)
{
    int	i, j;
    int element = 0;

    for(i=0, j=0; i<n1 && j<n2; i++, j++)
    {
	element = element  ^ array1[i] ^ array2[j];
    }

    if(n1 > n2)
	element = element ^ array1[n1-1];
    else
	element = element ^ array2[n2 - 1];

    return element;
}

int
main()
{
    int array1[] = {4, 1, 0, 2, 9, 6, 8, -10, 7, 5, 3};
    int array2[] = {6, 4, 7, 2, 1, 0, 8, 3, 9, 5};

    int missing = get_missing_element(array1, sizeof(array1)/sizeof(int), array2, sizeof(array2)/sizeof(int));

    printf("Missing element = %d\n", missing);
    return 0;
}
	    
