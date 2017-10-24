#include <algorithm>
namespace daves_bag {
    //template <class Item>
	//const typename bag<Item>::size_type bag<Item>::DEFAULT_CAPACITY;

	template <class Item>
	bag<Item>::bag(size_type initialCapacity)
	{
		capacity = initialCapacity;
		used = 0;
		data = new Item[capacity];
	}
	
	
	template <class Item>
	bag<Item>::bag(const bag<Item>& source)
	{
		capacity = source.capacity;
		used = source.used;
		data = new Item[capacity];
		std::copy(source.data, source.data + used, data);
	}
	
	
	template <class Item>
	bag<Item>::~bag()
	{
		delete [] data;
	}
	
	
	template <class Item>
	void bag<Item>::reserve(size_type new_capacity)
	{
		if (new_capacity < used){
			new_capacity = used;
		}
		
		if (new_capacity != capacity){
			Item* newbag = new Item[new_capacity];
			std::copy(data, data + used, newbag);
			delete [] data;
			data = newbag;
			capacity = new_capacity;
		}
	}
	
	
	template <class Item>
	void bag<Item>::insert(const Item& entry)
	{
		if (used == capacity){
			reserve(used + 1);
		}
		
		data[used] = entry;
		used++;
	}
	
	
	template <class Item>
	typename bag<Item>::size_type bag<Item>::size()const
	{
		return used;
	}
	
	template <class Item>
	typename bag<Item>::size_type bag<Item>::count(const Item& target) const
	{
		size_type count = 0;
		
		for (size_type i = 0; i < used; i++){
			if (data[i] == target){
				count++;
			}
		}
		
		return count;
	}
	
	template <class Item>
	void bag<Item>::erase_one(const Item& target)
	{
		size_type i = 0;
		
		while (i < used && data[i] != target){
			i++;
		}
		
		if (i != used){
			data[i] = data[used - 1];
			used--;
		}
	}
	
	
	template <class Item>
	void bag<Item>::erase(const Item& target, size_type& num)
	{
		num = 0;
		size_type i = 0;
		
		while (i < used){
			if (data[i] == target){
				data[i] = data[used - 1];
				used--;
				num++;
			} else {
				i++;
			}
		}
	}
				
	template <class Item>
	bag<Item> bag<Item>::operator+=(const bag<Item>& right)
	{
		if (used + right.used > capacity){
			reserve(used + right.used);
		}
		
		std::copy(right.data, right.data + right.used, data + used);
		used += right.used;
		
		return *this;
	}
	
	template <class Item>
	bag<Item> operator+(const bag<Item>& left, const bag<Item>& right)
	{
		bag<Item> answer(left.size() + right.size());
		
		answer += left;
		answer += right;
		return answer;
	}
	
	
	template <class Item>
	bag<Item> bag<Item>::operator=(const bag<Item>& right)
	{
		Item* newArray;
		if (this != &right){
			if (capacity != right.capacity){
				newArray = new Item[right.capacity];
				delete [] data;
				data = newArray;
				capacity = right.capacity;
			}
				
			used = right.used;
			std::copy(right.data, right.data + used, data);
		}
		
		return *this;
	}
		
}
		
		
		
		
		
		
		
		
		
		
		