import java.math.BigInteger;
import java.util.Scanner;

public class c {
    static public void main(String argv[]) {
        Scanner sc = new Scanner(System.in);
        BigInteger prod = BigInteger.ONE;
        BigInteger ans = BigInteger.ZERO;
        int x = sc.nextInt();
        int n = sc.nextInt();
        ans = ans.add(BigInteger.valueOf(x));
        for(int i = 1; i <= n; i++) {
            prod = prod.multiply(BigInteger.valueOf(i));
            BigInteger nxt = prod.divide(BigInteger.valueOf(x));
            ans = ans.add(nxt);
        }
        System.out.println(ans);
    }
}