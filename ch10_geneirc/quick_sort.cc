#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>

namespace myscope {

template <class ForwardIt, class UPredict>
ForwardIt partition(ForwardIt first, ForwardIt last, UPredict p) {
	first = std::find_if_not(first, last, p);
	if (first == last) return first;
	for (ForwardIt i = std::next(first); i != last; ++i) {
		if (p(*i)) {
			std::iter_swap(i, first);
			++first;
		}
	}
	return first;
}
};


template <class ForwardIt>
void quick_sort(ForwardIt first, ForwardIt last) {
	if (first == last) return;

	auto pivot = *std::next(first, std::distance(first, last) / 2);

	using pi = decltype(pivot);
	ForwardIt mid1 = myscope::partition(first, last,
		[pivot](const pi& em) { return em < pivot;});
	// ForwardIt mid2 = myscope::partition(mid1, last,
	// 	[pivot](const pi &em) { return !(pivot < em); });

	quick_sort(first, mid1);
	// quick_sort(mid2, last);
	// quick_sort(mid1+1, last);
	quick_sort(++first, last);
}

template <class Iter>
void print(Iter& v) {
	for (auto vi: v)
		std::cout << vi << ", ";
	std::cout << std::endl;
}

int main() {
	// std::vector<int> v = {5, 3, 2, 5, 6, 99, -2};
	std::vector<int> v = {10, 5, 1, 1, 5};
	print(v);
	quick_sort(v.begin(), v.end());
	print(v);

}
