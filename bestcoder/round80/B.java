import java.math.*;
import java.math.BigInteger;
import java.util.Scanner;
public class Main {
    public static void main(String args[]) {
        Scanner cin = new Scanner(System.in);
        BigInterger p, q;
        int T;
        T = cin.nextInteger();
        while(T--) {
            p = cin.nextBigInteger();
            q = cin.nextBigInteger();
            BigInterger tot = (q.add(1).multiply(q.add(1)).subtract(q.add(1)));
            tot = tot.divide(2);
            tot = tot.subtract(q.subtract(1).multiply(2)).subtract(1);
            if(q.remainder(2) == 2) {
                tot = tot.subtract(q.divide(2).subtract(1));
            }
            System.out.println(tot.remainder(p));
        }
    }
}
