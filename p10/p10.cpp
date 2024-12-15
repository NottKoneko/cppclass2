#include <iostream>
#include <vector>
using namespace std;

// Merge two subarrays
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void printArray(vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << endl;
}
int binarySearchIterative(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int binarySearchRecursive(vector<int>& arr, int left, int right, int target) {
    if (left > right) return -1;
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) return mid;
    if (arr[mid] < target)
        return binarySearchRecursive(arr, mid + 1, right, target);
    return binarySearchRecursive(arr, left, mid - 1, target);
}
int factorialIterative(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) result *= i;
    return result;
}

int factorialRecursive(int n) {
    if (n <= 1) return 1;
    return n * factorialRecursive(n - 1);
}
int triangleIterative(int n) {
    int result = 0;
    for (int i = 1; i <= n; i++) result += i;
    return result;
}

int triangleRecursive(int n) {
    if (n == 0) return 0;
    return n + triangleRecursive(n - 1);
}
void compoundInterestRecursive(double monthlyDeposit, double interest, int years, int year, double total, double payments, double interestEarned) {
    if (year > years) {
        cout << "End of Year: " << year - 1 << " | Total Savings: " << total << " | Payments: " << payments << " | Interest Earned: " << interestEarned << endl;
        return;
    }
    total += monthlyDeposit * 12;
    double yearInterest = total * (interest / 100);
    payments += monthlyDeposit * 12;
    total += yearInterest;
    interestEarned += yearInterest;

    cout << "Year: " << year << " | Total Savings: " << total << " | Payments: " << payments << " | Interest Earned: " << interestEarned << endl;

    compoundInterestRecursive(monthlyDeposit, interest, years, year + 1, total, payments, interestEarned);
}
int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int target = 9;

    // Merge Sort
    cout << "Original Array: ";
    printArray(arr);
    mergeSort(arr, 0, arr.size() - 1);
    cout << "Sorted Array: ";
    printArray(arr);

    // Binary Search
    cout << "Binary Search (Iterative): " << binarySearchIterative(arr, target) << endl;
    cout << "Binary Search (Recursive): " << binarySearchRecursive(arr, 0, arr.size() - 1, target) << endl;

    // Factorial
    int num = 5;
    cout << "Factorial Iterative: " << factorialIterative(num) << endl;
    cout << "Factorial Recursive: " << factorialRecursive(num) << endl;

    // Triangle
    int n = 5;
    cout << "Triangle Iterative: " << triangleIterative(n) << endl;
    cout << "Triangle Recursive: " << triangleRecursive(n) << endl;

    // Compound Interest
    double monthlyDeposit = 200.00, interest = 5;
    int years = 5;
    cout << "\nCompound Interest (Recursive):\n";
    compoundInterestRecursive(monthlyDeposit, interest, years, 1, 0.0, 0.0, 0.0);

    return 0;
}



/*


Original Array: 38 27 43 3 9 82 10 
Sorted Array: 3 9 10 27 38 43 82 
Binary Search (Iterative): 1
Binary Search (Recursive): 1
Factorial Iterative: 120
Factorial Recursive: 120
Triangle Iterative: 15
Triangle Recursive: 15

Compound Interest (Recursive):
Year: 1 | Total Savings: 2520 | Payments: 2400 | Interest Earned: 120
Year: 2 | Total Savings: 5166 | Payments: 4800 | Interest Earned: 366
Year: 3 | Total Savings: 7944.3 | Payments: 7200 | Interest Earned: 744.3
Year: 4 | Total Savings: 10861.5 | Payments: 9600 | Interest Earned: 1261.51
Year: 5 | Total Savings: 13924.6 | Payments: 12000 | Interest Earned: 1924.59
End of Year: 5 | Total Savings: 13924.6 | Payments: 12000 | Interest Earned: 1924.59


*/