package LeetCode.String;
import java.util.ArrayList;
public class Solution {
    public int lengthOfLongestSubstring(String s) {
        ArrayList<String> list = new ArrayList<>();
        //求字符串的所有子串（不去重）
        for(int i = 0;i<s.length();i++)
            for(int j = i;j<s.length();j++)
                list.add(s.substring(i, j + 1));
            //将相同的子串删除，只保留一个
      //  for(int i=0;i<list.size();i++)
        //    for (int j = i + 1; j < list.size(); j++)
       //         if ((list.get(i)).equalsIgnoreCase(list.get(j)))
      //              list.remove(j);
        //删除剩余子串中具有重复字符的子串
        for(int i=0;i<list.size();i++)
            for(int j=0;j<(list.get(i)).length();j++)
                for(int k=j+1;k<(list.get(i)).length();k++)
                    if((list.get(i)).charAt(j) == (list.get(i)).charAt(k)) {
                        list.remove(i);
                        i--;
                    }
        int[] num = new int[list.size()];
        for(int i=0;i<list.size();i++){
            num[i] = (list.get(i)).length();
        }
        int max = 0;
        if(list.size()==1){
            max = num[0];
            return max;
        }
        else {
            for (int i = 0; i < list.size(); i++)
                if(max<num[i])
                    max=num[i];
            return max;
        }
    }
}
