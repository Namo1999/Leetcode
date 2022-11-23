# 前言
做好长期做题的准备，要学会做题而不是背题  
# 分析
这一题有一个很明确的提醒
> 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍  
 
也就是说，每两个数之和不同
利用哈希表，一次遍历就可以完成
需要注意的是返回的是vector<int>,返回的内容是两个索引值。
还有就是C++的unordered_map<int,int>的使用事项。

# 代码
1. 2022年11月17日
```c++
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int,int> mymap;
      for(int i = 0; i < nums.size(); i++){
        auto item = mymap.find(target-nums[i]);
        if(item != mymap.end()){
          return {item->second,i};
        }
        mymap.insert(pair<int,int>(nums[i],i));
      }
      return {};

```
**注意：** `mymap.insert(pair<int,int>(nums[i],i))`
里面用的pair<int,int>

