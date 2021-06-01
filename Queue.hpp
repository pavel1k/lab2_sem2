#ifndef QUEUE_HPP
#define QUEUE_HPP


#include "Deque.hpp"

template <typename T>
class Queue {
public:
    Queue() : _list(new Deque<T>){}

    template <typename ...Args>
    Queue(Args&&... args) : _list(new Deque<T>(std::forward<Args>(args)...)) {}

    void push(const T &val) {_list->pushRight(val);}
    T pop() {_list->popLeft();}
   /* T& back() {return _list->getLast();};
    const T& back() const {return _list->getLast();}

    T& front() {return _list->getFirst();};
    const T& front() const {return _list->getFirst();}

    void erase(size_t i) {_list->erase(i);}
    void erase(size_t from, size_t to) {_list->erase(from, to);}
    T pop();

*/
    bool empty() {return _list->size() == 0;}
    size_t size() {return _list->size();}

private:
    Deque<T> *_list;
};


/*
template<typename T>
T Queue<T>::pop()
{
    T ret = front();
    erase(0);
    return ret;
}
*/
















#endif // QUEUE_HPP