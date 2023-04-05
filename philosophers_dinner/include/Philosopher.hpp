
enum class State {
    thinking, 
    waiting, 
    eating,
    starving
};

enum class Fork_State {
    free,
    taken,
    in_use
};

class Philosopher {
    
    Philosopher() = default;
    ~Philosopher() = default;

    void Eating();
    void Waiting();
    void Thinking();
    void Starved();

private:
    State state;
    int life;
    Fork_State left_fork;
    Fork_State right_fork;
};