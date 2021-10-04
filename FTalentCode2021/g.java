import java.math.BigInteger;
import java.util.Scanner;

public class g {
    static public void main(String argv[]) {
        Scanner sc = new Scanner(System.in);
        BigInteger prod = BigInteger.ONE;
        int n = sc.nextInt();
        prod = prod.multiply(BigInteger.valueOf(299792458));
        prod = prod.multiply(BigInteger.valueOf(31557600));
        prod = prod.multiply(BigInteger.valueOf(n));
        prod = prod.divide(BigInteger.valueOf(1000));
        System.out.println(prod);
    }
}
