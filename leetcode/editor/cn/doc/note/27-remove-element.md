```c++
  // 暴力求解
//      int n = nums.size();
//      for (int i = 0; i < n; i ++){
//        if(nums[i] == val){
//          for(int j = i + 1; j < n; j++){
//            nums[j-1] = nums[j];
//          }
//          i--; // 因为下标i以后的数值都向前移动一位，所以i也向前移动一位
//          n--; // 数组大小减1
//        }
//      }
//      return n;


      // 双指针法
//      int slowIndex = 0;
//      for(int fastIndex = 0; fastIndex < nums.size();fastIndex++){
//        if(val != nums[fastIndex]){
//          nums[slowIndex++] = nums[fastIndex]; // slowIndex++ 是先取变量;在加1
//        }
//      }
//      return slowIndex;

      // 相向双指针法 基于元素顺序可以改变的题目描述，改变元素相对位置，确保了移动最少元素
      int leftIndex = 0;
      int rightIndex = nums.size()-1;
      while(leftIndex <= rightIndex){
        // 找到左边等于val的元素
        while(leftIndex <= rightIndex && nums[leftIndex] != val){
          ++leftIndex;
        }
        // 找到右边等于val的元素
        while (leftIndex <= rightIndex && nums[rightIndex] == val){
          --rightIndex;
        }
        if(leftIndex < rightIndex){
          nums[leftIndex++] = nums[rightIndex--];
        }
      }
      return leftIndex;

```