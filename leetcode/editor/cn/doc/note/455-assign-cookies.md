## 贪心算法 由局部最优可以推出全局最优

这道题目，让小饼干给小胃口吃， 
比较难想的是 怎么让 饼干的遍历和胃口的遍历一起，也可以用两个for循环来做
```c++
for(int i = 0; i < s.size(); i++){
        for(int j = count; j < g.size(); j++){
           if(g[j] <= s[i]){
             count++;
             break;
           }
        }

      }
```
但是这样逻辑比较复杂;
还可以这样写：
```c++
     for(int i = 0; i < s.size(); i++){
         if(count < g.size() && g[count] <= s[i]){
           count++;
        }

      }
```