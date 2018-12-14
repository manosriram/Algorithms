import java.io.*;
import java.util.*;

class selection {
    public static void main(String args[]) throws IOException {
        int n, i, j, k, t;

        Scanner in = new Scanner(System.in);
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = in.nextInt();

        int a[] = new int[n];

        // String line = br.readLine();
        // String strs[] = line.trim().split("\\s+");

        for (t = 0; t < n; t++)
            a[t] = in.nextInt();

        for (t = 1; t < n; t++) {
            int v = a[t];
            j = t;

            while (a[j - 1] > v && j >= 1) {
                a[j] = a[j - 1];
                j--;
            }
            a[j] = v;
        }

        for (t = 0; t < n; t++)
            System.out.print(a[t] + " ");
    }
}