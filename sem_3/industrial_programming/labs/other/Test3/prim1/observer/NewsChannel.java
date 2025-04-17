package prim1.observer;

public class NewsChannel implements MyObserver{

    private String name;
    private String news;

    public NewsChannel(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public String getNews() {
        return news;
    }

    @Override
    public void update(MySubject theChangedSubject) {
        if (theChangedSubject instanceof NewsAgency) {
            this.news = ((NewsAgency) theChangedSubject).getNews();
        }
        System.out.println("Name: " + name + "\nNews: " + news + "\n----------");
    }
}
