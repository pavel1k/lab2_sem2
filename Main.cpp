#include <iostream>
#include <vector>

#include "DynamicArray.hpp"
#include "ArraySequence.hpp"
#include "Queue.hpp"
#include "List.hpp"
#include "ListSequence.hpp"
#include "Tests.h"

using namespace std;




int main()
{
    TestFunction<void> functions[] = {
            {"dynamic_array_basics", test_dynamic_array_basics},
            {"dynamic_array_operations", test_dynamic_array_operations},
            {"array_sequence_basics", test_array_sequence_basics},
            {"array_sequence_operations", test_array_sequence_operations},
            {"array_sequence_iterator", test_array_sequence_iterator},

            {"list_basics", test_list_basics},
            {"list_operations", test_list_operations},
            {"list_sequence_basics", test_list_sequence_basics},
            {"list_sequence_operations", test_list_sequence_operations},
            {"list_sequence_iterator", test_list_sequence_iterator},

            {"queue", test_queue},
            {"stack", testStack},
            {"deck", testDeck},
            {"map", test_map},
            {"where", test_where},
            {"reduce", test_reduce}
    };

    run_tests(functions, sizeof(functions) / sizeof (TestFunction<void>));
}


