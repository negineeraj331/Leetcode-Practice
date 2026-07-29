class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;

        for (const std::string& str : strs) {
            std::string key = str;
            std::sort(key.begin(), key.end());
            anagramMap[key].push_back(str);
        }

        std::vector<std::vector<std::string>> result;
        result.reserve(anagramMap.size());

        for (auto& pair : anagramMap) {
            result.push_back(std::move(pair.second));
        }

        return result;
    }
};