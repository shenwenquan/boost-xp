#include <iostream>
#include <future_test.h>
#include <pool_test.h>
#include "smart_ptr_test.h"
#include "ScopeExit _test.h"
#include "PointerContainer_test.h"
#include "pool_test.h"
#include "thread_test.h"
#include "tuple_test.h"
#include "thread_pool_test.h"
#include "work_queue_test.h"
#include "io_service_test.h"
#include "thread_pool_new_test.h"

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

#if 0
    test_simple_segregated_storage();

    test_object_pool();
#endif

#if 0

    test_tuple1();
    test_tuple2();
    test_tuple3();
    test_tuple4();
    test_tuple5();
    test_tuple6();
    test_tuple7();
    test_tuple8();
    test_tuple9();
    test_tuple10();
#endif

#if 0
    test_promise();
    test_future2();
//    std::list<int> ls = {1, 3, 4, 2};
//    std::list<int> ls2 = parallel_quick_sort<int>(ls);

    test_mul_promise();
    std::cout << "" << std::endl;

#endif

#if 0
    test_pool();

#endif

#if 0
    test_work_queue();
#endif
#if 0
    detail::test_io_service();
#endif
#if 1

    // create thread pool with 4 worker threads
    ThreadPool pool(10);

// enqueue and store future
    while(true){
        auto result = pool.enqueue([](int answer) { return answer; }, 42);

// get result from future
        std::cout << result.get() << std::endl;
    }


#endif
    return 0;
}