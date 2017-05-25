//
// Created by apple on 2017/5/12.
//

#ifndef BOOST_XP_TUPLE_TEST_H
#define BOOST_XP_TUPLE_TEST_H

#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <boost/tuple/tuple_comparison.hpp>
#include <string>
#include <iostream>

void test_tuple1()
{
    typedef boost::tuple<std::string, int> animal;
    animal a{"cat", 4};
    std::cout << a << '\n';

}


void test_tuple2()
{
    typedef boost::tuple<std::string, int, bool> animal;
    animal a{"cat", 4, true};
    std::cout << std::boolalpha << a << '\n';
}

void test_tuple3()
{
    std::cout.setf(std::ios::boolalpha);
    std::cout << boost::make_tuple("cat", 4, true) << '\n';
}

void test_tuple4()
{
    std::string s = "cat";
    std::cout.setf(std::ios::boolalpha);
    std::cout << boost::make_tuple(boost::ref(s), 4, true) << '\n';
}

void test_tuple5(){
    typedef boost::tuple<std::string, int, bool> animal;
    animal a = boost::make_tuple("cat", 4, true);
    std::cout << a.get<0>() << '\n';
    std::cout << boost::get<2>(a) << '\n';
}

void test_tuple6()
{
    typedef boost::tuple<std::string, int, bool> animal;
    animal a = boost::make_tuple("cat", 4, true);
    a.get<0>() = "dog";
    std::cout << std::boolalpha << a << '\n';
}


void test_tuple7()
{
    typedef boost::tuple<std::string, int, bool> animal;
    animal a1 = boost::make_tuple("cat", 4, true);
    animal a2 = boost::make_tuple("shark", 0, true);
    std::cout << std::boolalpha << (a1 != a2) << '\n';
}

void test_tuple8() {
    typedef boost::tuple<std::string &, int &, bool &> animal;
    std::string name = "cat";
    int legs = 4;
    bool tail = true;
    animal a = boost::tie(name, legs, tail);
    name = "dog";
    std::cout << std::boolalpha << a << '\n';
}

void test_tuple9()
{
    typedef boost::tuple<std::string&, int&, bool&> animal;
    std::string name = "cat";
    int legs = 4;
    bool tail = true;
    animal a = boost::make_tuple(boost::ref(name), boost::ref(legs),
                                 boost::ref(tail));
    name = "dog";
    std::cout << std::boolalpha << a << '\n';
}

boost::tuple<std::string, int> new_cat()
{
    return boost::make_tuple("cat", 4);
}

void test_tuple10()
{
    std::string name;
    int legs;
    boost::tie(name, legs) = new_cat();
    std::cout << name << ", " << legs << '\n';
}


#endif //BOOST_XP_TUPLE_TEST_H
