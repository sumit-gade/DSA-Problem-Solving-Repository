#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class StockSpanner {
public:
    // Stack to store pairs of (price, span)
    stack<pair<int, int>> st;

    // Constructor
    StockSpanner() {}

    // Function to calculate the next span
    int next(int price) {
        int span = 1;

        // Calculate the span for the current price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        // Push the current price and its span onto the stack
        st.push({price, span});

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main() {
    // Create an instance of StockSpanner
    StockSpanner* stockSpanner = new StockSpanner();

    // Example stock prices
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    vector<int> spans;

    // Calculate the span for each price
    for (int price : prices) {
        spans.push_back(stockSpanner->next(price));
    }

    // Output the results
    cout << "Stock prices: ";
    for (int price : prices) {
        cout << price << " ";
    }
    cout << endl;

    cout << "Spans: ";
    for (int span : spans) {
        cout << span << " ";
    }
    cout << endl;

    // Clean up
    delete stockSpanner;

    return 0;
}
