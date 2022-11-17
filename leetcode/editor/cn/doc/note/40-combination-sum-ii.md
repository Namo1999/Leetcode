## 解体思路
难点在于 candidates里面有重复的数字，每个只让用一次，怎么去重就是一个难题。

根据代码随想录的解题思路。
方法一是：通过构造一个used的数组 来标定每一个元素的使用情况

在同一个树枝内，是可以使用重复的元素，但是同一个树层内不可以使用重复的元素。

这个方法相对比较麻烦，建议用第二种去重

```C++
for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            // 要对同一树层使用过的元素进行跳过
            if (i > startIndex && candidates[i] == candidates[i - 1]) {
                continue;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i + 1); // 和39.组合总和的区别1，这里是i+1，每个数字在每个组合中只能使用一次
            sum -= candidates[i];
            path.pop_back();
        }

```

在同一个树层上面，因为数组经过了排序，相同元素必定是相邻的
就比如[1,1,2],加入现在startIndex = 0; i =1;那么就会跳过i = 1的时候，这样就能够去掉重复的元素


在同一个树枝上面，因为每次进行递归的时候，都已经去除过已经使用过的元素了
，所以只要避免现在遍历的元素和后面元素重复就行，即该树枝的下一层，去除重复的就可以了。