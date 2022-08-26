#ifndef shm_data_hpp
#define shm_data_hpp

#include <semaphore.h>
#include <string>

struct ShmData {
    sem_t Mutex;
    int counter;
};

std::string get_key() {
    return "/my_example_shm_key";
}


#endif
