// Leetcode 346. Moving Average from Data Stream
#include <iostream>
#include <queue>

class MovingAverage {
private:
    std::queue<int> q;  // FIFO
    int maxSize;
    double currentSum;

public:
    MovingAverage(int size) {
        maxSize = size;
        currentSum = 0.0;
    }
    double next(int val) {
        // 當Queue已經滿了丟掉最前面的
        if (q.size() == maxSize) {
            currentSum -= q.front();
            q.pop();
        }
        q.push(val);
        currentSum += val;

        return currentSum / q.size();
    }
};

int main() {
    // 範例驗證：設定視窗大小為 3
    MovingAverage ma(3);

    std::cout << "Input: 1  -> Average: " << ma.next(1) << " (Expected: 1.0)" << std::endl;
    std::cout << "Input: 10 -> Average: " << ma.next(10) << " (Expected: 5.5)" << std::endl;
    std::cout << "Input: 3  -> Average: " << ma.next(3) << " (Expected: 4.66667)" << std::endl;
    std::cout << "Input: 5  -> Average: " << ma.next(5) << " (Expected: 6.0)" << std::endl; // (10+3+5)/3

    return 0;
}

/*
題目一：時間與空間複雜度分析
問題： 在上述實作中，next(int val) 函數的時間複雜度是多少？O(1)空間複雜度是多少？O(W)

考核點： 確保你理解 Queue 操作的效率。
題目二：數值溢位 (Overflow) 與精確度
問題： 如果整數流非常大且視窗大小（Window Size）也很大，currentSum += val 可能會發生什麼問題？你會如何優化以維持精確度？

考核點： 測試對資料型別（int vs long long vs double）的敏感度。
題目三：記憶體優化 (Circular Buffer)
問題： 雖然 std::queue 很好用，但在嵌入式或高性能控制系統中，動態配置（Dynamic Allocation）可能導致延遲。你會如何使用一個固定長度的陣列 (Array) 來實作這個功能？

考核點： 測試對「環形緩衝區 (Circular Buffer)」的實作能力，這在底層開發中極其重要。

*/