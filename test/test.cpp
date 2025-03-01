#include <iostream>
#include "./skiplist.h"
#define FILE_PATH "./store/dumpFile"


int main() {

    // 键值中的key用int型，若不是内置类型，需要自定义比较函数
    // 而且如果修改key的类型，同时需要修改SkipList.load_file函数

    SkipList<int, std::string> skipList(6);

    // skipList.load_file(FILE_PATH);

	skipList.insert_element(1, "你好"); 
	skipList.insert_element(3, "不会");
    skipList.insert_element(4, "不会"); 
	skipList.insert_element(7, "试试"); 
	skipList.insert_element(8, "学习刻苦努力"); 
	skipList.insert_element(9, "吃饭"); 
	skipList.insert_element(18, "什百"); 
	skipList.insert_element(18, "计算器"); 

    std::cout << "skipList size: " << skipList.size() << std::endl;

    skipList.dump_file();

    // 查找
    skipList.search_element(9);
    skipList.search_element(18);

    skipList.display_list();

    // 删除
    skipList.delete_element(3);
    skipList.delete_element(7);
    skipList.delete_element(100);     // 没有的key跳过

    std::cout << "skipList size: " << skipList.size() << std::endl;

    skipList.display_list();
}