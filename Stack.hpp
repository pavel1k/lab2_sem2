#ifndef STACK_HPP
#define STACK_HPP


#include "ListSequence.hpp"

template <typename T>
class Stack {
public:
    Stack() : _list(new ListSequence<T>){}

    template <typename ...Args>
    Stack(Args&&... args) : _list(new ListSequence<T>(std::forward<Args>(args)...)) {}

    void push(const T &val) {_list->prepend(val);}

    T& back() {return _list->getLast();};
    const T& back() const {return _list->getLast();}

    T& front() {return _list->getFirst();};
    const T& front() const {return _list->getFirst();}

    void erase(size_t i) {_list->erase(i);}
    void erase(size_t from, size_t to) {_list->erase(from, to);}
    T pop();


    bool empty() {return _list->size() == 0;}
    size_t size() {return _list->size();}

private:
    ListSequence<T> *_list;
};



template<typename T>
T Stack<T>::pop()
{
    T ret = front();
    erase(0);
    return ret;
}

















#endif // STACK_HPP