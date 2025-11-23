#ifndef HEADER_H
#define HEADER_H

// Libraries
#include <concepts>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <set>

namespace mz {
	
	// 3 
	template <class T>
	void removeMinMaxElements(std::vector<T> &vec) {
		// Remove min element
		int idx = 0;
		for (int i = 0; i < vec.size(); i++) 
			if (vec[idx] > vec[i]) idx = i;
		vec.erase(vec.begin() + idx);

		// Remove max element
		idx = 0;
		for (int i = 0; i < vec.size(); i++)
			if (vec[idx] < vec[i]) idx = i;
		vec.erase(vec.begin() + idx);
	}

	// 4
	template <class T>
	int countEvenElements(std::vector<T> &vec) {
		// Check if is integral
		static_assert(
			std::is_same<T, int>::value ||
			std::is_same<T, short>::value ||
			std::is_same<T, long>::value,
			"Dozwolone tylko typy: int, short, long!"
		);

		// Count even elements
		int counter = 0;
		for (auto el : vec)
			if (el % 2 == 0) counter++;

		return counter;
	}

	// 5
	template <class T>
	void uniqueElements(std::vector<T>& vec) {
		std::set<T> s;
		for (auto el : vec) s.insert(el);
		vec.clear();
		for (auto el : s) vec.push_back(el);
	}

	// 6
	template <class T>
	void removeLessThenZero(std::vector<T>& vec) {
		std::vector<T> vec_2;
		for (int i = 0; i < vec.size(); i++)
			if (vec[i] >= 0)
				vec_2.push_back(vec[i]);
		vec.clear();

		for (auto el : vec_2) vec.push_back(el);
	}

	// 7
	template <class T>
	void removeEvenElements(std::vector<T>& vec) {
		std::vector<T> vec_2;
		for (int i = 0; i < vec.size(); i++)
			if (vec[i] % 2)
				vec_2.push_back(vec[i]);
		vec.clear();

		for (auto el : vec_2) vec.push_back(el);
	}

	// 8
	template <class T>
	void clamp(std::vector<T> &vec, T minVal, T maxVal) {
		std::for_each(vec.begin(), vec.end(), [minVal, maxVal](T& x) {
			x = std::min(maxVal, std::max(x, minVal));
		});
	}
}
#endif 
