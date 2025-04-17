public abstract class Person {
    protected String name;
    protected long id;
    public Person(String name, long id) {
        this.name = name;
        this.id = id;
    }

    public abstract String acceptMyVisitor(MyVisitor v);

    @Override
    public boolean equals(Object o) {
        if (o instanceof Person) {
            return this.id == ((Person) o).getId();
        }
        return this.equals(o);
    }
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
    public long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
    }
    @Override
    public String toString() {
        return this.acceptMyVisitor(new MyVisitorImpl());
    }
}
