#include <iostream>
#include <chrono>
#include <cstdlib>
#include <thread>
#include <vector>
#include <time.h>

#include "skiplist.h"

#define NUM_THREADS 8
#define TEST_COUNT 1000000

SkipList<int, std::string> skipList(18);

void insertElement(int tid) {
    std::cout << "Thread " << tid << " started." << std::endl;
    int tmp = TEST_COUNT / NUM_THREADS;
    for (int i = tid * tmp, count = 0; count < tmp; i++) {
        count++;
        skipList.insert_element(rand() % TEST_COUNT, "testValue");
    }
    std::cout << "Thread " << tid << " finished." << std::endl;
}

void getElement(int tid) {
    std::cout << "Thread " << tid << " started." << std::endl;
    int tmp = TEST_COUNT / NUM_THREADS;
    for (int i = tid * tmp, count = 0; count < tmp; i++) {
        count++;
        skipList.search_element(rand() % TEST_COUNT);
    }
    std::cout << "Thread " << tid << " finished." << std::endl;
}

int main() {
    srand(time(NULL));  // 使用当前时间初始化随机数种子


    std::vector<std::thread> threads;

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < NUM_THREADS; i++) {
        threads.emplace_back(insertElement, i);  // 创建线程执行插入操作
    }

    for (auto& th : threads) {
        th.join();  // 等待所有线程完成
    }

    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Insert elapsed: " << elapsed.count() << " seconds" << std::endl;
    

    // 查找操作
    // std::vector<std::thread> threads;
    threads.clear();
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < NUM_THREADS; i++) {
        threads.emplace_back(getElement, i);  // 创建线程执行查找操作
    }

    for (auto& th : threads) {
        th.join();  // 等待所有线程完成
    }

    finish = std::chrono::high_resolution_clock::now();
    elapsed = finish - start;
    std::cout << "Get elapsed: " << elapsed.count() << " seconds" << std::endl;
    
    

    return 0;
}


// 写 百万 8个线程   2.18s   读 20.96s（因为打印耗时 不打印的话 1.10s）