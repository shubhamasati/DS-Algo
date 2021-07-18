#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

int main() {
    
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    int start = 0; 
    int end = n;

    while (start < end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target) {
            cout << "Found the element at: " << mid + 1<< " position" << endl;
            return 1;
        } else if (target < arr[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    cout << "Element not found";
    return 0;
}