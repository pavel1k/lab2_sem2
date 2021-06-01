#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <vector>
#include "DynamicArray.hpp"
#include "ArraySequence.hpp"
#include "Queue.hpp"
#include "List.hpp"
#include "ListSequence.hpp"
#include "Tests.h"

using namespace std;
template<class T>
void Menu(){
    Deque<int> DequeInt;
    Stack<int> StackInt;
    Queue<int> QueueInt;
    Deque<float> DequeFloat;
    Stack<float> StackFloat;
    Queue<float> QueueFloat;
    Deque<double> DequeDouble;
    Stack<double> StackDouble;
    Queue<double> QueueDouble;
//    T element;
    int a, b, c, d, f;
    float t;
    double s;
    cout << "choose type of structure:" << endl << "1 - int" << endl << "2 - float" << endl << "3 - double";
    cin >> a;
    switch(a){
        case 1:
            cout << "choose structure:" << endl << "1 - deque" << endl << "2 - stack" << endl << "3 - queue";
            cin >> b;
            switch(b) {
                case 1:

                    cout << "input amount of elements";
                    cin >> d;
                    for (size_t i = 0; i < d; ++i) {
                        cout << "input element: ";
                        cin >> f;
                        DequeInt.pushLeft(f);
                    }

                    while(true) {
                        cout <<"choose functions" << endl << "1 - push into the left side" << endl << "2 - push into the left side"<< endl << "3 - pop from the left side" << endl << "4 - pop from the right side" << endl << "5 - exit";
                        cin >> c;
                        if (c == 5) break;
                        switch (c) {
                            case 1:
                                cout << "input element: ";
                                cin >> f;
                                DequeInt.pushLeft(f);
                                break;
                            case 2:
                                cout << "input element: ";
                                cin >> f;
                                DequeInt.pushRight(f);
                                break;
                            case 3:
                                f = DequeInt.popLeft();
                                cout << f;
                                break;
                            case 4:
                                f = DequeInt.popRight();
                                cout << f;
                                break;
                            default:
                                break;
                        }
                    }
                    break;
                case 2:
                    cout << "input amount of elements";
                    cin >> d;
                    for (size_t i = 0; i < d; ++i) {
                        cout << "input element: ";
                        cin >> f;
                        StackInt.push(f);
                    }

                    while(true) {
                        cout << "choose functions" << endl << "1 - push" << endl << "2 - pop" << endl << "3 - exit";
                        cin >> c;
                        if (c == 3) break;
                        switch (c) {
                            case 1:
                                cout << "input element: ";
                                cin >> f;
                                StackInt.push(f);
                                break;
                            case 2:
                                f = StackInt.pop();
                                cout << f;
                                break;
                            default:
                                break;
                        }
                    }
                    break;
                case 3:
                    cout << "input amount of elements";
                    cin >> d;
                    for (size_t i = 0; i < d; ++i) {
                        cout << "input element: ";
                        cin >> f;
                        QueueInt.push(f);
                    }

                    while(true) {
                        cout << "choose functions" << endl << "1 - push" << endl << "2 - pop" << endl << "3 - exit";
                        cin >> c;
                        if (c == 3) break;
                        switch (c) {
                            case 1:
                                cout << "input element: ";
                                cin >> f;
                                QueueInt.push(f);
                                break;
                            case 2:
                                f = QueueInt.pop();
                                cout << f;
                                break;
                             default:
                                break;
                        }
                    }
                    break;
                default:
                    break;
            }
            break;
        case 2:
            cout << "choose structure:" << endl << "1 - deque" << endl << "2 - stack" << endl << "3 - queue";
            cin >> b;
            switch (b) {
                case 1:
                    cout << "input amount of elements";
                    cin >> d;
                    for (size_t i = 0; i < d; ++i) {
                        cout << "input element: ";
                        cin >> t;
                        DequeFloat.pushLeft(t);
                    }

                    while(true) {
                        cout << "choose functions" << endl << "1 - push into the left side" << endl << "2 - push into the left side"<< endl << "3 - pop from the left side" << endl << "4 - pop from the right side" << endl << "5 - exit";
                        cin >> c;
                        if (c == 5) break;
                        switch (c) {
                            case 1:
                                cout << "input element: ";
                                cin >> t;
                                DequeFloat.pushLeft(t);
                                break;
                            case 2:
                                cout << "input element: ";
                                cin >> t;
                                DequeFloat.pushRight(t);
                                break;
                            case 3:
                                t = DequeFloat.popLeft();
                                cout << t;
                                break;
                            case 4:
                                t = DequeFloat.popRight();
                                cout << t;
                                break;
                             default:
                                break;
                        }
                    }
                    break;
                case 2:
                    cout << "input amount of elements";
                    cin >> d;
                    for (size_t i = 0; i < d; ++i) {
                        cout << "input element: ";
                        cin >> t;
                        StackFloat.push(t);
                    }

                    while(true) {
                        cout << "choose functions" << endl << "1 - push" << endl << "2 - pop" << endl << "3 - exit";
                        cin >> c;
                        if (c == 3) break;
                        switch (c) {
                            case 1:
                                cout << "input element: ";
                                cin >> t;
                                StackFloat.push(t);
                                break;
                            case 2:
                                t = StackFloat.pop();
                                cout << t;
                                break;
                            default:
                                break;
                        }
                    }
                    break;
                case 3:
                    cout << "input amount of elements";
                    cin >> d;
                    for (size_t i = 0; i < d; ++i) {
                        cout << "input element: ";
                        cin >> t;
                        QueueFloat.push(t);
                    }

                    while(true) {
                        cout << "choose functions" << endl << "1 - push" << endl << "2 - pop" << endl << "3 - exit";
                        cin >> c;
                        if (c == 3) break;
                        switch (c) {
                            case 1:
                                cout << "input element: ";
                                cin >> t;
                                QueueFloat.push(t);
                                break;
                            case 2:
                                t = QueueFloat.pop();
                                cout << t;
                                break;
                            default:
                                break;
                        }
                    }
                    break;
                default:
                    break;
            }
            break;
        case 3:
            cout << "choose structure:" << endl << "1 - deque" << endl << "2 - stack" << endl << "3 - queue";
            cin >> b;
            switch(b) {
                case 1:
                    cout << "input amount of elements";
                    cin >> d;
                    for (size_t i = 0; i < d; ++i) {
                        cout << "input element: ";
                        cin >> s;
                        DequeDouble.pushLeft(s);
                    }

                    while(true) {
                        cout << "choose functions" << endl << "1 - push into the left side" << endl << "2 - push into the left side"<< endl << "3 - pop from the left side" << endl << "4 - pop from the right side" << endl << "5 - exit";
                        cin >> c;
                        if (c == 5) break;
                        switch (c) {
                            case 1:
                                cout << "input element: ";
                                cin >> s;
                                DequeDouble.pushLeft(s);
                                break;
                            case 2:
                                cout << "input element: ";
                                cin >> s;
                                DequeDouble.pushRight(s);
                                break;
                            case 3:
                                s = DequeDouble.popLeft();
                                cout << s;
                                break;
                            case 4:
                                s = DequeDouble.popRight();
                                cout << s;
                                break;
                            default:
                                break;
                        }
                    }
                    break;
                case 2:
                    cout << "input amount of elements";
                    cin >> d;
                    for (size_t i = 0; i < d; ++i) {
                        cout << "input element: ";
                        cin >> s;
                        StackDouble.push(s);
                    }

                    while(true) {
                        cout << "choose functions" << endl << "1 - push" << endl << "2 - pop" << endl << "3 - exit";
                        cin >> c;
                        if (c == 3) break;
                        switch (c) {
                            case 1:
                                cout << "input element: ";
                                cin >> s;
                                StackDouble.push(s);
                                break;
                            case 2:
                                s = StackDouble.pop();
                                cout << s;
                                break;
                            default:
                                break;
                        }
                    }
                    break;
                case 3:
                    cout << "input amount of elements";
                    cin >> d;
                    for (size_t i = 0; i < d; ++i) {
                        cout << "input element: ";
                        cin >> s;
                        QueueDouble.push(s);
                    }

                    while(true) {
                        cout << "choose functions" << endl << "1 - push" << endl << "2 - pop" << "3 - exit";
                        cin >> c;
                        if (c == 3) break;
                        switch (c) {
                            case 1:
                                cout << "input element: ";
                                cin >> s;
                                QueueDouble.push(s);
                                break;
                            case 2:
                                s = QueueDouble.pop();
                                cout << s;
                                break;
                            default:
                                break;
                        }
                    }
                    break;
                default:
                    break;
            }
            break;
        default:
            break;


    }

}






#endif //MENU_HPP