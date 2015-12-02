/*
Name:  [Joseph Waite]
MacID: [waitejg]
Student Number:  [001403712]
Description:  [powerset generator with an additional filter to find sum. ]
*/
import java.util.*;
public class HWK3_3_waitejg{

    public static void main(String[] args) {
        /* 
        here we parse the args, 
        declare some variable, 
        and start our recursive call
        */ 

        //Create an accumulator(acc) and a starting value(x)
        List<String> acc = new ArrayList<String>(); 
        List<String> x = new ArrayList<String>();

        //last element in args is the target sum
        int sum = Integer.parseInt(args[args.length -1]);

        //Copy String[] args to our starting List x, handles type conversion 
        Collections.addAll(x, args); 

        //Remove the last element in args, which is the target sum 
        x.remove(x.size() - 1);

        //call our workhorse function with the values we just parsed
        generate(acc, x, sum);

    }
    public static void generate(List<String> acc , List<String> x, int sum) {
        /*
            acc is our accumulator, what has been done so far
            x is what still needs to be done
            sum is out target value
        */

        //If we've hit the base case(a single subset)
        if (x.size()==0){
            //then sum every value in the set. print the set if it equal our target
            if (acc.stream().mapToInt(Integer::valueOf).sum() == sum){
                System.out.println(acc.toString()
                                        .replace("[", "{")
                                        .replace("]", "}"));
            } 
        } else {
            //head is the first element of x
            String head = x.get(0);

            //We need a new list to save and pass into our recursive call
            List<String> orig = new ArrayList<String>();

            //copy the acc before we modify it
            orig.addAll(acc);

            //add the head of x to acc, 
            acc.add(head);

            generate(acc, x.subList(1,x.size()), sum); //generate(acc ++ head x, tail x)
            generate(orig, x.subList(1,x.size()), sum); //generate(acc, tail x)
        }
    }

}