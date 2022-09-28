package Cars;

public class Truck extends Car{
    protected int Capacity;

    public Truck(String plate, int power, boolean automatic, int capacity) {
        super(plate, power, automatic);
        Capacity = capacity;
    }

    @Override
    public String toString() {
        return super.toString()+", "+ "Capacity= "+ Capacity ;
    }
}
