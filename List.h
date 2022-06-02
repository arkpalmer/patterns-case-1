#pragma once

#include <iostream>
#include <vector>
#include <exception>

#include "Utils.h"
#include "Iterator.h"

template <typename T>
class List
{
public:
    List(long size = 10);
    virtual ~List();

    void push(const T& item);

    const T& get(long index) const;

    const T& first() const;
    const T& last() const;
    long count() const;

private:
    std::vector<T> data_;
};

template <typename T>
List<T>::List(long size) :
    data_(size)
{
}

template <typename T>
List<T>::~List()
{
    PFL
}

template <typename T>
void List<T>::push(const T& item)
{
    data_.push_back(item);
}

template <typename T>
const T& List<T>::first() const
{
    PFL
    
    if (count() == 0)
    {        
        throw std::out_of_range("List<T>::first() exception : list is empty");
    }
    
    std::cout << *(data_.begin()) << std::endl;

    return *(data_.begin());
}

template <typename T>
const T& List<T>::last() const
{
    FL

    if (count() == 0)
    {        
        throw std::out_of_range("List<T>::last() exception : list is empty");
    }

    return *(std::prev(data_.end()));
}

template <typename T>
long List<T>::count() const
{
    return data_.size();
}

template <typename T>
const T& List<T>::get(long index) const
{
    if (count() == 0 || index >= count())
    {        
        throw std::out_of_range("List<T>::last() exception : list is empty");
    }

    return data_[index];
}