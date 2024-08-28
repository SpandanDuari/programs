class Vehicle {
    void startEngine() {
        System.out.println("Starting vehicle engine...");
    }

    void stopEngine() {
        System.out.println("Stopping vehicle engine...");
    }
}

class Car extends Vehicle {
    @Override
    void startEngine() {
        System.out.println("Car engine starts");
    }

    @Override
    void stopEngine() {
        System.out.println("Car engine stops");
    }
}

class Motorcycle extends Vehicle {
    @Override
    void startEngine() {
        System.out.println("Motorcycle engine starts ");
    }

    @Override
    void stopEngine() {
        System.out.println("Motorcycle engine stops ");
    }
}

public class W4Q1 {
    public static void main(String[] args) {
        Vehicle myCar = new Car();
        Vehicle myMotorcycle = new Motorcycle();

        myCar.startEngine();
        myCar.stopEngine();

        myMotorcycle.startEngine();
        myMotorcycle.stopEngine();
    }
}