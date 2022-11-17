## 这一题关键是去重

题目说了 会有重复的元素。先排序  
` sort(nums.begin(), nums.end());`  
然后在利用used数组进行去重
![图片](https://img-blog.csdnimg.cn/20201124201331223.png)  
```c++
 for(int i = 0; i < nums.size(); i++){
      // used[i - 1] == true，说明同一树枝nums[i - 1]使用过
      // used[i - 1] == false，说明同一树层nums[i - 1]使用过
      // 如果同一树层nums[i - 1]使用过则直接跳过
      if(i > 0 && nums[i] == nums[i-1] && used[i-1] == false){  //这个主要是用于同一层 排除重复
        continue;
      }
      if(used[i] == false){ // 排除同一个树枝的情况下，[1,1,2] 比如第一个1 已经进入path，used[0] = ture; 这个1 就不会重复进入path了
        used[i] = true;
        path.push_back(nums[i]);
        backtracking(nums,used);
        path.pop_back();
        used[i] = false;
      }
    }
```
for循环的第一个if 是用来排除同一层选取相等的元素的可能  
第二层for循环是用来，防止已经选取过的元素重新进入path