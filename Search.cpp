#include<bits/stdc++.h>

using namespace std;

int IterativeSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == target) {
            return i;
        }
    }
    cout << "Not found target number ";
    return -1;
}

int RecursiveSearch(int i, int arr[], int n, int target) {
    if (i == n) {
        cout << "Not found target number ";
        return -1;
    }
    if (arr[i] == target) {
        return i;
    }
    return RecursiveSearch(i + 1, arr, i + 1, target);
}

int IterativeBinarySearch(int arr[], int n, int target) {
    int l = 0, r = n - 1, index = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] > target) {
            r = mid - 1;
        } else {
            index = mid;
            l = mid + 1;
        }
    }
    if (index == -1 || arr[index] != target) {
        cout << "Not found target number ";
        return -1;
    }
    return index;
}

int RecursiveBinarySearch(int low, int high, int arr[], int target) {
    if (low > high) {
        cout << "Not found target number ";
        return -1;
    }
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] > target) {
        return RecursiveBinarySearch(low, mid - 1, arr, target);
    } else {
        return RecursiveBinarySearch(mid + 1, high, arr, target);
    }
}


int main() {


}
