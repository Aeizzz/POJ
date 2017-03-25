import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	static BigInteger dp[] = new BigInteger [300];
	public static void main(String[] args) {
		int n;
		dp[0]=BigInteger.valueOf(1);
		dp[1]=BigInteger.valueOf(1);
		dp[2]=BigInteger.valueOf(3);
		for(int i=3;i<=250;i++){
			dp[i]=dp[i-1].add(dp[i-2].multiply(BigInteger.valueOf(2)));
		}
		Scanner scanner = new Scanner(System.in);
		while(scanner.hasNext()){
			n=scanner.nextInt();
			System.out.println(dp[n]);
		}
	}
}