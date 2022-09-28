package Cars;

import java.util.Objects;

public class Car implements Comparable<Car>{
    private String plate;
    private int power;
    private boolean automatic;

    //Constructor
    public Car(String plate, int power, boolean automatic) {
        this.plate = plate;
        this.power = power;
        this.automatic = automatic;
    }


    //Empty Constructor
    public Car() {
    }

    //Getter & Setter methods for each field
    public String getPlate() {
        return plate;
    }

    public void setPlate(String plate) {
        this.plate = plate;
    }

    public int getPower() {
        return power;
    }

    public void setPower(int power) {
        this.power = power;
    }

    public boolean getAutomatic() {
        return automatic;
    }

    public void setAutomatic(boolean automatic) {
        this.automatic = automatic;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Car car = (Car) o;
        return power == car.power && automatic == car.automatic && plate.equals(car.plate);
    }

    @Override
    public int hashCode() {
        return Objects.hash(plate, power, automatic);
    }


    public int compareTo(Car x)
    {
        if(this.getPlate().compareTo(x.getPlate())== 0) return 0;
        else if (this.getPlate().compareTo(x.getPlate())> 0) return 1;
        else return  -1;
        }


    public String toString() {
        return "Car: " +
                "plate='" + plate + '\'' +
                ", power=" + power +
                ", automatic=" + automatic
                ;
    }



}

