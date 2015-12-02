/*
Name:  [Joseph Waite]
MacID: [waitejg]
Student Number:  [001403712]
Description:  [basic recursive binominal function]
*/

public class HWK3_1_waitejg{

	public static void main(String[] args){

		int n = Integer.parseInt(args[0]); //get n from args
		int k = Integer.parseInt(args[1]); //get k from args

		//call the binom function and print the results
		System.out.println(binom(n, k));
	}

	public static int binom(int n, int k){

		if (n==k || k ==0){//from piecewise function
			return 1;

		}else{

			return binom(n-1, k-1) + binom(n-1, k); //recursive calls
		}
	}
}
