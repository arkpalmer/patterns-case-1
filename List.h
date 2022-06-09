#pragma once

#include <iostream>
#include <vector>
#include <exception>

#include "Utils.h"
#include "Iterator.h"

template <typename T>
class Abstract_list
{
public:
    virtual Iterator<T>* create_iterator() = 0;

    virtual ~Abstract_list() { }

    virtual void push(const T& item) = 0;

    virtual const T& get(long index) const = 0;

    virtual const T& first() const = 0;
    virtual const T& last() const = 0;
    virtual long count() const = 0;
};

template <typename T>
class List : public Abstract_list<T>
{
public:
    // what is the purpose of starting with 10? how to add the first new item?? push_back would put
    // it at 11th entry - maybe List api in book has [] operator etc TODO
    //List(long size = 10); 
    List(long size = 0);
    virtual ~List();

    void push(const T& item) override;

    const T& get(long index) const override;

    const T& first() const override;
    const T& last() const override;
    long count() const override;

    Iterator<T>* create_iterator() override;

private:
    std::vector<T> data_;
};

template <typename T>
Iterator<T>* List<T>::create_iterator() 
{
    return new List_iterator<T>(this);
}

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