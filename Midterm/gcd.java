public class gcd{
	public static void main(String[] args){
		System.out.println(gcd(1276,216));
	}
	public static int gcd(int p, int q){
		if (q==0) {
			return 0;
		} else {
			return gcd(q, p%q);
		}
	}
}
