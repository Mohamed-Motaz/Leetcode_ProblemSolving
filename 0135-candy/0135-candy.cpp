class Solution {
public:
    
    //make sure every increasing rating from the right is >
    //then do the same for the left
    int twoWay(vector<int>& ratings){
        vector<int> sol(ratings.size(), 1);
        int res = 0;
        for (int i = 1; i < ratings.size(); i++){
            if (ratings[i] > ratings[i - 1])
                sol[i] = sol[i - 1] + 1;
        }
        res = sol.back();
        for (int i = ratings.size() - 2; i >= 0; i--){
            if (ratings[i] > ratings[i + 1])
                sol[i] = max(sol[i], sol[i + 1] + 1); 
            //if I am smaller than the right path, need to maximize
            //1 2 3 4 5 3 2 1 
            //1 2 3 4 5 1 1 1
            //        5 3 2 1
            res += sol[i];
        }
        return res;
    }
    
   
    
    int candy(vector<int>& ratings) {
        //return twoWay(ratings);
        return peaksAndValleys(ratings);
    }
    
    int peaksAndValleys(vector<int>& ratings){
        const int n = ratings.size();
        int candy = n;
        int i = 1;
        
        while (i < n){
            //equal, so just start over from 1
            while (i < n && ratings[i] == ratings[i - 1]){
                i++;
            }
            
            //inc slope
            int peak = 0;
            int ctr1 = 0;
            while (i < n && ratings[i] > ratings[i - 1]){
                i++;
                peak++;
                candy += peak;
                ctr1++;
            }
            
            //dec slope
            int valley = 0;
            int ctr2 = 0;
            while (i < n && ratings[i] < ratings[i - 1]){
                i++;
                valley++;
                candy += valley;
                ctr2++;
            }
            //shift by 1 for dec
            candy -= min(ctr1, ctr2);
        }
        
        
        return candy;
    }
};

//3 2 1 3      5 0 1
//3 2 1 3.     3 1 2


//1 2 3 4 5 4 3 2 1 
//1 2 3 4 5 1 1 1 1
//        5 4 3 2 1

