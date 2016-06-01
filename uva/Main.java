import java.util.*;
import java.math.*;

public class Main {
    public static void main(String args[]) {
        final int maxn = 2000 + 5;
        Scanner cin = new Scanner(System.in);
        BigInteger f[] = new BigInteger[maxn];
        for (int i = 0; i < maxn; i++) f[i] = BigInteger.ZERO;
        int A[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
        f[0] = BigInteger.ONE;
        for (int i = 0; i < maxn; i++) {
            for (int j = 0; j < 10; j++) {
                if(!(i == 0 && j == 0) && i + A[j] < maxn) {
                    f[i + A[j]] = f[i + A[j]].add(f[i]);
                }
            }
        }

        BigInteger ans[] = new BigInteger[maxn];
        for (int i = 0; i < maxn; i++) ans[i] = BigInteger.ZERO;
        ans[0] = BigInteger.ZERO;
        for (int i = 1; i < maxn; i++) {
            // System.out.println(f[i]);
            ans[i] = ans[i-1].add(f[i]);
            // System.out.println("ans[i]" + ans[i]);
        }
        for (int i = 6; i < maxn; i++) {
            ans[i] = ans[i].add(BigInteger.ONE);
        }

        while(cin.hasNext()) {
            int n = cin.nextInt();
            System.out.println(ans[n]);
        }
    }
}
