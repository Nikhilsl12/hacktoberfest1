#include <iostream>
#include <vector>

using namespace std;

vector<int> findTwoElement(vector<int>& arr) {
    int n = arr.size();
    // Decrease the array elements by 1
    for (int i = 0; i < n; i++) 
        arr[i]--;
    
    for (int i = 0; i < n; i++) {
        arr[arr[i] % n] += n; // Finding the original number then adding n at that position
    }

    // Finding the missing and repeating number
    vector<int> ans(2); // To store the repeating and missing number
    for (int i = 0; i < n; i++) {
        if (arr[i] / n == 2) 
            ans[0] = i + 1; // Repeating number
        else if (arr[i] / n == 0) 
            ans[1] = i + 1; // Missing number
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = findTwoElement(arr);

    cout << "Repeating number: " << result[0] << endl;
    cout << "Missing number: " << result[1] << endl;

    return 0;
}
