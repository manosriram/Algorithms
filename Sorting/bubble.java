import java.io.*;
import java.util.*;

class bubble {
    public static void main(String args[]) throws IOException {
        int i,j;
        int n;
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(in.readLine());
        int a[] = new int[n];
        String line = in.readLine(); // to read multiple integers line
        String[] strs = line.trim().split("\\s+");

    for (i = 0; i < n; i++) {
    a[i] = Integer.parseInt(strs[i]);
}
        for (i=0;i<n;i++) {
            for (j=i+1;j<n;j++) {
                if (a[i] > a[j]) {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }

        for (int t=0;t<n;t++)
        System.out.print(a[t] + " ");
    }
}