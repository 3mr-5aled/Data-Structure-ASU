#include <iostream>
#include <set>
#include <string>
#include <unordered_map>

using namespace std;

namespace
{
    struct ProductRankComparator
    {
        bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs) const
        {
            if (lhs.first != rhs.first)
                return lhs.first > rhs.first;
            return lhs.second < rhs.second;
        }
    };

    unordered_map<int, int> sales_count;
    set<pair<int, int>, ProductRankComparator> ranking;
}

void add_transaction(string customer_name, int product_id)
{
    (void)customer_name;

    auto found = sales_count.find(product_id);
    int current_count = 0;
    if (found != sales_count.end())
    {
        current_count = found->second;
        ranking.erase({current_count, product_id});
    }

    ++current_count;
    sales_count[product_id] = current_count;
    ranking.insert({current_count, product_id});
}

int get_product_sales_count(int product_id)
{
    auto found = sales_count.find(product_id);
    if (found == sales_count.end())
        return 0;
    return found->second;
}

void print_top_products_ids()
{
    int printed = 0;
    for (auto it = ranking.begin(); it != ranking.end() && printed < 5; ++it, ++printed)
    {
        if (printed > 0)
            cout << ' ';
        cout << it->second;
    }
    cout << endl;
}
