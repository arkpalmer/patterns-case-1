#pragma once

#include <iostream>
#include <vector>

#include "Utils.h"

template <typename T>
class List
{
public:
    List(long size = 10);
    virtual ~List();

    const T& get(long index) const;

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
long List<T>::count() const
{
    return data_.size();
}

template <typename T>
const T& List<T>::get(long index) const
{
    // TODO you could have some kind of try or other check
    return data_[index];
}