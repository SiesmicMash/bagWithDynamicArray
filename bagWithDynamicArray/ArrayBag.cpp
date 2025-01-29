//
//  ArrayBag.cpp
//  bagWithDynamicArray
//
//  Created by Usaid Ali Syed on 2025-01-28.
//

#include "ArrayBag.hpp"

template <class ItemType>
ArrayBag<ItemType> :: ArrayBag() : capacity(DEFAULT_CAPACITY), itemCount(0) {
    
    items = new ItemType[capacity];
    
};

template <class ItemType>
ArrayBag<ItemType>:: ArrayBag(const ArrayBag<ItemType> &sourceBag) : capacity(sourceBag.capacity), itemCount(sourceBag.itemCount){
    
    if (capacity > 0) {
        
        items = new ItemType[capacity];
        for (int i = 0; i < itemCount; i++) {
            items[i] = sourceBag.items[i];
        }
    }
}


template <class ItemType>
ArrayBag<ItemType>:: ~ArrayBag() {
    
    if(capacity > 0) {
        delete [] items;
        capacity = 0;
        itemCount = 0;
        items = nullptr;
    }
    
}

template <class ItemType>
ArrayBag<ItemType>& ArrayBag<ItemType>::operator = (const ArrayBag<ItemType> &sourceBag) {
    
    if (this != &sourceBag) {
        this ->~ArrayBag();
        capacity = sourceBag.capacity;
        itemCount = sourceBag.itemCount;
        
        if (capacity > 0) {
            items = new ItemType[capacity];
            
            for (int i=0; i < itemCount; i++) {
                items[i] = sourceBag.items[i];
            }
            
        }
    }
    
    return *this;
}

template <class ItemType>
int ArrayBag<ItemType> :: getCurrentSize() const {
    
    return itemCount;
    
}

template <class ItemType>
bool ArrayBag<ItemType>:: isEmpty() const{
    
    return itemCount == 0;
    
}

template <class ItemType>
bool ArrayBag<ItemType>:: isFull() const{
    
    return itemCount == capacity;
    
}

template <class ItemType>
bool ArrayBag<ItemType>:: add(const ItemType &newEntry) {
    
    if (this -> isFull()) {
        //Re-size the array
        ItemType *oldArray = items; //Old array is the original dynamic array
        capacity *= 2;
        items = new ItemType[capacity]; // items are in the new dynamic array
        
        for (int i = 0; i< itemCount; i++) {
            items[i] = oldArray[i];
        }
        
        if (oldArray != nullptr) {
            delete [] oldArray;
        }
        
    }
    
    items[itemCount++] = newEntry;
    return true;
}

template <class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType &anEntry) {
    
    int index = getIndexOf(anEntry);
    
    if (index == -1) {
        return false;
    } else {
        //copy the last item of the array to the index of the item to be removed
        items[index] = items[itemCount - 1];
        //Decrement the number of items in the array (port-decrement)
        itemCount --;
        return true;
    }
}

template <class ItemType>
void ArrayBag<ItemType>::clear() {
    
    itemCount = 0;
}

template <class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType &anEntry) const{

    int count = 0;
    for (int i=0; i < itemCount; i++) {
        
        if (items[i] == anEntry) {
            count++;
        }
    }
    return count;
}

template <class ItemType>
bool ArrayBag<ItemType>:: contains(const ItemType &anEntry) const{
    
    return getFrequencyOf(anEntry) > 0;
    
}

template <class ItemType>
vector<ItemType> ArrayBag<ItemType>::toVector() const{
    
    vector<ItemType> v;
    
    for (int i = 0; i < itemCount; i++) {
        v.push_back(items[i]);
    }
    
    return v;
}


template <class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType &target) const{
    
    for (int itemIndex = 0; itemIndex < itemCount; itemIndex++) {
        
        if (items[itemIndex] == target) {
            return itemIndex;
        }
        
    }
    return -1;
}



