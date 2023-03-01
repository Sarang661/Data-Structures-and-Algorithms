class Solution {
    
private:
    
    void merge(vector<int>&nums, int low, int mid, int high){
        
        int len1 = mid-low+1;
        int len2 = high-mid;
        
        int nums1[len1];
        int nums2[len2];
        
        for(int index= 0; index < len1; index++){
            
            nums1[index] = nums[index+low];
        }
        
          for(int index= 0; index < len2; index++){
            
            nums2[index] = nums[index+mid+1];
        }
        
        int start1 = 0;
        int start2 = 0;
        int index = low;
        
        while(start1 < len1 && start2 < len2){
            
            if(nums1[start1]<=nums2[start2]){
                nums[index] = nums1[start1];
                index++;
                start1++;
            }
            else{
                nums[index] = nums2[start2]; 
                index++;
                start2++;
            }
                
        }
        
        while(start1 < len1){
            
            nums[index]  = nums1[start1];
            start1++;
            index++;
        }
        
        while(start2 < len2){
            
            nums[index]  = nums2[start2];
            start2++;
            index++;
        }
    }
    
    
    void mergeSort(vector<int>&nums, int low, int high){
        
        if(low < high){
            
            int mid = low + (high-low)/2;
            
            mergeSort(nums, low, mid);
            mergeSort(nums, mid+1, high);
            
            merge(nums, low, mid, high);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        
        int low = 0; 
        int high = nums.size() - 1;
        
        mergeSort(nums, low, high);
        
        return nums;
    }
};