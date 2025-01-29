//
//  ArrayBag.hpp
//  bagWithDynamicArray
//
//  Created by Usaid Ali Syed on 2025-01-28.
//

#ifndef ARRAY_BAG_
#define ARRAY_BAG_

#include "BagInterface.hpp"

template<class ItemType>
class ArrayBag: public BagInterface<ItemType> {
private:
    static const int DEFAULT_CAPACITY = 5; //The size of the default bag
    ItemType *items; //Pointer for dynamic array container for the bag object
    int itemCount; //The actual number of items in the bag
    int capacity; //The capacity of a bag object
    
public:
    ArrayBag();//Default constructor
    ArrayBag(const ArrayBag<ItemType> &sourceBag); //Copy Constructor
    ~ArrayBag(); //Destructor
    ArrayBag<ItemType>& operator = (const ArrayBag<ItemType> &sourceBag); //Assignment Operator
    
    int getCurrentSize() const;
    bool isEmpty() const;
    bool isFull() const;
    bool add(const ItemType& newEntry);
    bool remove(const ItemType& anEntry);
    void clear();
    int getFrequencyOf(const ItemType& anEntry) const;
    bool contains(const ItemType& anEntry) const;
    vector<ItemType> toVector() const;

private: //Some Utility methods
    int getIndexOf(const ItemType& target) const;
    int getFrequenceOfRecursive(ItemType* arr, int startIndex, int lastIndex, const ItemType& anEntry) const;
};

#endif /* ArrayBag_hpp */
