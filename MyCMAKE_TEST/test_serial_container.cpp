#include <gtest/gtest.h>
#include "Serial_container.hpp"

#define CONTAINER_NAME SERIAL_CONTAINER
#define LIST_CONT  Serial_container
using container = Serial_container<int>;


TEST(CONTAINER_NAME, size_container) {
    container list{ 0,1,2,3,4,5,6,7,8,9 };
    int size_cont = 10;
    ASSERT_EQ(list.size(), size_cont);
}

TEST(CONTAINER_NAME, create_container) {
    container list{ 0,1,2,3,4,5,6,7,8,9 };
    int past_add_one_number = 11;
    list.push_back(10);
    ASSERT_EQ(list.size(), past_add_one_number);
}

TEST(CONTAINER_NAME, push_back) {
    container list{ 0,1,2,3,4,5,6,7,8,9 };
    int past_add_one_number = 11;
    int new_element = 10;
    list.push_back(new_element);
    ASSERT_EQ(list.size(), past_add_one_number);
    ASSERT_EQ(list[10], new_element);
}

TEST(CONTAINER_NAME, insert_in_begin) {
    container list{ 0,1,2,3,4,5,6,7,8,9 };
    int past_add_one_number = 11;
    int new_element = 10;
    list.insert(new_element, 0);
    ASSERT_EQ(list.size(), past_add_one_number);
    ASSERT_EQ(list[0], new_element);
}

TEST(CONTAINER_NAME, insert_in_middle) {
    container list{ 0,1,2,3,4,5,6,7,8,9 };
    int past_add_one_number = 11;
    int new_element = 10;
    list.insert(new_element, 5);
    ASSERT_EQ(list.size(), past_add_one_number);
    ASSERT_EQ(list[5], new_element);
}

TEST(CONTAINER_NAME, deletion_from_the_middle) {
    container list{ 0,1,2,3,4,5,6,7,8,9 };
    list.erase(4);
    int new_middle_element = 5;
    int past_remove_one_number = 9;
    ASSERT_EQ(list.size(), past_remove_one_number);
    ASSERT_EQ(list[4], new_middle_element);
}

TEST(CONTAINER_NAME, deletion_from_the_begin) {
    container list{ 0,1,2,3,4,5,6,7,8,9 };
    list.erase(0);
    int new_begin_element = 1;
    int past_remove_one_number = 9;
    ASSERT_EQ(list.size(), past_remove_one_number);
    ASSERT_EQ(list[0], new_begin_element);
}

TEST(CONTAINER_NAME, get_element) {
    container list{ 0,1,2,3,4,5,6,7,8,9 };
    int val_element = 4;
    ASSERT_EQ(list[4], val_element);
}

TEST(CONTAINER_NAME, copy_container) {
    container list{ 0,1,2,3,4,5,6,7,8,9};
    int val_for = 12;
    //container list2(list);

}

class test_destr {
public:
    ~test_destr() {
        i = 1;
    }
    int i = 0;
};

TEST(CONTAINER_NAME, destr_container) {
    test_destr val;
    LIST_CONT<test_destr>* list = new LIST_CONT<test_destr>();
    list->push_back(val);
    delete list;
    int val_posle_start_distr = 1;
    int for_eq = (&val == nullptr) ? 2 : val.i;
    ASSERT_EQ(for_eq, val_posle_start_distr);
}

TEST(CONTAINER_NAME, move_container) {
    container list{ 0,1,2,3,4,5,6,7,8,9 };
    container list2(std::move(list));
    ASSERT_NE(list.size(), list2.size());
}

TEST(CONTAINER_NAME, deletion_from_the_end) {
    container list{ 0,1,2,3,4,5,6,7,8,9 };
    int past_add_one_number = 11;
    int new_element = 10;
    list.push_back(new_element);
    ASSERT_EQ(list.size(), past_add_one_number);
    ASSERT_EQ(list[10], new_element);
    list.erase(10);
    int old_end_element = 9;
    int past_remove_one_number = 10;
    ASSERT_EQ(list.size(), past_remove_one_number);
    ASSERT_EQ(list[9], old_end_element);
}


