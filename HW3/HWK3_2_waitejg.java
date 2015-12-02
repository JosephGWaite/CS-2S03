/*
Name:  [Joseph Waite]
MacID: [waitejg]
Student Number:  [001403712]
Description:  [powerset generator with an additional filter to remove continous strings]
*/
import java.util.*;
public class HWK3_2_waitejg{

    public static void main(String[] args) {
        /* 
        here we parse the args, 
        declare some variable, 
        and start our recursive call.

        The number of sets outputed is 2^n, where n is the number of elements
        in the input set. 
        */ 

        //Create an accumulator(acc) and a starting value(x)
        List<String> acc = new ArrayList<String>(); 
        List<String> x = new ArrayList<String>();

        //Copy String[] args to our starting List x, handles type conversion 
        Collections.addAll(x, args[0].split("")); 

        //call our workhorse function with the values we just parsed
        generate(acc, x, x);

    }
    public static void generate(List<String> acc , List<String> x, List<String> set) {
        /*
            Generate a power set. A set containing all subsets of a given set
            acc is our accumulator, what has been done so far
            x is what still needs to be done
            sum is out target value
        */

        //If we've hit the base case(a single subset)
        if (x.size()==0){
                //run this on every subset, check if it contiguous
                isContiguous(set, acc);
           // } 
        } else {
            //head is the first element of x
            String head = x.get(0);

            //We need a new list to save and pass into our recursive call
            List<String> orig = new ArrayList<String>();

            //copy the acc before we modify it
            orig.addAll(acc);

            //add the head of x to acc, 
            acc.add(head);

            generate(acc, x.subList(1,x.size()), set); //generate(acc ++ head x, tail x)
            generate(orig, x.subList(1,x.size()), set); //generate(acc, tail x)
        }
    }
    public static boolean isContiguous(List<String> set, List<String> subset){
        //takes a set, and a subset.
        //then determines if the subset exists in the set, without gaps; continiguously 

        boolean hasGap = false;

        //iterate through each element
        for (int i = 0; i<subset.size() -1; i++){
            String current = subset.get(i);
            //if the next element in the subset matches the next in the set, there is no gap
            if ((subset.get(i + 1) == set.get(set.indexOf(current) +1 ))) 
            {
                hasGap = false;  
            } else {
                //print the subset that has a gap, with formatting
                hasGap = true;
                System.out.println(subset.toString()
                                        .replace("[", "{")
                                        .replace("]", "}"));
                return hasGap; //return, good practise
            }   
        }
        return hasGap; //return, good practise
    }


}