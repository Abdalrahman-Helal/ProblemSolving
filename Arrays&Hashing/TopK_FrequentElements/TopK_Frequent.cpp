// URL : https://leetcode.com/problems/top-k-frequent-elements/description/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;

        for (int i : nums) {
            if (umap.find(i) != umap.end()) {
                umap.at(i) += 1;
            } else {
                umap.insert({i, 1});
            }
        }

        vector<pair<int,int>> arr;
        vector<int> result(k);

        for (auto i : umap) {
            arr.push_back(i);
        }

        sort(arr.begin(), arr.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        return a.second > b.second; // Descending order
        });

        for (int j = 0; j < k; j++) {
            result[j]=arr[j].first;
        }
        
        return result;
    }
};
