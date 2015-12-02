public class nbits{
	public static void main(String[] args){
	//I put stuff here 
	
		gen(3);	

	}
	public static void gen(int n){
	//n=number of bits 

		int[] acc = new int[3]; 
		if (n==0){	
			System.out.println(acc);
		
		} else { 
			acc[-1]=1;
			gen(n-1);
			acc[-1]=0;
			gen(n-1); 
		}
	}
}
