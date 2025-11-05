/**
 Link to the question: https://leetcode.com/problems/remove-element/submissions/1821940974/?envType=list&envId=ofbiscdi
 What I learned:
 This problem uses the two-pointer technique. It is similar to how we moved elements in sorted_vector.c when shifting array items. 
 The problem requires in-place changes, so we cannot use extra space. This is like how we worked with arrays in the vector implementation. 
 Moving elements to the front is similar to the shift operation in the vector remove function, but here we only copy the elements that do not match.
 Most other solutions use the same two-pointer approach. Some solutions swap elements instead of overwriting, but that is slower. 
 My solution follows the standard method. It takes O(n) time and O(1) space. This is optimal because the array is only traversed once.
 */



int removeElement(int* nums, int numsSize, int val) {
    int k = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }
    
    return k;
}