#include <iostream>
#include "smart_ptr_test.h"
#include "ScopeExit _test.h"
#include "PointerContainer_test.h"
#include "pool_test.h"

int main() {

#if 0
    test_scope_prt();
    std::cout << "=====================" << std::endl;
    test_scoped_array();
    std::cout << "=====================" << std::endl;
    test_shared_ptr();
    std::cout << "=====================" << std::endl;
    test_make_shared();
    std::cout << "=====================" << std::endl;
    test_shared_array();
    std::cout << "=====================" << std::endl;
    test_optimise_shared_ptr();
    std::cout << "=====================" << std::endl;
    test_weak_ptr();
    std::cout << "=====================" << std::endl;
#endif

#if 0
    test_ptr_vector();
    std::cout << "=====================" << std::endl;
    test_ptr_set();
    std::cout << "=====================" << std::endl;
    test_ptr_vector_copy();
    std::cout << "=====================" << std::endl;

#endif


#if 0

    test_SCOPE_EXIT();
    test_SCOPE_EXIT_WITH_LAMBDA();

    test_SCOPE_EXIT_Peculiarities();

#endif

#if 1
    test_simple_segregated_storage();

    test_object_pool();
#endif



    return 0;
}