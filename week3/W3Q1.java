class W3Q1 {

    String model;
    int year;
    String color;

    W3Q1(String model, int year, String color) {
       this.model = model;
       this.year = year;
       this.color = color;
   }

    void displayCarInfo() {
       System.out.println("Model: " + model);
       System.out.println("Year: " + year);
       System.out.println("Color: " + color);
   }

   public static void main(String[] args) {

       W3Q1 car1 = new W3Q1("Toyota Camry", 2020, "Blue");
       W3Q1 car2 = new W3Q1("Honda Accord", 2021, "Red");

       System.out.println("Car 1 Information:");
       car1.displayCarInfo();
       System.out.println();

       System.out.println("Car 2 Information:");
       car2.displayCarInfo();
   }
}