#ifndef DECK_HPP
#define DECK_HPP


#include "ListSequence.hpp"

template <typename T>
class Deck {
public:
    Deck() : _list(new ListSequence<T>){}

    template <typename ...Args>
    Deck(Args&&... args) : _list(new ListSequence<T>(std::forward<Args>(args)...)) {}

    void pushLeft(const T &val) {_list->prepend(val);}
    void pushRight(const T &val) {_list->append(val);}

    T& back() {return _list->getLast();};
    const T& back() const {return _list->getLast();}

    T& front() {return _list->getFirst();};
    const T& front() const {return _list->getFirst();}

    void erase(size_t i) {_list->erase(i);}
    void erase(size_t from, size_t to) {_list->erase(from, to);}
    T popLeft();
    T popRight();


    bool empty() {return _list->size() == 0;}
    size_t size() {return _list->size();}

private:
    ListSequence<T> *_list;
};



template<typename T>
T Deck<T>::popLeft()
{
    T ret = front();
    erase(0);
    return ret;
}

template<typename T>
T Deck<T>::popRight()
{
    T ret = back();
    erase(size()-1);
    return ret;
}
















#endif // DECK_HPP