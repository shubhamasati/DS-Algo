import java.util.*;
import java.lang.*;

class AnotherCoin{
    public static void main(String args[]){
        int[] pow = new int[14];
        int ans = 0;

        int val = 47;

        for(int i = 13; i >-1; i--){
            int p = (int)Math.pow(5, i);
            int s = val/p;
            val = val - s*p;
            ans += s;
        }
        System.out.println(ans);
        
    }
}