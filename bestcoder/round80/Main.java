import java.math.*;
import java.math.BigInteger;
import java.util.Scanner;
public class Main {
    public static void main(String args[]) {
        Scanner cin = new Scanner(System.in);
        BigInteger p, q;
        int T = cin.nextInt();
        while(T-- > 0) {
            q = cin.nextBigInteger();
            p = cin.nextBigInteger();
            BigInteger one = BigInteger.valueOf(1);
            BigInteger tot = ((q.add(one)).multiply(q.add(one))).subtract(q.add(one));
            tot = tot.divide(BigInteger.valueOf(2));
            tot = (tot.subtract((q.subtract(one)).multiply(BigInteger.valueOf(2)))).subtract(one);
            if(q.remainder(BigInteger.valueOf(2)) == BigInteger.valueOf(0)) {
                tot = tot.subtract(q.divide(BigInteger.valueOf(2)).subtract(one));
            }
            System.out.println(tot.remainder(p));
        }
    }
}
