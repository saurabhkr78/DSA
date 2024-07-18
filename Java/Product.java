import java.io.*;


public class Product implements Serializable {
    private String name;
    private int price;
    private int quantity;

public Product(String name, int price, int quantity) {
      this.name = name;
        this.price = price;
        this.quantity = quantity;
    }

public void serialize(String filename) {
        try {
            FileOutputStream fileOut = new FileOutputStream(filename);
            ObjectOutputStream objectOut = new ObjectOutputStream(fileOut);
            objectOut.writeObject(this);
            objectOut.close();
            fileOut.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
}

public static Product deserialize(String filename) {
        Product product = null;
        try {
            FileInputStream fileIn = new FileInputStream(filename);
            ObjectInputStream objectIn = new ObjectInputStream(fileIn);
            product = (Product) objectIn.readObject();
            objectIn.close();
            fileIn.close();
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
        return product;
    }

public static void main(String[] args) {
        Product product1 = new Product("Laptop", 63000, 1);
        product1.serialize("product.text"); 

Product product2 = Product.deserialize("product.text");
        if (product2 != null) {
            System.out.println("Product Name: " + product2.name);
            System.out.println("Product Price: " + product2.price);
            System.out.println("Product Quantity: " + product2.quantity);
        } else {
            System.out.println("Error");
        }
    }
}
