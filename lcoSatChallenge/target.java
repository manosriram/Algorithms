import java.io.*;
import java.util.*;

class target {

    boolean checkEr(int n, int a[], int target) {

        return false;
    }

    public static void main(String args[]) {
        Hashtable<Integer, Integer> h = new Hashtable<Integer, Integer>();
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        target ob = new target();
        int target = in.nextInt();
        int a[] = new int[n];
        int t, i;
        for (t = 0; t < n; t++) {
            a[t] = in.nextInt();
        }

        for (t = 0; t < n; t++) {
            if (h.containsKey(target - a[t])) {
                System.out.println(a[t] + " " + (target - a[t]));
                return;
            } else {
                h.put(a[t], a[t]);
            }
        }

    }
}