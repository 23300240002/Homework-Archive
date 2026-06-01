#ifndef __VEC_H
#define __VEC_H
#include <memory>
#include <cstddef>
//TODO

template <class T>
class Vec {
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef std::size_t size_type;
	typedef T value_type;
	typedef std::ptrdiff_t difference_type;
	typedef T& reference;
	typedef const T& const_reference;

	Vec() { create(); }
	explicit Vec(size_type n, const T& val = T()) { create(n, val); }
	Vec(const Vec& v) { create(v.begin(), v.end()); }
	~Vec() { uncreate(); }

	Vec& operator=(const Vec& rhs)
	{
		if (&rhs != this) {
			uncreate();
			create(rhs.begin(), rhs.end());
		}
		return *this;
	}

	size_type size() const { return static_cast<size_type>(avail - data); }

	reference operator[](size_type i) { return data[i]; }
	const_reference operator[](size_type i) const { return data[i]; }

	iterator begin() { return data; }
	const_iterator begin() const { return data; }
	iterator end() { return avail; }
	const_iterator end() const { return avail; }

	void push_back(const T& val)
	{
		if (avail == limit) {
			grow();
		}
		unchecked_append(val);
	}

	void clear()
	{
		uncreate();
		create();
	}

private:
	iterator data;
	iterator avail;
	iterator limit;
	std::allocator<T> alloc;

	void create()
	{
		data = avail = limit = 0;
	}

	void create(size_type n, const T& val)
	{
		data = alloc.allocate(n, 0);
		avail = limit = data + n;
		std::uninitialized_fill(data, limit, val);
	}

	void create(const_iterator i, const_iterator j)
	{
		data = alloc.allocate(j - i, 0);
		avail = limit = std::uninitialized_copy(i, j, data);
	}

	void uncreate()
	{
		if (data) {
			iterator it = avail;
			while (it != data) {
				alloc.destroy(--it);
			}
			alloc.deallocate(data, limit - data);
		}
		data = avail = limit = 0;
	}

	void grow()
	{
		size_type new_size = 1;
		if (data) {
			new_size = 2 * static_cast<size_type>(limit - data);
		}
		iterator new_data = alloc.allocate(new_size, 0);
		iterator new_avail = std::uninitialized_copy(data, avail, new_data);

		uncreate();
		data = new_data;
		avail = new_avail;
		limit = data + new_size;
	}

	void unchecked_append(const T& val)
	{
		alloc.construct(avail++, val);
	}
};


#endif
