import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        long a, b, c;

        Scanner scanner = new Scanner(System.in);

        a = scanner.nextLong();
        b = scanner.nextLong();

        c = a + b;
        String cStr = String.valueOf(c);
        StringBuffer tempStr = new StringBuffer();
        int count = 0;
        for(int i = cStr.length() - 1; i >= 0; i--, count++){
            if(count == 3 && cStr.charAt(i) != '-'){
                tempStr.insert(0,',');
                count = 0;
            }
            tempStr.insert(0,cStr.charAt(i));
        }

        System.out.println(tempStr);
    }
}
