//
// Created by ice on 2017/5/7.
//

#ifndef BOOST_XP_POOL_TEST_H
#define BOOST_XP_POOL_TEST_H
#include <boost/pool/simple_segregated_storage.hpp>
#include <boost/pool/object_pool.hpp>
#include <vector>
#include <cstddef>
void test_simple_segregated_storage(){
    boost::simple_segregated_storage<std::size_t> storage;
    std::vector<char> v(1024);
    storage.add_block(&v.front(), v.size(), 256);

    int *i = static_cast<int*>(storage.malloc());
    *i = 1;
    *(i+63)=63;

    int *j = static_cast<int*>(storage.malloc_n(1, 512));
    j[10] = 2;

//
//    int *k = static_cast<int*>(storage.malloc_n(1, 1024));
//    k[10] = 3;

    storage.free(i);
    storage.free_n(j, 1, 512);
}

void test_object_pool(){
    boost::object_pool<int> pool;

    int *i = pool.malloc();
    *i = 1;

    int *j = pool.construct(2);

    pool.destroy(i);
    pool.destroy(j);
}

#endif //BOOST_XP_POOL_TEST_H
