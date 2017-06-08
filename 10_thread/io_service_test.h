//
// Created by ice on 2017/6/8.
//

#ifndef BOOST_XP_IO_SERVICE_TEST_H
#define BOOST_XP_IO_SERVICE_TEST_H

#include <pthread.h>
#include <boost/thread/thread.hpp>
#include <boost/asio/io_service.hpp>

namespace detail {

    template<class T>
    struct task_wrapped {

    private:
        T task_unwrapped_;
    public:
        explicit task_wrapped(const T &task_unwrapped)
                : task_unwrapped_(task_unwrapped) {}

        void operator()() const {
            try {
                boost::this_thread::interruption_point();
            } catch (const boost::thread_interrupted &) {}

            try {
                task_unwrapped_();
            } catch (const std::exception &e) {
                std::cerr << "Exception:" << e.what() << '\n';
            } catch (const boost::thread_interrupted &) {
                std::cerr << "Thread interrupted \n";
            } catch (...) {
                std::cerr << "Unknown exception \n";
            }

        }

    };

    template<class T>
    task_wrapped<T> make_task_wrapped(const T &task_unwrapped) {

        return task_wrapped<T>(task_unwrapped);
    }


    class tasks_processor : private boost::noncopyable {


    public:
        static tasks_processor &get() {

            pthread_once(&ponce_, &tasks_processor::init);

            return *value_;
        }

        template<class T>
        inline void push_task(const T &task_unwrapped) {
            ios_.post(detail::make_task_wrapped(task_unwrapped));
        }

        void start() {
            ios_.run();
        }

        void stop() {
            ios_.stop();
        }

    private:

        static void init() {
            value_ = new tasks_processor();
        }

        tasks_processor() :
                ios_(),
                work_(ios_) {}

    private:
        boost::asio::io_service ios_;
        boost::asio::io_service::work work_;
        static pthread_once_t ponce_;
        static tasks_processor *value_;

    };

    pthread_once_t tasks_processor::ponce_ = PTHREAD_ONCE_INIT;
    tasks_processor *tasks_processor::value_ = NULL;

    int g_val = 0;

    void func_test() {
        ++g_val;
        if (g_val == 3) {
            throw std::logic_error("Just checking");
        }

        boost::this_thread::interruption_point();

        if (g_val == 10) {

            throw boost::thread_interrupted();
        }

        if (g_val == 90) {
            tasks_processor::get().stop();
        }


    }


    void test_io_service() {
        static const std::size_t tasks_count = 100;
        BOOST_STATIC_ASSERT(tasks_count > 90);
        for (std::size_t i = 0; i < tasks_count; i++) {
            tasks_processor::get().push_task(&func_test);
        }

        tasks_processor::get().push_task(boost::bind(std::plus<int>(), 2, 2));

        assert(g_val == 0);

        tasks_processor::get().start();
        assert(g_val == 90);
    }
}


#endif //BOOST_XP_IO_SERVICE_TEST_H
