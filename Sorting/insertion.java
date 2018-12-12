import java.io.*;
import java.util.*;

class insertion {
    public static void main(String args[]) throws IOException {
        int v;
        int n;
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(in.readLine());
        int a[] = new int[n];
        String line = in.readLine(); // to read multiple integers line
        String[] strs = line.trim().split("\\s+");
        int a2;
        int i,j,t;
    
        for (t=0;t<n;t++) {
        a[t] = Integer.parseInt(strs[t]);
        }

        for (t=1;t<n;t++) {
            v = a[t];
            j=t;
            while (a[j-1] > v && j>=1) {
                a[j] = a[j-1];
                j--;
            }
            a[j] = v;
        }

        for (t=0;t<a.length;t++)
        System.out.print(a[t] + " ");
        
    }
}