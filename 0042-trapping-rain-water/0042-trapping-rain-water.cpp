class Solution {
public:
    int trap(vector<int>& height) {
        int tot = 0;
        stack<int> st;
        
        int i = 0;
        const int n = height.size();
        while (i < n){
            if (!st.empty()){
                int prv = st.top();
                if (height[i] < height[prv]){
                    st.push(i++);
                }else{
                    st.pop();
                    if (st.empty()) continue;
                    tot += max(0, (i - st.top() - 1)  * ((min(height[i], height[st.top()]) - height[prv])));
                }
            }else{
                //empty stack
                st.push(i++);
            }
        }
        return tot;
    }
};