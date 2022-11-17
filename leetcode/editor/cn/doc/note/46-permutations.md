## 这一题是经典的排列问题，用递归方法做的。

![图解](https://code-thinking-1253855093.file.myqcloud.com/pics/20211027181706.png)

```c++
  for(int i =0; i < nums.size(); i++){
      if(used[i] == true)
        continue ;
      used[i] = true;
      path.push_back(nums[i]);
      backtracking(nums,used);
      path.pop_back();
      used[i] = false;
    }
```
在每一层树枝中，通过for循环 让每次新的元素排列在第一个，但是后面还会用到同一层，前面用过的元素，
就好比说 当 i = 1时，used[0,0,0],然后变为[0,1,0];
path.push_back(2); 之后让backtracking(nums,[0,1,0])进入下一层递归;
下一层 递归从i = 0开始，因为used[1] =1; 所以，2不会再次进入path，这样就保证了全排列。


> 每层都是从0开始搜索而不是startIndex  
> 需要used数组记录path里都放了哪些元素了


当然 也可以这样写
```c++
    for(int i =0; i < nums.size(); i++){
      if(used[i] == false){
      used[i] = true;
      path.push_back(nums[i]);
      backtracking(nums,used);
      path.pop_back();
      used[i] = false;
      }

    }
```

