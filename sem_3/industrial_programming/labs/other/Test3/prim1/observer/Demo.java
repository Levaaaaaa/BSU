package prim1.observer;

import java.util.Scanner;

public class Demo {
    public static void main(String[] args) {
        NewsAgency agency = new NewsAgency("agency1");
        NewsChannel channel1 = new NewsChannel("channel1");
        NewsChannel channel2 = new NewsChannel("channel2");

        agency.attach(channel1);
        agency.attach(channel2);

        Scanner scanner = new Scanner(System.in);
        while(true) {
            System.out.println("Enter news: ");
            String news = scanner.nextLine();
            agency.setNews(news);
        }
    }
}
