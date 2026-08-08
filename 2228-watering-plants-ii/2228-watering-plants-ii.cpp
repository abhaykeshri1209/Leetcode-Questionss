class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
       int left = 0;
int right = plants.size() - 1;

int count = 0;

int initialCapacityA = capacityA;
int initialCapacityB = capacityB;

while (left <= right) {

    if (left == right) {
      
        if (capacityA >= capacityB) {
            if (plants[left] > capacityA)
                count++;
        } 
        else {
            if (plants[left] > capacityB)
                count++;
        }

        break;
    }

    
    if (plants[left] <= capacityA) {
        capacityA -= plants[left];
        left++;
    }
    else {
        count++;
        capacityA = initialCapacityA;
        capacityA -= plants[left];
        left++;
    }

    
    if (plants[right] <= capacityB) {
        capacityB -= plants[right];
        right--;
    }
    else {
        count++;
        capacityB = initialCapacityB;
        capacityB -= plants[right];
        right--;
    }
       
       if(left==right){
        
       }

}
return count;
    }
};