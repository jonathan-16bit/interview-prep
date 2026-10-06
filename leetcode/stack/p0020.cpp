class Solution {
public:
  bool isValid(string s) {
    vector<char> stack;
    unordered_map<char, char> opp = {{')', '('}, {']', '['}, {'}', '{'}};

    for (char br: s) {
      // If opening bracket, push
      if (opp.find(br) == opp.end()) {
        stack.push_back(br);
        continue;
      }

      // If empty and checking for a closing bracket, return false
      if (stack.empty())
        return false;

      // If the top of the stack doesn't have the matching opening bracket
      if (stack.back() != opp[br]) {
        return false;
      }

      // Remove one valid bracket pair
      stack.pop_back();
    }

    // If all valid pairs, stack will be empty
    if (stack.empty())
      return true;

    // When unmatched opening brackets remain
    return false;
  }
};
