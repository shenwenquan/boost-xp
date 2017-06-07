//
// Created by ice on 2017/6/7.
//

#ifndef BOOST_XP_WORK_QUEUE_TEST_H
#define BOOST_XP_WORK_QUEUE_TEST_H

#include <deque>
#include <boost/function.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/locks.hpp>
#include <boost/thread/condition_variable.hpp>
#include <boost/thread/thread.hpp>
#include <iostream>
class work_queue{

public:
    typedef boost::function<void()> task_type;

private:
    std::deque<task_type> tasks_;
    boost::mutex tasks_mutex_;
    boost::condition_variable cond_;

public:
    void push_task(const task_type& task){
        boost::unique_lock<boost::mutex> lock(tasks_mutex_);
        tasks_.push_back(task);
        lock.unlock();
        cond_.notify_one();
    }

    task_type try_pop_task(){
        task_type ret;
        boost::lock_guard<boost::mutex> lock(tasks_mutex_);
        if(!tasks_.empty()){
            ret = tasks_.front();
            tasks_.pop_front();
        }
        return ret;
    }

    task_type pop_task(){
        boost::unique_lock<boost::mutex> lock(tasks_mutex_);
        while(tasks_.empty()){
            cond_.wait(lock);
        }
        task_type ret = std::move(tasks_.front());
        tasks_.pop_front();
        return ret;
    }

};

work_queue g_queue;
void do_nothing(){
    std::cout<<"......." << std::endl;
}

const std::size_t tests_tasks_count = 3;

void pusher(){

    for(std::size_t i = 0;i< tests_tasks_count;i++){
        g_queue.push_task(&do_nothing);
    }
}

void popper_sync(){
    for(std::size_t i = 0;i< tests_tasks_count;i++){
        work_queue::task_type type=  g_queue.pop_task();
    }
}


void test_work_queue(){



    boost::thread pop_sync1(&popper_sync);
    boost::thread pop_sync2(&popper_sync);
    boost::thread pop_sync3(&popper_sync);

    boost::thread push1(&pusher);
    boost::thread push2(&pusher);
    boost::thread push3(&pusher);


    pop_sync1.join();
    pop_sync2.join();
    pop_sync3.join();

    push1.join();
    push2.join();
    push3.join();

    assert(!g_queue.try_pop_task());
    g_queue.push_task(&do_nothing);
    assert(g_queue.try_pop_task());


}


#endif //BOOST_XP_WORK_QUEUE_TEST_H
