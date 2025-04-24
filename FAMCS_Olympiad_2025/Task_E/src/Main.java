import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int k = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        String s = st.nextToken();
        LinkedList<Character> linkedList = new LinkedList<>();
        String op = "<>_.";
        int t = 0;
        for (int i = 0; i < s.length(); i++) {
            if (linkedList.size() >= k) {
                break;
            }
            if (op.indexOf(s.charAt(i)) == -1) {
                linkedList.add(s.charAt(i));
                t++;
            } else {
                if (s.charAt(i) == '<') {
                    if (t == 0) {
                        continue;
                    }
                    t--;
                }
                if (s.charAt(i) == '>') {
                    if (t == linkedList.size()) {
                        continue;
                    }
                    t++;
                }
                if (s.charAt(i) == '-') {
                    if (t == 0) {
                        continue;
                    }
                    linkedList.remove(t);
                    t--;
                }
                if (s.charAt(i) == '.') {
                    if (t == linkedList.size()) {
                        continue;
                    }
                    linkedList.remove(t + 1);
                }
            }
        }
        System.out.println(linkedList);
    }
}