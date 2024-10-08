#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bucketSort(vector<float> &arr) {
    int n = arr.size();
    vector<vector<float>> buckets(n);

    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i];
        buckets[bucketIndex].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    vector<float> arr = {0.42, 0.32, 0.23, 0.52, 0.73, 0.25, 0.65, 0.34};
    bucketSort(arr);

    for (float num : arr) {
        cout << num << " ";
    }
    return 0;
}
