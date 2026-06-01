#ifndef GUARD_median_h
#define GUARD_median_h

#include <algorithm>
#include <stdexcept>
#include "Vec.h"

template<class T>
T median(Vec<T> vec)
{
	typedef typename Vec<T>::size_type vec_sz;
	vec_sz size = vec.size();
	if(size == 0)
		throw std::domain_error("median of an empty vector");
	std::sort(vec.begin(),vec.end());
	vec_sz mid = size/2;
	return size % 2 == 0 ? (vec[mid]+vec[mid-1])/2 : vec[mid];
}

template<class T>
T average(const Vec<T> &vec){
	typedef typename Vec<T>::size_type vec_sz;
	vec_sz size = vec.size();
	if(size == 0)
		 throw std::domain_error("average of an empty vector");
	double sum=0;
	for(int i=0;i<size;i++){
		sum+=vec[i];
	}
	return sum/size;
}

#endif
