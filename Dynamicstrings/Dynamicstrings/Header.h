#ifndef BAG_H
#define BAG_H

namespace daves_bag {

template <class Item>
	class bag
	{
		public:
			typedef Item value_type;
			typedef std::size_t size_type;
			static const size_type DEFAULT_CAPACITY = 30;
			
			
			
			bag(size_type initialCapacity = DEFAULT_CAPACITY);
			bag(const bag& source);
			~bag();
			
			
			
			void reserve(size_type newCapacity);
			void erase_one(const Item& target);
			void erase(const Item& target,
						size_type &num);
			void insert(const Item& entry);
			bag operator+=(const bag& right);
			bag operator=(const bag& right);
			
			size_type size() const;
			size_type count(const Item& target) const;
		private:
			value_type *data;
			size_type used;
			size_type capacity;
	};
	
	template <class Item>
	bag<Item> operator+(const bag<Item>& b1, const bag<Item>& b2);
	
}

#include "source.cpp"

#endif
			
			