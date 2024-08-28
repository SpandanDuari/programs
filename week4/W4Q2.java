public class W4Q2 {
    private String companyName;
    private String modelName;
    private int year;
    private double mileage;

    public String getCompanyName() {
        return companyName;
    }

    public void setCompanyName(String companyName) {
        this.companyName = companyName;
    }

    public String getModelName() {
        return modelName;
    }

    public void setModelName(String modelName) {
        this.modelName = modelName;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }

    public double getMileage() {
        return mileage;
    }

    public void setMileage(double mileage) {
        this.mileage = mileage;
    }

    public static void main(String[] args) {
        W4Q2 myCar = new W4Q2();
        myCar.setCompanyName("Toyota");
        myCar.setModelName("Corolla");
        myCar.setYear(2020);
        myCar.setMileage(15000.5);

        System.out.println("Company: " + myCar.getCompanyName());
        System.out.println("Model: " + myCar.getModelName());
        System.out.println("Year: " + myCar.getYear());
        System.out.println("Mileage: " + myCar.getMileage());
    }
}