#include <iostream>

int iterbinarySearch(const int *arr, int length, int elem)
{
	int min(0);
	int max(length-1);
	while (min<=max)
	{
		int pos = (max + min)/2;
		if (arr[pos] > elem)
			max = pos - 1;
		else if (arr[pos] < elem)
			min = pos + 1;
		else
			return pos;
	}
	return -1;
}

int recurbinarySearch(const int *arr, int min, int max, int elem)
{
	int pos = (min+max)/2;
	if ((min > max)) 
		return -1;
	if (arr[pos] == elem)
		return pos;
	else if (arr[pos] > elem)
		recurbinarySearch(arr,min,pos - 1,elem);
	else
		recurbinarySearch(arr,pos + 1,max,elem);
}

int main()
{
	int elem;
	std::cout << "Enter integer to search in array: ";
	std::cin >> elem;
	int sorted_array[] = {3,6,7,9,12,15,18,21,24};
	int found = iterbinarySearch(sorted_array, 9, elem);
	if (found == -1)
		std::cout << "Element not found in the array" << '\n';
	else
		std::cout << "Element found at " << found << '\n';
	int bin_found = recurbinarySearch(sorted_array,0,8,elem);
	if (found == -1)
		std::cout << "Recursive Binary search also does not lead any result" << '\n';
	else
		std::cout << "Result of recursive binart search: " << bin_found << '\n';
	return 0;
}
