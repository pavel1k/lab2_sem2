#ifndef TEST_H
#define TEST_H

#include <stdexcept>

#include "DynamicArray.hpp"
#include "ArraySequence.hpp"
#include "List.hpp"
#include "ListSequence.hpp"

#include "Queue.hpp"
#include "Stack.hpp"
#include "Deque.hpp"



template<typename T1, typename T2>
void assert_equal(const T1 &a, const T2 &b, const char* msg = "Not equal in assert_equal!"){
    if(a != b){
        throw std::logic_error(msg);
    }
}


typedef enum {
    OK,
    ERROR
} Error;

template<typename FRet, typename ...FArgs>
class TestFunction {
public:
    FRet operator() (FArgs... args) {return function(args...);}

    const char *name;
    FRet (*const function)(FArgs...);
};

template<typename FRet, typename ...FArgs>
void run_tests(TestFunction<FRet, FArgs...> functions[], size_t n)
{
    unsigned short errors = 0;

    for(unsigned short i = 0; i < n; ++i){
        printf("[%d/%d] Test %s: ", i+1, n, functions[i].name);

        try {
            functions[i]();
            printf("OK");
        }
        catch (std::exception &ex) {
            printf("ERROR!\n");
            printf("%6c%s", ' ', ex.what());
            ++errors;
        }


        printf("\n");
    }

    printf("\n\nTotal: tests: %d, errors: %d\n", n, errors);
    if(errors == 0)
        printf("ALL OK\n");
}

void test_dynamic_array_basics()
{
    // const-val constructor
    DynamicArray<int> array(5, 10);
    for(size_t i = 0; i < array.size(); ++i){
        assert_equal(array.get(i), 10);
    }

    // copy constructor and operator==
    DynamicArray<int> array2 = array;
    assert_equal(array, array2);


    //array and iter constructors
    int a[] = {1, 2, 3, 4, 5};
    array = DynamicArray<int>(a, 5);
    for(size_t i = 0; i < array.size(); ++i){
        assert_equal(array.get(i), i+1);
    }

    array2 = DynamicArray<int>(a, a+5);
    assert_equal(array, array2);
}

void test_dynamic_array_operations()
{
    int a[10];
    DynamicArray<int> array;
    for(size_t i = 0; i < 10; ++i){
        array.push_back(i);
        a[i] = static_cast<int>(i);
    }
    assert_equal(array, DynamicArray<int>(a, 10, true));

    int a2[] = {0, 1, 2, 3, 6, 7, 8, 9};
    DynamicArray<int> array2 = array;
    array2.erase(4, 6);
    assert_equal(array2, DynamicArray<int>(a2, 8, true));

    array2.clear();
    assert_equal(array2, DynamicArray<int>());
}

void test_array_sequence_basics()
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    //forward constructor
    ArraySequence<int> s1(a, 10, true);
    ArraySequence<int> s2(a, a+10);

    for(size_t i = 0; i < 10; ++i)
        assert_equal(s1[i], s2[i]);
}

void test_array_sequence_operations()
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto s1 = new ArraySequence<int>();

    for(size_t i = 0; i < 10; ++i){
        s1->prepend(i);
        s1->append(i);
    }

    for(size_t i = 0; i < s1->size() / 2; ++i){
        assert_equal(s1->get(i), s1->get(s1->size() - 1 - i));
    }

    auto s2 = s1->getSubsequence(10, s1->size());
    for(size_t i = 0; i < 10; ++i){
        assert_equal(s2->get(i), i);
    }
}

void test_array_sequence_iterator()
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto s1 = ArraySequence<int>(a, 10, false);
    auto s2 = ArraySequence<int>();

    for(int k : s1){
        s2.append(k);
    }

    for(size_t i = 0; i < s1.size(); ++i)
        assert_equal(s1[i], s2[i]);
}

void test_list_basics()
{
    // const-val constructor
    List<int> list(5, 10);
    for(size_t i = 0; i < list.size(); ++i){
        assert_equal(list.get(i), 10);
    }

    // copy constructor and operator==
    List<int> list2 = list;
    assert_equal(list, list2);


    //array and iter constructors
    int a[] = {1, 2, 3, 4, 5};
    list = List<int>(a, 5);
    for(size_t i = 0; i < list.size(); ++i){
        assert_equal(list.get(i), i+1);
    }

    list2 = List<int>(a, a+5);
    assert_equal(list, list2);
}

void test_list_operations()
{
    int a[10];
    List<int> list;
    for(size_t i = 0; i < 10; ++i){
        list.append(i);
        a[i] = static_cast<int>(i);
    }
    assert_equal(list, List<int>(a, 10));

    int a2[] = {0, 1, 2, 3, 6, 7, 8, 9};
    List<int> list2 = list;
    list2.erase(4, 6);
    assert_equal(list2, List<int>(a2, 8));

    list2.clear();
    assert_equal(list2, List<int>());
}

void test_list_sequence_basics()
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    //forward constructor
    ListSequence<int> s1(a, 10);
    ListSequence<int> s2(a, a+10);

    for(size_t i = 0; i < 10; ++i)
        assert_equal(s1[i], s2[i]);
}

void test_list_sequence_operations()
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto s1 = new ListSequence<int>();

    for(size_t i = 0; i < 10; ++i){
        s1->prepend(i);
        s1->append(i);
    }

    for(size_t i = 0; i < s1->size() / 2; ++i){
        assert_equal(s1->get(i), s1->get(s1->size() - 1 - i));
    }

    auto s2 = s1->getSubsequence(10, s1->size());
    for(size_t i = 0; i < 10; ++i){
        assert_equal(s2->get(i), i);
    }
}

void test_list_sequence_iterator()
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto s1 = ListSequence<int>(a, 10);
    auto s2 = ListSequence<int>();

    for(int k : s1){
        s2.append(k);
    }

    for(size_t i = 0; i < s1.size(); ++i)
        assert_equal(s1[i], s2[i]);
}



void test_queue()
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    //forward constructor
    Queue<int> q1(a, 10);
    Queue<int> q2(a, a+10);

    for(size_t i = 0; i < 10; ++i)
        assert_equal(q1.pop(), q2.pop());

    assert_equal(q1.size(), 0);
    assert_equal(q2.size(), 0);
}

void testStack()
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    //forward constructor
    Stack<int> s1(a, 10);
    Stack<int> s2(a, a+10);

    for(size_t i = 0; i < 10; ++i)
        assert_equal(s1.pop(), s2.pop());

    assert_equal(s1.size(), 0);
    assert_equal(s2.size(), 0);
}

void testDeque()
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    //forward constructor
    Deque<int> d1(a, 10);
    Deque<int> d2(a, a + 10);

    for(size_t i = 0; i < 10; ++i)
        assert_equal(d1.popRight(), d2.popRight());

    assert_equal(d1.size(), 0);
    assert_equal(d2.size(), 0);
}




void test_map()
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Sequence<int> *s = new ArraySequence<int>(a, 10, true);

    ArraySequence<int> *s1 = map(static_cast<ArraySequence<int>*>(s), [](int x){return x*x;});

    for(size_t i = 0; i < 10; ++i)
        assert_equal(s1->get(i), i*i);
}

void test_where()
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Sequence<int> *s = new ArraySequence<int>(a, 10, true);

    ArraySequence<int> *s1 = where(static_cast<ArraySequence<int>*>(s), [](int x){return x >= 5;});

    for(size_t i = 5; i < 10; ++i)
        assert_equal(s1->get(i-5), i);
}

void test_reduce()
{
    int a[] = {1, 2, 3};
    ArraySequence<int> *s = new ArraySequence<int>(a, 3, true);

    int ret = reduce(s, [](int a, int b){return 2*a+3*b;}, 4);

    assert_equal(ret, 144);
}

#endif // TEST_H