// C++ Tutorial - Algorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

struct IntHolder
{
	IntHolder(int InValue) : Value(InValue)
	{

	}

	int Value;
};

int main()
{
	std::vector<IntHolder> intVector;
	intVector.push_back(IntHolder(2));
	intVector.push_back(IntHolder(4));
	intVector.push_back(IntHolder(6));
	intVector.push_back(IntHolder(0));
	intVector.push_back(IntHolder(1));

	{
		auto maxValueIt = std::max_element(intVector.begin(), intVector.end(), [](const IntHolder& lhs, const IntHolder& rhs) {
			return lhs.Value < rhs.Value;
			});

		if (maxValueIt != intVector.end())
			std::cout << "Maximum value is " << maxValueIt->Value << std::endl;
	}
	{
		auto minValueIt = std::min_element(intVector.begin(), intVector.end(), [](const IntHolder& lhs, const IntHolder& rhs) {
			return lhs.Value < rhs.Value;
			});

		if (minValueIt != intVector.end())
			std::cout << "Minimum value is " << minValueIt->Value << std::endl;
	}
	{
		auto foundValueIt = std::find_if(intVector.begin(), intVector.end(), [](const IntHolder& element) {
			return element.Value == 6;
			});

		if (foundValueIt != intVector.end())
			std::cout << "Found value at position " << std::distance(intVector.begin(), foundValueIt) << std::endl;
	}
	{
		auto count = std::count_if(intVector.begin(), intVector.end(), [](const IntHolder& element) {
			return element.Value % 2 == 0;
			});

		std::cout << "Num matching values is " << count << std::endl;
	}
	{
		bool ascending = false;

		std::sort(intVector.begin(), intVector.end(), [ascending](const IntHolder& lhs, const IntHolder& rhs) {
			return ascending ? (lhs.Value < rhs.Value) : (lhs.Value > rhs.Value);
			});

		std::cout << "Sorted data:" << std::endl;
		for (auto value : intVector)
			std::cout << value.Value << std::endl;
	}
	{
		std::replace_if(intVector.begin(), intVector.end(), [](const IntHolder& element) {
			return element.Value % 2 == 0;
			}, 42);

		std::cout << "Modified data:" << std::endl;
		for (auto value : intVector)
			std::cout << value.Value << std::endl;
	}
	{
		auto removePointIt = std::remove_if(intVector.begin(), intVector.end(), [](const IntHolder& element) {
			return element.Value == 42;
			});

		intVector.erase(removePointIt, intVector.end());

		std::cout << "Filtered data:" << std::endl;
		for (auto value : intVector)
			std::cout << value.Value << std::endl;
	}
}
