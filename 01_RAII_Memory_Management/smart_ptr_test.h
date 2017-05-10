//
// Created by ice on 2017/5/7.
//

#ifndef BOOST_XP_SMART_PTR_TEST_H
#define BOOST_XP_SMART_PTR_TEST_H
#define BOOST_SP_USE_QUICK_ALLOCATOR
#include <boost/scoped_ptr.hpp>
#include <boost/scoped_array.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/shared_array.hpp>
#include <boost/weak_ptr.hpp>
#include <thread>
#include <functional>
#include <typeinfo>
#include <iostream>
#include "utils.h"
#include "User.h"



void test_scope_prt(){
    boost::scoped_ptr<int> p{new int{1}};
    std::cout << *p << '\n';
    p.reset(new int{2});
    std::cout << *p.get() << '\n';
    p.reset();
    std::cout << std::boolalpha << static_cast<bool>(p) << '\n';
}

void test_scoped_array(){
    boost::scoped_array<int> p{new int[2]};
    *p.get() = 1;
    std::cout << *p.get() << '\n';
    p[1] = 20;
    std::cout << *(p.get()+1) << '\n';
    p.reset(new int[3]);
}

void test_shared_ptr(){
    boost::shared_ptr<int> p1{new int{1}};
    std::cout << *p1 << '\n';
    boost::shared_ptr<int> p2{p1};
    p1.reset(new int{2});
    std::cout << *p1.get() << '\n';
    p1.reset();
    std::cout << std::boolalpha << static_cast<bool>(p2) << '\n';
}

void test_make_shared(){
    auto p1 = boost::make_shared<int>(1);
    std::cout << typeid(p1).name() << '\n';
    auto p2 = boost::make_shared<int[]>(10);
    std::cout << typeid(p2).name() << '\n';
}

void test_shared_array(){
    boost::shared_array<int> p1{new int[2]};
    {
        boost::shared_array<int> p2{p1};
        p2[0] = 1;
        p2[1] = 10;
    }
    std::cout << p1[1] << '\n';
}

void test_optimise_shared_ptr(){
    boost::shared_ptr<int> p;
    std::time_t then = std::time(nullptr);
    for (int i = 0; i < 10000; ++i)
        p.reset(new int{i});
    std::time_t now = std::time(nullptr);
    std::cout <<"use time: " <<now - then << '\n';
}

void reset(boost::shared_ptr<User> &sh)
{
    wait(1);
    sh->setState(10000);
    std::cout << "reset shared ptr:" << sh.get()<< '\n';
    sh.reset();
    std::cout << "......." << '\n';
}

void print(boost::weak_ptr<User> &w)
{
    boost::shared_ptr<User> sh = w.lock();
    wait(2);
    if (sh)
        std::cout <<" print shared ptr:" << sh.get() << " state: "<<sh->getState() << '\n';
}

void test_weak_ptr(){
    boost::shared_ptr<User> sh{new User};
    std::cout<< "out state:" << sh->getState()<< std::endl;
    boost::weak_ptr<User> w{sh};
    std::thread t1{reset, std::ref(sh)};
    std::thread t2{print, std::ref(w)};
    t1.join();
    t2.join();
}



#endif //BOOST_XP_SMART_PTR_TEST_H
