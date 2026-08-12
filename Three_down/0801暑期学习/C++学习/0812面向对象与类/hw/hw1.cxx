// 1. 定义以下类(没有用到继承)：
// - 品牌 - id、name、vector<产品> vs;
// - 商品 - id、name、price、vector<品牌> vs;
// - 客户 -
//     地址 - 订单 -
//
// 订单项

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Brand;

// 商品：用指针关联品牌（不拥有，打破循环依赖）
class Product
{
  private:
    int id;
    string name;
    double price;
    Brand *brand; // 商品指向一个品牌，但品牌不指向商品
};

// 品牌：用值拥有产品（真正的组合关系）
class Brand
{
  private:
    int id;
    string name;
    vector<Product> products; // 品牌拥有多个产品（组合）
};

class Address
{
  private:
    string province;
    string city;
    string district;
    string street;
};

class OrderItem
{
  private:
    int id;
    int quantity;
    Product product; // 订单项包含一个商品（组合）
    double price;    // 成交单价
};

class Order
{
  private:
    int id;
    string order_time;
    vector<OrderItem> order_items; // 订单包含多个订单项（组合）
};

class Customer
{
  private:
    int id;
    string name;
    Address address;      // 客户拥有地址（组合）
    vector<Order> orders; // 客户拥有多个订单（组合）
};
