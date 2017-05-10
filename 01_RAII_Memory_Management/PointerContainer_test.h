//
// Created by ice on 2017/5/7.
//

#ifndef BOOST_XP_POINTERCONTAINER_TEST_H
#define BOOST_XP_POINTERCONTAINER_TEST_H
#include <boost/ptr_container/ptr_vector.hpp>
#include <boost/ptr_container/ptr_set.hpp>
#include <boost/ptr_container/indirect_fun.hpp>
#include <boost/ptr_container/ptr_inserter.hpp>
#include <array>
#include <algorithm>
#include <set>
#include <memory>
#include <functional>
#include <iostream>

void test_ptr_vector(){
    boost::ptr_vector<int> v;
    v.push_back(new int{1});
    v.push_back(new int{2});
    std::cout << v.back() << '\n';
}

void test_ptr_set(){
    boost::ptr_set<int> s;
    s.insert(new int{2});
    s.insert(new int{1});
    std::cout << *s.begin() << '\n';

    std::set<std::unique_ptr<int>, boost::indirect_fun<std::less<int>>> v;
    v.insert(std::unique_ptr<int>(new int{2}));
    v.insert(std::unique_ptr<int>(new int{1}));
    std::cout << **v.begin() << '\n';
}

void test_ptr_vector_copy(){
    boost::ptr_vector<int> v;
    std::array<int, 3> a{{0, 1, 2}};
    std::copy(a.begin(), a.end(), boost::ptr_container::ptr_back_inserter(v));
    std::cout << v.size() << '\n';
}


#endif //BOOST_XP_POINTERCONTAINER_TEST_H
