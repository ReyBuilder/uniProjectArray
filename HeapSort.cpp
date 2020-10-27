#include "HeapSort.h"
#include <algorithm>

/// <summary>
/// Creates the small heap like this
/// 
///		      root[1]
///			  /     \
///		left[3]     right[4]
/// 
/// based on elements of given array, where the nums in brackets are array
/// indexes.
/// 
/// Left elem = rootIndex * 2 + 1
/// Right elem = rootIndex * 2 + 2
/// 
/// </summary>
/// <param name="arr">Array</param>
/// <param name="size">Size of array</param>
/// <param name="rootIndex">Index of root</param>
void HeapSort::createHeap(int* arr, int size, int rootIndex) {
	int largestNumIndex = rootIndex;
	// contains left and right root children indexes
	int childrenIndexes[] = { rootIndex * 2 + 1, rootIndex * 2 + 2 };

	for (size_t i = 0; i < 2; i++)
	{
		if (childrenIndexes[i] < size && arr[childrenIndexes[i]] < arr[largestNumIndex])
		{
			largestNumIndex = childrenIndexes[i];
		}
	}

	if (rootIndex != largestNumIndex) {
		std::swap(arr[largestNumIndex], arr[rootIndex]);
		createHeap(arr, size, largestNumIndex);
	}
}

/// <summary>
/// Sorts array using HeapSort algo
/// Min-heap is based on array, that appears like this
///
///		   5[0]
///			/ \
///		4[1]   2[2]
///     / \
///	0[3]   2[4]
/// 
/// where the nums in brackets are array indexes.
/// </summary>
/// <param name="arr">Array which will be sorted</param>
/// <param name="size">Size of array</param>
void HeapSort::sort(int* arr, int size) {

	// heap creation (it creates from small heaps from the bottom to the top)
	for (size_t i = size / 2; i > 0; i--)
	{
		createHeap(arr, size, i - 1);
	}

	for (size_t i = size; i > 0; i--)
	{
		std::swap(arr[0], arr[i - 1]);
		createHeap(arr, size, 0);
	}

		
}