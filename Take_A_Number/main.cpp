#include <iostream>
#include <pthread.h>
#include <thread>
#include <random>
#include "Clerk.hpp"
#include "Customer.hpp"
#include "QueueManagingSystem.hpp"
#include <map>

/*
https://learn.saylor.org/mod/book/view.php?id=26823&chapterid=2900

Problem Statement: Take-a-Number

To illustrate how to address the sorts of problems that can arise when you try to synchronize threads, let’s consider a simple application in which several threads use a shared resource. You’re familiar with those take-a-number devices that are used in bakeries to manage a waiting line. Customers take a number when they arrive, and the clerk announces who’s next by looking at the device. As customers are called, the clerk increments the “next customer” counter by one.

There are some obvious potential coordination problems here. The device must keep proper count and can’t skip customers. Nor can it give the same number to two different customers. Nor can it allow the clerk to serve nonexistent customers.

Our task is to build a multithreaded simulation that uses a model of a take-a-number device to coordinate the behavior of customers and a (single) clerk in a bakery waiting line. To help illustrate the various issues involved in trying to coordinate threads, we will develop more than one version of the program.

*/

using time = int;
using qnumber = int;

struct Time {
    time time_last_customer_entered;

};

static bool store_is_open = true;

int main(int* argc, char* argv[]) {

    time time_ms = 0;
    Clerk clerk{};
    QueueManagingSystem queue_ms{};


    std::random_device rd;  
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 6);
    auto customer_will_enter = [&distrib, &gen](){ return distrib(gen) > 5; }; // Probability 1 out of 6
    auto how_many_customers_will_enter = [&distrib, &gen](){ return distrib(gen); }; // 1-6 customers
    std::map<qnumber, Customer> customers;

    while(store_is_open) {

        if (customer_will_enter()) {
            for(int i=0; i < how_many_customers_will_enter(); i++) {
                
            }
        }

        time_ms++;

    }
    
}