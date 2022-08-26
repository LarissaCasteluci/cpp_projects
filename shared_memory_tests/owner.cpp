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

    shm_unlink(get_key().c_str());
    int shm_fd = shm_open(get_key().c_str(), O_CREAT | O_RDWR | O_EXCL, 0666);

    if(shm_fd == -1) { 
        std::cerr << "PAHHH" << std::endl; 
        std::cerr << errno << std::endl; 
    }

    long page_size = sysconf(_SC_PAGE_SIZE);
    off_t shm_size = (sizeof(ShmData)/page_size + 1)*page_size;

    assert(ftruncate(shm_fd, shm_size) == 0);

    ShmData* Pointer = reinterpret_cast<ShmData*>(
        mmap(0, shm_size,
        PROT_WRITE,
        MAP_SHARED | MAP_NORESERVE,
        shm_fd, 0));

    if (Pointer == MAP_FAILED) {
        std::cerr << "PAHHH" << std::endl; 
        std::cerr << errno << std::endl; 
    }

    assert(close(shm_fd) == 0);
    assert(mlock(Pointer, shm_size) == 0);

    memset(Pointer, 0, shm_size);

    sem_init(&(Pointer->Mutex), 1, 1);

    std::cout << "Before Loop!" << std::endl;

    int i=0;
    while(keepRunning) {
        sem_wait(&(Pointer->Mutex));
        Pointer->counter = i;
        sem_post(&(Pointer->Mutex));
        i++;
        usleep(10000);
    }

    return 0;

}