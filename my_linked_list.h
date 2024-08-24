#ifndef MY_LINKED_LIST
#define MY_LINKED_LIST


class my_linked_list {
private:
  class node {
  public:
    node * next = nullptr;
    int value;

    node();
    node(int value);
    ~node();
  };
  node * head = nullptr;
  node * tail = nullptr;
  int size = 0;

public:
  my_linked_list();
  ~my_linked_list();

  int is_empty();

  void insert_last(int value);
  
  int remove_last();
  
  void insert_first(int value);
  int remove_first();

  void insert_at(int index, int value);
  
  int remove_at(int index);

  void to_string();

};

#endif

