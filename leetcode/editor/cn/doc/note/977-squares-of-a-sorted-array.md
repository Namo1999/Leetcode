```c++
 int k = nums.size()-1;
      vector<int> result(nums.size(),0);
      for(int i = 0,j = nums.size()-1;i <=j;){   // i <=j 是因为result里面初始都是0,当i=j时，把那个数 放到第一个里面
        if(nums[i] * nums[i] < nums[j] * nums[j]){
          result[k--] = nums[j]*nums[j];
          j--;
        }else{
          result[k--]=nums[i]*nums[i];
          i++;
        }
      }
      return result;
```