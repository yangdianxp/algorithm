#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__

#include <functional>
#include <algorithm>

template <class ForwardIt>
void quicksort(ForwardIt first, ForwardIt last)
{
	if (first == last) return;
	auto pivot = *std::next(first, std::distance(first, last) / 2);
	ForwardIt middle1 = std::partition(first, last,
		[pivot](const auto& em) { return em < pivot; });
	ForwardIt middle2 = std::partition(middle1, last,
		[pivot](const auto& em) { return !(pivot < em); });
	quicksort(first, middle1);
	quicksort(middle2, last);
}

#endif