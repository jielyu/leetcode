/*
#面试刷题# 第80期
#Leetcode# Q1396 设计地铁系统
难度：中
实现支持三种方法的UndergroundSystem类：
1. checkIn（int id，string stationName，int t）
身份证等于id的客户在时间t进入车站stationName。
一次只能将客户签入一个地方。
2. checkOut（int id，字符串stationName，int t）
身份证等于id的客户在时间t从车站stationName下车。
3. getAverageTime（字符串startStation，字符串endStation）
返回在startStation和endStation之间旅行的平均时间。
平均时间是根据之前发生的从startStation到endStation的所有直接旅行计算得出的。
调用getAverageTime始终有效。
您可以假定对checkIn和checkOut方法的所有调用都是一致的。 
也就是说，如果客户在某个时间的时间t1进入某个站点，那么它会在时间t2离开t2> t1。 
所有事件均按时间顺序发生。
约束条件：
(a) 最多有2000次操作
(b) 1 <= id, t <= 10^6
(c) 所有字符串是由大小写英文字母和数字组成
(d) 1 <= stationName.length <= 10
(e) 精度在10^-5范围内的答案可以认为是正确的

例1:
Input
["UndergroundSystem","checkIn","checkIn","checkIn","checkOut","checkOut","checkOut","getAverageTime","getAverageTime","checkIn","getAverageTime","checkOut","getAverageTime"]
[[],[45,"Leyton",3],[32,"Paradise",8],[27,"Leyton",10],[45,"Waterloo",15],[27,"Waterloo",20],[32,"Cambridge",22],["Paradise","Cambridge"],["Leyton","Waterloo"],[10,"Leyton",24],["Leyton","Waterloo"],[10,"Waterloo",38],["Leyton","Waterloo"]]

Output
[null,null,null,null,null,null,null,14.0,11.0,null,11.0,null,12.0]

Explanation
UndergroundSystem undergroundSystem = new UndergroundSystem();
undergroundSystem.checkIn(45, "Leyton", 3);
undergroundSystem.checkIn(32, "Paradise", 8);
undergroundSystem.checkIn(27, "Leyton", 10);
undergroundSystem.checkOut(45, "Waterloo", 15);
undergroundSystem.checkOut(27, "Waterloo", 20);
undergroundSystem.checkOut(32, "Cambridge", 22);
undergroundSystem.getAverageTime("Paradise", "Cambridge");       // return 14.0. There was only one travel from "Paradise" (at time 8) to "Cambridge" (at time 22)
undergroundSystem.getAverageTime("Leyton", "Waterloo");          // return 11.0. There were two travels from "Leyton" to "Waterloo", a customer with id=45 from time=3 to time=15 and a customer with id=27 from time=10 to time=20. So the average time is ( (15-3) + (20-10) ) / 2 = 11.0
undergroundSystem.checkIn(10, "Leyton", 24);
undergroundSystem.getAverageTime("Leyton", "Waterloo");          // return 11.0
undergroundSystem.checkOut(10, "Waterloo", 38);
undergroundSystem.getAverageTime("Leyton", "Waterloo");          // return 12.0
*/
#include "leetcode.h"

namespace q1396{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below
    slt.checkIn(45, "Leyton", 3);
    slt.checkIn(32, "Paradise", 8);
    slt.checkIn(27, "Leyton", 10);
    slt.checkOut(45, "Waterloo", 15);
    slt.checkOut(27, "Waterloo", 20);
    slt.checkOut(32, "Cambridge", 22);
    CHECK_RET(std::abs(14 - slt.getAverageTime("Paradise", "Cambridge")) < 1e-5);
    CHECK_RET(std::abs(11 - slt.getAverageTime("Leyton", "Waterloo")) < 1e-5);
    slt.checkIn(10, "Leyton", 24);
    CHECK_RET(std::abs(11 - slt.getAverageTime("Leyton", "Waterloo")) < 1e-5);
    slt.checkOut(10, "Waterloo", 38);
    CHECK_RET(std::abs(12 - slt.getAverageTime("Leyton", "Waterloo")) < 1e-5);
    // succ
    return true;
}

// Runtime: 304 ms, faster than 96.01%
// Memory Usage: 61.6 MB, less than 100.00%
class UndergroundSystem {
private:
    unordered_map<string, unordered_map<int, int>> _in_dict;
    unordered_map<string, unordered_map<int, int>> _out_dict;
public:
    UndergroundSystem() {
        _in_dict.clear();
        _out_dict.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        _in_dict[stationName][id] = t;
    }
    
    void checkOut(int id, string stationName, int t) {
        _out_dict[stationName][id] = t;
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto & id_time1 = _in_dict[startStation];
        auto & id_time2 = _out_dict[endStation];
        // extract id appearing in _in_dict and _out_dict
        int sum = 0, count = 0;
        for (auto & p1 : id_time1) {
            auto iter = id_time2.find(p1.first);
            if (iter != id_time2.end()) {
                sum += iter->second - p1.second;
                ++count;
            }
        }
        if (count == 0) {
            return 0;
        }
        return (double)sum / (double)count;
    }
};
TEST(Q1396, Solution) {EXPECT_TRUE(run_testcases<UndergroundSystem>());}
/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

};
