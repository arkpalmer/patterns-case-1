#pragma once

#include "Utils.h"

template <typename T>
class Iterator
{
public:
    // position the iterator to the first element
    virtual void first() = 0;

    // advance the iterator
    virtual void next() = 0;

    // true if iterator does not refer to an element
    virtual bool is_done() const = 0;

    virtual T current_item() const = 0;

    // need this for interface/abstract class or deletion of derived is undefined
    virtual ~Iterator() { PFL }

protected:
    // needed? class is Abstract so can't instantiate? TBD
    Iterator();
};

template <typename T>
Iterator<T>::Iterator() { }

template <typename T>
class List;

template <typename T>
class List_iterator : public Iterator<T>
{
public:
    List_iterator(const List<T>* list); // explicit?

    ~List_iterator() { PFL }

    void first() override;
    void next() override;
    bool is_done() const override;
    T current_item() const override;

private:
    const List<T>* list_;
    long           current_;
};

template <typename T>
List_iterator<T>::List_iterator(const List<T>* list) :
    list_(list), current_(0)
{
    PFL
}

template <typename T>
void List_iterator<T>::first()
{
    current_ = 0;
}

template <typename T>
void List_iterator<T>::next()
{
    current_++;
}

template <typename T>
bool List_iterator<T>::is_done() const 
{
    return current_ >= list_->count();
}

template <typename T>
T List_iterator<T>::current_item() const
{

    return list_->get(current_);
}