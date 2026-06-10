#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

const int TOP = 5;

unordered_map<int, int> productCount;

void add_transaction(string customer_name, int product_id)
{
    productCount[product_id]++;
}
int get_product_sales_count(int product_id)
{
    auto it = productCount.find(product_id);
    return (it != productCount.end()) ? it->second : 0;
    // return productCount[product_id];
}

void print_top_products_ids()
{
    priority_queue<pair<int, int>> maxHeap;
    for (auto &p : productCount)
    {
        maxHeap.push({p.second, p.first});
    }
    for (int i = 0; i < TOP && !maxHeap.empty(); i++)
    {
        cout << maxHeap.top().second << " ";
        maxHeap.pop();
    }
}

int main()
{

    add_transaction("Ahmed", 1);
    add_transaction("Ahmed", 1);
    add_transaction("Mohammed", 2);
    add_transaction("Mohammed", 1);
    add_transaction("Mohammed", 2);
    add_transaction("Ahmed", 2);
    add_transaction("Ahmed", 3);
    add_transaction("Nader", 7);
    add_transaction("Badr", 6);
    add_transaction("Badr", 5);
    add_transaction("Badr", 4);
    add_transaction("Badr", 3);
    add_transaction("Ahmed", 1);
    add_transaction("Gad", 3);
    add_transaction("Ali", 6);

    cout << "Count for Product 1: " << get_product_sales_count(1) << endl;
    print_top_products_ids();

    return 0;
}