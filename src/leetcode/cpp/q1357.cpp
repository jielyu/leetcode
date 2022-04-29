/*
#面试刷题# 第0060期
#Leetcode# Q1357 每n个订单应用折扣
难度：中
一家超市有销售，每n位顾客都会有折扣。
超级市场中有一些产品，第i个产品的ID为产品[i]，而该产品的每单位价格为prices[i]。
该系统将计算客户数量，当第n位客户到达时，他/她将在账单上享有折扣。 
（即，如果费用为x，则新费用为x-（discount* x）/ 100）。
然后，系统将再次开始计算客户。
顾客订购一定数量的每种产品，其中product [i]是顾客订购的第i个产品的id，
而amount [i]是顾客订购该产品的单位数。

实现 Cashier 类：
Cashier（int n，int discount，int [] products，int [] prices）用n，折扣，产品及其价格初始化对象。
double getBill（int [] product，int [] amount）返回票据的价值，
并在需要时应用折扣。实际值的10 ^ -5以内的答案将被认为是正确的。
约束条件：
(a) 1 <= n <= 10^4
(b) 0 <= discount <= 100
(c) 1 <= products.length <= 200
(d) 1 <= products[i] <= 200
(e) products无重复元素.
(f) prices.length == products.length
(g) 1 <= prices[i] <= 1000
(h) 1 <= product.length <= products.length
(i) product[i] exists in products.
(j) amount.length == product.length
(k) 1 <= amount[i] <= 1000
(l) 最多调用1000次 getBill函数.
(m) 精度在 10^-5以内的结果都正确

例1:
Input
["Cashier","getBill","getBill","getBill","getBill","getBill","getBill","getBill"]
[[3,50,[1,2,3,4,5,6,7],[100,200,300,400,300,200,100]],[[1,2],[1,2]],[[3,7],[10,10]],[[1,2,3,4,5,6,7],[1,1,1,1,1,1,1]],[[4],[10]],[[7,3],[10,10]],[[7,5,3,1,6,4,2],[10,10,10,9,9,9,7]],[[2,3,5],[5,3,2]]]
Output
[null,500.0,4000.0,800.0,4000.0,4000.0,7350.0,2500.0]
Explanation
Cashier cashier = new Cashier(3,50,[1,2,3,4,5,6,7],[100,200,300,400,300,200,100]);
cashier.getBill([1,2],[1,2]);                        // return 500.0, bill = 1 * 100 + 2 * 200 = 500.
cashier.getBill([3,7],[10,10]);                      // return 4000.0
cashier.getBill([1,2,3,4,5,6,7],[1,1,1,1,1,1,1]);    // return 800.0, The bill was 1600.0 but as this is the third customer, he has a discount of 50% which means his bill is only 1600 - 1600 * (50 / 100) = 800.
cashier.getBill([4],[10]);                           // return 4000.0
cashier.getBill([7,3],[10,10]);                      // return 4000.0
cashier.getBill([7,5,3,1,6,4,2],[10,10,10,9,9,9,7]); // return 7350.0, Bill was 14700.0 but as the system counted three more customers, he will have a 50% discount and the bill becomes 7350.0
cashier.getBill([2,3,5],[5,3,2]);                    // return 2500.0
*/
#include "leetcode.h"

namespace q1357{

template<typename T>
bool run_testcases() {
    int n = 3, discount = 50;
    vector<int> products{1,2,3,4,5,6,7}, prices{100,200,300,400,300,200,100};
    T slt(n, discount, products, prices);
    // place testcases below
    {
        vector<int> prod{1,2}, pri{1,2};
        CHECK_RET(std::abs(500 - slt.getBill(prod, pri)) < 1e-5);
    }

    {
        vector<int> prod{3,7}, pri{10,10};
        CHECK_RET(std::abs(4000 - slt.getBill(prod, pri)) < 1e-5);
    }

    {
        vector<int> prod{1,2,3,4,5,6,7}, pri{1,1,1,1,1,1,1};
        CHECK_RET(std::abs(800 - slt.getBill(prod, pri)) < 1e-5);
    }

    {
        vector<int> prod{4}, pri{10};
        CHECK_RET(std::abs(4000 - slt.getBill(prod, pri)) < 1e-5);
    }

    {
        vector<int> prod{7,3}, pri{10,10};
        CHECK_RET(std::abs(4000 - slt.getBill(prod, pri)) < 1e-5);
    }

    {
        vector<int> prod{7,5,3,1,6,4,2}, pri{10,10,10,9,9,9,7};
        CHECK_RET(std::abs(7350 - slt.getBill(prod, pri)) < 1e-5);
    }

    {
        vector<int> prod{2,3,5}, pri{5,3,2};
        CHECK_RET(std::abs(2500 - slt.getBill(prod, pri)) < 1e-5);
    }

    // succ
    return true;
}

class Cashier {
private:
    unordered_map<int, int> _dict;
    const int _d, _n;
    int _counter;
public:
    // Runtime: 172 ms, faster than 87.14%
    // Memory Usage: 33.4 MB, less than 100.00%
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices): _d(discount), _n(n) {
        this->_counter = 0;
        // create mapping from product id to price
        int num = products.size();
        for (int i = 0; i < num; ++i) {
            this->_dict[products[i]] = prices[i];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        // calculate the total price
        double total = 0;
        int len = product.size();
        for (int i = 0; i < len; ++i) {
            // product[i] exists in products
            total += _dict[product[i]] * amount[i];
        }
        // counter current customer
        ++_counter;
        if (_counter % _n == 0) {
            total = (100 - _d) * total / 100;
        }
        return total;
    }
};
TEST(Q1357, Solution) {EXPECT_TRUE(q1357::run_testcases<q1357::Cashier>());}
/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
};
