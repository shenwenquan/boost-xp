//
// Created by ice on 2017/5/7.
//

#ifndef BOOST_XP_SCOPEEXIT_TEST_H
#define BOOST_XP_SCOPEEXIT_TEST_H
#include <boost/scope_exit.hpp>
#include <utility>

int *foo()
{
    int *i = new int{10};
    BOOST_SCOPE_EXIT(&i)
        {
            delete i;
            i = 0;
        } BOOST_SCOPE_EXIT_END
    std::cout << *i << '\n';
    return i;
}

void test_SCOPE_EXIT(){
    int *j = foo();
    std::cout <<"j:"<< j << '\n';
    std::cout <<"v:"<< *j << '\n';
}
//====================================================================================================

template <typename T>
struct scope_exit
{
    scope_exit(T &&t) : t_{std::move(t)} {}
    ~scope_exit() { t_(); }
    T t_;
};

template <typename T>
scope_exit<T> make_scope_exit(T &&t) { return scope_exit<T>{
            std::move(t)}; }

int *foo2()
{
    int *i = new int{10};
    auto cleanup = make_scope_exit([&i]() mutable { delete i; i = 0; });
    std::cout << *i << '\n';
    return i;
}

void test_SCOPE_EXIT_WITH_LAMBDA(){
    int *j = foo2();
    std::cout << j << '\n';
}

//====================================================================================================

struct x
{
    int i;

    void foo()
    {
        i = 10;
        BOOST_SCOPE_EXIT(void)
            {
                std::cout << "last\n";
            } BOOST_SCOPE_EXIT_END
        BOOST_SCOPE_EXIT(this_)
            {
                this_->i = 20;
                std::cout << "first\n";
            } BOOST_SCOPE_EXIT_END
    }
};


//奇怪的用法
int test_SCOPE_EXIT_Peculiarities()
{
    x obj;
    obj.foo();
    std::cout << obj.i << '\n';
}

#endif //BOOST_XP_SCOPEEXIT_TEST_H
