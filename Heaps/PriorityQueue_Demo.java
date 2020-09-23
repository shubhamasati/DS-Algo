/*

Methods of PriorityQueue class:

1. peek() -- returns peek element
2. poll() -- remove and return the peek(smallest) element.
3. offer() -- inserts element in queue
4. 

*/

import java.util.*;
import java.lang.*;

class Element{
    int numerator;
    int denominator;
    double fraction;

    Element(double f, int n, int d){
        this.numerator = n;
        this.denominator = d;
        this.fraction = f;
    }

    // public float toString(){
    //     return this.fraction;
    // }
}

class MyCom implements Comparator{
    public int compare(Object obj1, Object obj2){
        Element e1 = (Element)obj1;
        Element e2 = (Element)obj2;
        if (e1.fraction < e2.fraction) return -1;
        else if (e1.fraction > e2.fraction) return 1;
        else return 0;
    }

    
}

class PriorityQueue_Demo{
    public ArrayList<Integer> smallestPrimeFraction(ArrayList<Integer> A, int B){
        PriorityQueue<Element> q =  new PriorityQueue<>(1000, new MyCom());
        int cnt = 0;
        for(int i = 0; i < A.size() - 1; i++){
            for (int j = i+1; j < A.size(); j++){
                int nume = A.get(i);
                int deno = A.get(j);
                double f = -1*(double)nume/deno;
                // System.out.printf(" %f %d %d",f, nume, deno);
                if (cnt < B){
                    q.offer(new Element(f, nume, deno));
                }
                // else{
                //     // System.out.print(f);
                //     // System.out.println(q.peek().fraction);
                // }
                else if (f > q.peek().fraction){
                    q.poll();
                    q.offer(new Element(f, nume, deno));
                    System.out.println(q.peek().fraction);
                }
                cnt++;
            }
        }
        System.out.println(q);
        ArrayList<Integer> ans = new ArrayList<>();
        ans.add(q.peek().numerator);
        ans.add(q.peek().denominator);
        return ans;
    }


    public static void main(String args[]){

       PriorityQueue_Demo pd = new PriorityQueue_Demo();

        ArrayList<Integer> a = new ArrayList<>();
        a.add(1);
        a.add(2);
        a.add(3);
        a.add(5);
        // a.add(9);
        // a.add(5);

        System.out.println(pd.smallestPrimeFraction(a, 3));
        
    }
}