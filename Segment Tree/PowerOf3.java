import java.util.*;
import java.lang.*;
public class PowerOf3{
    char[] s;
    int[] tree;
    HashMap<Integer, Integer> d;
    public void calculate(){
        d.put(0, 1);
        for(int i = 1; i < 10; i++){
            // System.out.print(i);
            int temp = (d.get(i-1) << 1);
            this.d.put(i, temp);
        }   
    }
    public void build(int idx, int start, int end){
        if( start == end ){
            this.tree[idx] = Integer.parseInt(String.valueOf(this.s[start]));
        else{
            int m = (start + end)/2;
            
            int lc = idx*2 + 1;
            int rc = idx*2 + 2;
            
            build(lc, start, m);
            build(rc, m+1, end);
            
            this.tree[idx] = (this.tree[lc] * this.d.get(end - m)) + this.tree[rc];
        }
        
    }
    
    
    public int query(int idx, int start, int end, int L, int R){
        
        //No overlap
        if( end < L || start > R) return 0;
        
        //Complete overlap
        else if( L <= start && end <= R) return this.tree[idx];
        
        int m = (start + end)/2;
        
        int lc = idx*2 + 1;
        int rc = idx*2 + 2; 
        
        
        int l = query(lc, start, m, L, R);
        int r = query(rc, m+1, end, L, R);
        
        if (R < m) return l;
        
        int steps = Math.min(R, end) - m;
    
        return l * this.d.get(steps) + r;
        
    }
    
    public int update(int idx, int start, int end, int i){
        if( start == end ){
            System.out.println("here");
            System.out.println(idx);
            System.out.println(this.tree[idx]);
            if(this.tree[idx] == 0){
                // System.out.println("here");
                this.tree[idx] = 1;
            }
            return -1;
        }
        else{
            int m = (start+end)/2;
            int lc = idx*2 + 1;
            int rc = idx*2 + 2;
            
            if (start <= i && i <= end) 
                update(lc, start, m, i);
            else 
                update(rc, m+1, end, i);
            
            // if((this.tree[lc] << (end - m)) + this.tree[rc] > 1000000007) 
            //     this.tree[idx] = (this.tree[lc] << (end - m)) + this.tree[rc] % 1000000007;
            // else 
            this.tree[idx] = (this.tree[lc] * d.get(end - m)) + this.tree[rc];
            return -1;
        }
    }
    public ArrayList<Integer> solve(String A, ArrayList<ArrayList<Integer>> B) {
        
        this.s = A.toCharArray();
        int N = s.length - 1;
        this.d = new HashMap<>();
        this.tree = new int[4*N];
        Arrays.fill(tree, -1);
        calculate();
        build(0, 0, N);
        
        // for(int i: tree) System.out.println(i);
        

        System.out.println(update(0, 0, N, 1));
        // for(int i: tree) System.out.println(i);
        System.out.println(query(0, 0, N, 0, 4));
        System.out.println(update(0, 0, N, 1));
        // for(int i: tree) System.out.println(i);
        System.out.println(query(0, 0, N, 0, 3));



        ArrayList<Integer> ans = new ArrayList<>();
    
        // for( ArrayList<Integer> a: B){
        //     int c = a.get(0);
        //     int l = a.get(1);
        //     int r = a.get(2);
            
        //     if(c == 0){
        //         ans.add(query(0, 0, N, l-1, r-1) % 3);
        //     } else{
        //         ans.add(update(0, 0, N, l-1));
        //     }
            
        // }
        return ans;

    }

    public static void main(String[] args){
            String s = "10010";
            ArrayList<Integer> t = new ArrayList<>();
            ArrayList<ArrayList<Integer>> A = new ArrayList<>();

            PowerOf3 p = new PowerOf3();
            t.add(0);
            t.add(1);
            t.add(5);
            A.add(t);
            // t.clear();
            
            ArrayList<Integer> t1 = new ArrayList<>();
            t1.add(0);
            t1.add(1);
            t1.add(4);
            A.add(t1);
            // t.clear();
            
            System.out.println(p.solve(s, A));
        }
}

