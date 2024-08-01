#ifndef MY_DLINKED_LIST
#define MY_DLINKED_LIST


class my_dlinked_list {
private:
  class node {
  public:
    node * next = nullptr;
    node * prev = nullptr;
    int value;

    node();
    node(int value);
    ~node();
  };
  node * head = nullptr;
  node * tail = nullptr;
  int size = 0;

public:
  my_dlinked_list();
  ~my_dlinked_list();

  int is_empty();

  void insert_last(int value);
  
  int remove_last();
  
  void insert_at(int index, int value);
  
  int remove_at(int index);

  void to_string();

};

#endif

