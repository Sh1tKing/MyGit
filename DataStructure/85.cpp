#include<iostream>
#include<vector>
#pragma warning(disable:4996)
using namespace std; 
int removeDuplicates(vector<int>& nums) {
    int times = nums.size(),s=nums[1];
    if
    vector<int> bag;
    bag.push_back(nums[0]);
    for (int i = 1; i < times; i++) {
        if (nums[i] != s) {
            bag.push_back(nums[i]);
            s = nums[i];
        }
    }
    int k = bag.size();
    nums = bag;
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    } 
    cout << endl;
    return k;
}
int main(){
    vector<int> n = { 1 ,2};
    cout<<removeDuplicates(n);
}