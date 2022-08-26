#include <signal.h>
#include "shm_data.hpp"
#include <sys/mman.h>
#include <fcntl.h> 
#include <sys/stat.h>     
#include <iostream>
#include <errno.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>


static bool keepRunning = true;

void c_exit(int signum) {
    keepRunning = false;
}


int main() {

    signal(SIGINT, c_exit);

    int shm_fd = -1;

    while (shm_fd < 0 && keepRunning) {
        shm_fd = shm_open(get_key().c_str(), O_RDWR, 0666);
        if (shm_fd < 0) {
            if(errno != ENOENT) {
                std::cerr << "NOPE - erro brabo: " << errno << std::endl;
            }
        }
        usleep(10000);
    }
    
    if (!keepRunning) exit(errno);

    long page_size = sysconf(_SC_PAGE_SIZE);
    off_t shm_size = (sizeof(ShmData)/page_size + 1)*page_size;


    ShmData* Pointer = reinterpret_cast<ShmData*>(
        mmap(0, shm_size,
        PROT_WRITE | PROT_READ,
        MAP_SHARED | MAP_NORESERVE,
        shm_fd, 0));

    if (Pointer == MAP_FAILED) {
        std::cerr << "PAHHH" << std::endl; 
        std::cerr << errno << std::endl; 
    }

    assert(close(shm_fd) == 0);
    std::cout << "Before Loop!" << std::endl;

    while(keepRunning) {
        sem_wait(&(Pointer->Mutex));
        std::cout << "current value is " << Pointer->counter << std::endl;
        sem_post(&(Pointer->Mutex));
    }

    return 0;
}