#ifndef ARRAY_H
#define ARRAY_H

#include <exception>
#include <iostream>
#include <ctime>
#include "HeapSort.h"

constexpr auto START_MEMORY = 4;

class Array
{
private:
	int* array_;
	size_t memory_;
	size_t dataAmount_;
	
	/// <summary>
	/// Finds the num in array
	/// </summary>
	/// <param name="num">The num that needs to find</param>
	/// <returns>Pointer to the num if it's exists in array and nullptr if doesnt</returns>
	int* search(const int);

	/// <summary>
	/// Doubles memory used by array
	/// </summary>
	void memoryIncrease();
	
public:
	enum Direction {
		LEFT,
		RIGHT
	};

	Array();

	/// <summary>
	/// Creates array object using preset memory and data amount
	/// 
	/// Can throw std::bad_array_new_length if the real memory is less than the data amount
	/// </summary>
	/// <param name="memory">Real size of array</param>
	/// <param name="dataAmount">Amout of array elements</param>
	Array(const size_t memory = START_MEMORY, const size_t dataAmount = 0);

	/// <summary>
	/// Creates array object by copying given array
	/// 
	/// Can throw std::bad_array_new_length if the data amount is less than zero
	/// </summary>
	/// <param name="arr">Array to copy</param>
	/// <param name="dataAmount">Amout of array elements</param>
	Array(const int* arr, const size_t dataAmount);

	Array(const Array& a);

	~Array();
	friend std::ostream& operator<< (std::ostream& out, const Array a);

	int& operator[] (const size_t index);
	/// <summary>
	/// Sorts the array using HeapSort algo
	/// </summary>
	void sort();

	/// <summary>
	/// Shifts the array to the shiftDirection at 1 position from the shiftStart
	/// to the shiftSize
	/// </summary>
	/// <param name="shiftSize">Amount of nums that need to be shifted</param>
	/// <param name="shiftStart">Index of starting num</param>
	/// <param name="shiftDirection">Direction that declared in enum Direction</param>
	void shift(const size_t shiftSize, const size_t shiftStart, Direction shiftDirection);
};


#endif // !ARRAY_H