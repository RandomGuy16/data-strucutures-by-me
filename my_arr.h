#ifndef MY_ARR
#define MY_ARR

class my_arr {
    private:
    int capacity;
    int * data;
    int items = 0;

    public:
    my_arr(int capacity);
    ~my_arr();

    int length();

    int get_at(int index);

    void set_at(int index, int value);

    void to_string();

};

#endif
