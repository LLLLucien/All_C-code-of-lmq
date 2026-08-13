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
class Product;
// 品牌
class Brand
{
  public:
    int id;
    string name;
    vector<Product> products; // 品牌拥有多个产品（组合）
                              // public:
    Brand(int id, string name) : id(id), name(name)
    {
    }
    ~Brand()
    {
        cout << "品牌析构" << endl;
    }
    void addProduct(Product *product)
    {
        products.push_back(*product);
    }
    void show()
    {
        cout << "品牌信息：" << endl;
        cout << "id: " << id << endl;
        cout << "name: " << name << endl;
    }
};
// 商品
class Product
{
  public:
    int id;
    string name;
    double price;
    Brand *brand; // 商品指向一个品牌，但品牌不指向商品
  public:
    Product(int id, string name, double price, Brand *brand)
        : id(id), name(name), price(price), brand(brand)
    {
    }
    ~Product()
    {
        cout << "商品析构" << endl;
    }
    void show()
    {
        cout << "商品信息：" << endl;
        cout << "id: " << id << endl;
        cout << "name: " << name << endl;
        cout << "price: " << price << endl;
        cout << "brand: " << brand->name << endl;
    }
};

// 客户地址
class Address
{
  private:
    string province;
    string city;
    string district;
    string street;
};
// 订单项
class Item
{

  public:
    int id;
    int quantity;
    Product product; // 订单项包含一个商品（组合）
    double price;    // 成交单价
  public:
    Item(int id, int quantity, Product product, double price)
        : id(id), quantity(quantity), product(product), price(price)
    {
    }
    ~Item()
    {
        cout << "订单项析构" << endl;
    }
};
// 订单
class Order
{
  public:
    int id;
    string order_time;
    vector<Item> ItemList;

    Order(int id, string order_time) : id(id), order_time(order_time)
    {
    }
    ~Order()
    {
        cout << "订单析构" << endl;
    }
    void addItem(int id, int quantity, Product product, double price)
    {
        ItemList.emplace_back(id, quantity, product, price);
    }
    void addItem(Item item)
    {
        ItemList.push_back(item);
    }
    void show()
    {

        cout << "订单信息：" << endl;
        cout << "id: " << id << endl;
        cout << "order_time: " << order_time << endl;
        for (auto &item : ItemList)
        {
            cout << "Item: " << endl;
            cout << "id: " << item.id << endl;
            cout << "quantity: " << item.quantity << endl;
            cout << "product: " << item.product.name << endl;
            cout << "price: " << item.price << endl;
        }
    }
};
// 客户
class Customer
{
  private:
    int id;
    string name;
    Address address;      // 客户拥有地址（组合）
    vector<Order> orders; // 客户拥有多个订单（组合）
};
int main()
{
    Brand brand(1, "Apple");
    Product product(1, "iPhone 13", 10000, &brand);
    Product product2(1, "iPhone 13 Pro", 10000, &brand);
    product.show();
    brand.name = "Huawei";
    product.show();

    Order order(1, "2025-06-01 12:00:00");
    order.addItem(1, 1, product, 500);
    order.addItem(Item(2, 1, product2, 999));

    order.show();
    return 0;
}