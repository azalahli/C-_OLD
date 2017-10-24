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


#endif
			


#include <iostream>
#include "bagdyntemplate.h"
using namespace std;
using namespace daves_bag;

int main()
{
    bag<int> b(3);
    bag<int>::size_type count;
    
    b.insert(4);
    b.insert(8);
    b.insert(8);
    b.insert(6);
    cout << "number of items: " << b.size() << endl;
    cout << "number of 4s: " << b.count(4) << endl;
    cout << "number of 8s: " << b.count(8) << endl;
    b.reserve(2);
    cout << "number of items: " << b.size() << endl;
    b.erase_one(8);
    cout << "number of 8s: " << b.count(8) << endl;
    b.insert(8);
    b.erase(8, count);
    cout << count << " 8s were erased" << endl;
    b.insert(8);
    b.insert(8);
    
    bag<int> b2;
    b2.reserve(4);
    b2.insert(1);
    b2 += b;
    
    cout << "number of items: " << b2.size() << endl;
    cout << "number of 1s: " << b2.count(1) << endl;
    cout << "number of 8s: " << b2.count(8) << endl;
    
    b2 = b2 + b2;
    cout << "number of items: " << b2.size() << endl;
    cout << "number of 1s: " << b2.count(1) << endl;
    cout << "number of 8s: " << b2.count(8) << endl;
  
    //doesn't work if += is void, but works if += returns by value
    cout << "number of items: " << (b2 += b).size() << endl;
    
    //doesn't work if += is void or returns by value, but works if += returns by ref
    (b2 += b) += b;
    cout << "number of items: " << b2.size() << endl;
  
}
    