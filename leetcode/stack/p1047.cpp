class Solution {
public:
  string removeDuplicates(string s) {
    stack<char> st;
    for (char ch: s) {
      if (st.empty() || ch != st.top()) {
        st.push(ch);
        continue;
      }

      st.pop();
    }

    string rem = "";
    while (!st.empty()) {
      rem += st.top();
      st.pop();
    }
    
    reverse(rem.begin(), rem.end());
    return rem;
  }
};
