import Cars.Truck;
import Cars.Car;

import java.util.ArrayList;
import java.util.Collections;

public class Main {
        public static void main(String[] args) {
            Car x = new Car("plate1",500,true  );
            Truck y= new Truck("plate2", 500, false, 250);

            System.out.println(x.toString());
            System.out.println(y.toString());


            Car test1= new Car("1bmw",500, true);
            Car test2= new Car("4kia", 500, true);
            Car test3= new Car("2wolks",500, true);
            Car test4= new Car("3mercedes",500, true);

            ArrayList<Car> cars = new ArrayList<Car>();

            cars.add( test1); cars.add(test2); cars.add(test3); cars.add(test4);

            for(Car c: cars){
                System.out.println(c.getPlate());
            }
            Collections.sort(cars);

            for(Car c: cars){
                System.out.println(c.getPlate());
            }

        }
    }