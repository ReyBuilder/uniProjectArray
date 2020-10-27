#include "Array.h"

int* Array::search(const int num)
{
	for (size_t i = 0; i < dataAmount_; i++)
	{
		if (array_[i] == num) {
			return &array_[i];
		}
	}

	return nullptr;
}

void Array::memoryIncrease()
{
	memory_ *= 2;
	int* oldArr = array_;
	array_ = new int[memory_];
	for (size_t i = 0; i < dataAmount_; i++)
	{
		array_[i] = oldArr[i];
	}
	delete[] oldArr;
}

void Array::shift(const size_t shiftSize, const size_t shiftStart, Direction direction)
{
	if (shiftStart < 0 || shiftStart + shiftSize > dataAmount_ || shiftSize < 1) {
		throw std::out_of_range("shift out of range");
	}

	if (direction == Direction::LEFT) {
		int temp;
		
		if (shiftStart != 0)
		{
			temp = array_[shiftStart - 1];
			array_[shiftStart - 1] = array_[shiftStart];
		}
		else
		{
			temp = 0;
		}

		for (size_t i = 1; i < shiftSize; i++)
		{
			array_[shiftStart + i - 1] = array_[shiftStart + i];
		}

		array_[shiftStart + shiftSize - 1] = temp;
	} 
	else
	{
		int temp;

		if (shiftStart + shiftSize != dataAmount_) {
			temp = array_[shiftStart + shiftSize];
			array_[shiftStart + shiftSize] = array_[shiftStart + shiftSize - 1];
		}
		else
		{
			temp = 0;
		}

		for (size_t i = shiftSize; i > 0; i--)
		{
			array_[shiftStart + i - 1] = array_[shiftStart + i - 2];
		}

		array_[shiftStart] = temp;
	}
}

Array::Array()
{
	srand(time(NULL));

	dataAmount_ = rand() % 10;
	memory_ = dataAmount_;

	array_ = new int[dataAmount_];
	for (size_t i = 0; i < dataAmount_; i++)
	{
		array_[i] = rand() % 100;
	}
}

Array::Array(const size_t memory, const size_t dataAmount) {
	if (memory < dataAmount || dataAmount < 0) {
		throw std::bad_array_new_length();
	}
	memory_ = memory;
	dataAmount_ = dataAmount;
	array_ = new int[memory_];
	for (size_t i = 0; i < dataAmount_; i++)
	{
		array_[i] = 0;
	}
}

Array::Array(const int* arr, const size_t dataAmount) {
	if (dataAmount < 0) {
		throw std::bad_array_new_length();
	}
	dataAmount_ = dataAmount;
	memory_ = dataAmount;
	array_ = new int[memory_];
	for (size_t i = 0; i < dataAmount; i++)
	{
		array_[i] = arr[i];
	}
}

Array::Array(const Array& a) {
	dataAmount_ = a.dataAmount_;
	memory_ = a.memory_;
	array_ = new int[memory_];
	for (size_t i = 0; i < memory_; i++)
	{
		array_[i] = a.array_[i];
	}
}

Array::~Array() {
	delete[] array_;
}

int& Array::operator[] (const size_t index) {
	return array_[index];
}

void Array::sort() {
	HeapSort::sort(array_, dataAmount_);
}

std::ostream& operator<<(std::ostream& out, const Array a)
{
	for (size_t i = 0; i < a.dataAmount_ - 1; i++)
	{
		out << a.array_[i] << ' ';
	}
	out << a.array_[a.dataAmount_ - 1];

	return out;
}
