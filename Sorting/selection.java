import java.io.*;
import java.util.*;

class selection {
    public static void main(String args[]) throws IOException {
        int min,i,j,k,t;
        int n;

        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(in.readLine());
        int a[] = new int[n];
        String line = in.readLine();
        String strs[] = line.trim().split("\\s+");
        for (t=0;t<n;t++) {
            a[t] = Integer.parseInt(strs[t]);
        }

        for (i=0;i<n;i++) {
            min = i;
            for (j=i+1;j<n;j++) {
                if (a[j] < a[min]) min = j;
            }
            int temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }

        for (t=0;t<n;t++)
        System.out.print(a[t] + " ");
    }
}