import java.util.*;
import java.io.*;

public class js {

    static int N, strsz;
    static char[] thes; 
    static HashMap<Pii, Boolean> mem;
    static String[] syll;

    static int match(int ind, String str) {
        while (ind < strsz && thes[ind] == ' ') ind++;
        for (char c : str.toCharArray()) {
            if (ind == strsz || thes[ind] != c) return -1;
            ind++;
        }
        return ind;
    }

    static boolean haiku(int ind, int left) {
        if (left == 0) return ind == strsz;
        Boolean out = mem.get(new Pii(ind, left));
        if (out != null) return out;
        out = false;
        for (int i = 0; i < N; ++i) {
            int ind2 = ind;
            ind2 = match(ind2, syll[i]);
            if (ind2 >= 0 && haiku(ind2, left - 1)) {
                out = true;
                break;
            }
        }
        mem.put(new Pii(ind, left), out);
        return out;
    }


    public static void main(String... args) {
        Kattio io = new Kattio(System.in);
        N = io.getInt();
        syll = new String[N];
        for (int i = 0; i < N; ++i) syll[i] = io.getWord();

        String a = io.getLine(),
               b = io.getLine(),
               c = io.getLine();

        thes = a.toCharArray();
        strsz = thes.length;
        mem = new HashMap<Pii, Boolean>();
        if (haiku(0, 5)) {
            thes = b.toCharArray();
            strsz = thes.length;
            mem = new HashMap<Pii, Boolean>();
            if (haiku(0, 7)) {
                thes = c.toCharArray();
                strsz = thes.length;
                mem = new HashMap<Pii, Boolean>();
                if (haiku(0, 5)) {
                    io.println("haiku");
                    io.flush();
                    return;
                }
            }
        }
        io.println("come back next year");
        io.flush();
    }

    static class Pii {
        int first, second;

        Pii(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public int hashCode() {
            return (this.first << 16) ^ this.second;
        }

    }

}

class Kattio extends PrintWriter {
    public Kattio(InputStream i) {
        super(new BufferedOutputStream(System.out));
        r = new BufferedReader(new InputStreamReader(i));
    }
    public Kattio(InputStream i, OutputStream o) {
        super(new BufferedOutputStream(o));
        r = new BufferedReader(new InputStreamReader(i));
    }

    public boolean hasMoreTokens() {
        return peekToken() != null;
    }

    public int getInt() {
        return Integer.parseInt(nextToken());
    }

    public double getDouble() {
        return Double.parseDouble(nextToken());
    }

    public long getLong() {
        return Long.parseLong(nextToken());
    }

    public String getWord() {
        return nextToken();
    }

    public String getLine() {
        nextToken();
        st = null;
        return line;
    }

    private BufferedReader r;
    private String line;
    private StringTokenizer st;
    private String token;

    private String peekToken() {
        if (token == null)
            try {
                while (st == null || !st.hasMoreTokens()) {
                    line = r.readLine();
                    if (line == null) return null;
                    st = new StringTokenizer(line);
                }
                token = st.nextToken();
            } catch (IOException e) { }
        return token;
    }

    private String nextToken() {
        String ans = peekToken();
        token = null;
        return ans;
    }
}
