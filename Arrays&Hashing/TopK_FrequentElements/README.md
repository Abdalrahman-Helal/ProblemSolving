# Top K Frequent Elements - C++ Solution

## Overview

This C++ program finds the **k most frequent elements** in a given integer array. It uses an `unordered_map` to count frequencies, a `vector<pair<int,int>>` to store number-frequency pairs, and then sorts the vector to find the top `k` elements.

---

## How It Works

1. **Count Frequencies using `unordered_map`**

```cpp
unordered_map<int, int> umap;
for (int i : nums) {
    if (umap.find(i) != umap.end()) {
        umap.at(i) += 1;
    } else {
        umap.insert({i, 1});
    }
}
```

* Loop through the input array `nums`.
* If a number already exists in the map, increment its frequency.
* Otherwise, insert it with frequency 1.

> This step has **O(n)** time complexity.

---

2. **Move Map Data to Vector of Pairs**

```cpp
vector<pair<int,int>> arr;
for (auto i : umap) {
    arr.push_back(i);
}
```

* `arr` stores `{number, frequency}` pairs.
* This allows sorting by frequency.

---

3. **Sort Vector by Frequency**

```cpp
sort(arr.begin(), arr.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
    return a.second > b.second; // Descending order
});
```

### Detailed Explanation of this line:

* **`sort(arr.begin(), arr.end(), ...)`**
  Uses the standard C++ `sort` algorithm to sort the vector from beginning to end.

* **Lambda function as comparator:**

  ```cpp
  [](const pair<int,int>& a, const pair<int,int>& b) {
      return a.second > b.second;
  }
  ```

  * `[]` → Lambda capture list (empty here, we don’t capture external variables)
  * `(const pair<int,int>& a, const pair<int,int>& b)` → Parameters: two pairs from the vector, passed **by reference** to avoid copying and marked `const` to prevent modification.
  * `{ return a.second > b.second; }` → Sorting condition:

    * Returns `true` if `a` should come **before** `b`.
    * `a.second` is the frequency of the first pair, `b.second` is frequency of the second.
    * So `a.second > b.second` → sorts in **descending order by frequency**.

> Using a lambda allows **custom sorting rules**, which is essential because the default `sort` only sorts by the first element (`pair.first`).

---

4. **Pick Top K Frequent Elements**

```cpp
vector<int> result(k);
for (int j = 0; j < k; j++) {
    result[j] = arr[j].first;
}
```

* After sorting, the first `k` elements in `arr` are the top `k` frequent numbers.
* Extract only the number (`first` of each pair) and store in `result`.

---

## Time Complexity

* Counting frequencies: **O(n)**
* Moving map to vector: **O(m)** (m = number of unique elements)
* Sorting vector: **O(m log m)**
* Extracting top k: **O(k)**

✅ Total: **O(n + m log m)**

---

## Space Complexity

* `unordered_map`: O(m)
* `vector<pair<int,int>> arr`: O(m)
* `result`: O(k)

✅ Total: **O(m + k)**

---

## Example

Input:

```cpp
nums = {1,1,1,2,2,3}, k = 2
```

Processing:

1. Count frequencies → `{1:3, 2:2, 3:1}`
2. Vector of pairs → `{(1,3),(2,2),(3,1)}`
3. Sort by frequency → `{(1,3),(2,2),(3,1)}`
4. Top 2 → `[1,2]`

Output:

```cpp
[1,2]
```

---

This README explains the **whole flow** and the **lambda sorting line in detail**, so anyone reading your repo can understand both the logic and the C++ syntax.
