class Solution {
public:
    
    int nos(int num, int stepsCount = 0) {
        if(num <= 0) return stepsCount;
        if(num%2 == 0) {
            num/=2;
        }
        else {
            num-=1;
        }
            stepsCount++;
            return nos(num,stepsCount);
        
    }
    
    int numberOfSteps(int num) {
        int steps = nos(num);
        
        return steps;
    }
};