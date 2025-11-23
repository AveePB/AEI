#include "header.hpp"
#include <functional>

template <class T>
std::vector<T> CreateVector(const size_t size, std::function<T(const size_t)> f) {
	std::vector<T> result(size);
	for (size_t i = 0; i < size; i++) result[i] = f(i);
	return result;
}

int main() {
	char c;
	// Exercise 1
	int prev1 = 1;
	std::vector<int> v1 = CreateVector<int>(10, [&prev1](const size_t i) {
		if (i == 0) return 1;
		return prev1 *= 2;
	});

	std::cout << "Ex 1\nInitialized vector: ";
	for (auto el : v1) std::cout << el << ' ';
	std::cout << '\n';
	std::cin >> c;

	// Exercise 2
	int prev2_1 = 1;
	int prev2_2 = 1;
	std::vector<int> v2 = CreateVector<int>(10, [&prev2_1, &prev2_2](const size_t i) {
		if (i < 2) return 1;
		int help = prev2_1;
		prev2_1 = prev2_2;
		prev2_2 += help;
		return prev2_2;
	});

	std::cout << "Ex 2\nInitialized vector: ";
	for (auto el : v2) std::cout << el << ' ';
	std::cout << '\n';
	std::cin >> c;

	// Exercise 3 
	std::vector<int> v3 = { 1, 2, 3, 4, 5, 6, 7 };
	std::cout << "Ex 3\nInitialized vector: ";
	for (auto el : v3) std::cout << el << ' ';

	mz::removeMinMaxElements(v3);
	std::cout << "\nRemoved Min & Max: ";
	for (auto el : v3) std::cout << el << ' ';
	std::cout << '\n';
	std::cin >> c;

	// Exercise 4
	std::vector<int> v4 = { 1, 2, 1, 2, 1, 2, 1 };
	std::cout << "Ex 4\nInitialized vector: ";
	for (auto el : v4) std::cout << el << ' ';
	std::cout << "\nCounted " << mz::countEvenElements(v4) << " even elements\n";
	std::cin >> c;

	// Exercise 5
	std::vector<int> v5 = { 1, 2, 3, 4, 5, 1, 2, 3, 6};
	std::cout << "Ex 5\nInitialized vector: ";
	for (auto el : v5) std::cout << el << ' ';

	mz::uniqueElements(v5);
	std::cout << "\nUnique elements: ";
	for (auto el : v5) std::cout << el << ' ';
	std::cout << '\n';
	std::cin >> c;

	// Exercise 6
	std::vector<int> v6 = { 1, -2, -3, -4, -5, 1, -2, -3, 6 };
	std::cout << "Ex 6\nInitialized vector: ";
	for (auto el : v6) std::cout << el << ' ';

	mz::removeLessThenZero(v6);
	std::cout << "\nNon-negative elements: ";
	for (auto el : v6) std::cout << el << ' ';
	std::cout << '\n';
	std::cin >> c;

	// Exercise 7
	std::vector<int> v7 = { 1, 2, 3, 4, 5, 1, 2, 3, 6 };
	std::cout << "Ex 7\nInitialized vector: ";
	for (auto el : v7) std::cout << el << ' ';

	mz::removeEvenElements(v7);
	std::cout << "\nOdd elements: ";
	for (auto el : v7) std::cout << el << ' ';
	std::cout << '\n';
	std::cin >> c;

	// Exercise 8
	std::vector<int> v8 = { 1, 2, 3, 4, 5, 1, 2, 3, 6 };
	std::cout << "Ex 8\nInitialized vector: ";
	for (auto el : v8) std::cout << el << ' ';

	mz::clamp(v8, 3, 4);
	std::cout << "\nClamped values: ";
	for (auto el : v8) std::cout << el << ' ';
	std::cout << '\n';
	std::cin >> c;

	return 0;
}
