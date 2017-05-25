//
// Created by apple on 2017/5/25.
//

#ifndef BOOST_XP_FUTURE_TEST_H
#define BOOST_XP_FUTURE_TEST_H

//#define BOOST_THREAD_PROVIDES_FUTURE
//#define BOOST_THREAD_PROVIDES_FUTURE_CONTINUATION
#include <boost/lexical_cast.hpp>
#include <boost/thread.hpp>
#include <boost/thread/future.hpp>
#include <boost/lexical_cast.hpp>
#include <vector>
void callback_function()
{
    std::cout << "Wait is called and promise not ready yet" << std::endl;
}

void test_promise()
{
//    boost::promise<std::string> promise;
//    boost::unique_future<std::string> fut = promise.get_future();
//    promise.set_wait_callback(boost::bind(callback_function));
//
//    boost::thread([&]{ sleep(4); promise.set_value("test"); });
//
//    std::cout << fut.get();
}

int test_future2()
{

//    std::cout<<"main thread id : "<<boost::this_thread::get_id()<<std::endl;
//    boost::future<int> f1 = boost::async(boost::launch::async, []()
//    {
//        std::cout<<"async thread id : "<<boost::this_thread::get_id()<<std::endl;
//        return 123;
//    });
//    boost::future<std::string> f2 = f1.then(boost::launch::deferred, [](boost::future<int> f)
//    {
//        std::cout<<"then id : "<<boost::this_thread::get_id()<<std::endl;
//        return boost::lexical_cast<std::string>(f.get());
//    });
//
//    f2.wait();
//
//    std::cout << f2.get()<<std::endl;
}


int the_answer()
{
    return 42;
}
void test_mul_promise(){


    std::vector<boost::unique_future<int> > futures;
    for (int i=0; i < 4; ++i)
    {
        boost::packaged_task<int> pt(the_answer);
        futures.push_back(pt.get_future());
        boost::thread task(std::move(pt));
    }
    boost::wait_for_all(futures.begin(), futures.end());

    for(size_t n=0; n<futures.size(); ++n)
        std::cout << futures[n].get() << ' ';
    std::cout << '\n';
}

#endif //BOOST_XP_FUTURE_TEST_H
