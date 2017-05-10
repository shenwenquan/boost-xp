//
// Created by ice on 2017/5/7.
//

#ifndef BOOST_XP_UTIL_H_H
#define BOOST_XP_UTIL_H_H
#include <boost/thread.hpp>
#include <boost/chrono.hpp>

void wait(int seconds)
{
    boost::this_thread::sleep_for(boost::chrono::seconds{seconds});
}
#endif //BOOST_XP_UTIL_H_H
