import java.io.*;
import java.util.*;

class hops {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int n, t, i;
        n = in.nextInt();
        int a[] = new int[n];

        for (t = 0; t < n; t++) {
            a[t] = in.nextInt();
        }
        int cur = 0;
        for (t = 0; t < n; t++) {
            if (a[t] != 0) {
                cur += a[t];
                t += a[t] - 1;
            } else
                break;
        }

        if (cur == n - 1)
            System.out.println("Reached End..");
        else
            System.out.println("Not able to Reach the end :(");
    }
}