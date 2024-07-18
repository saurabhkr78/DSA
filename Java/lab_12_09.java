import java.io.*;

class MethodOverloading {
    static int add(int a, int b) { return a + b; }
    static int add(int a, int b, int c) { return a + b + c; }

    // Main Function
    public static void main(String args[]) {
        System.out.println("add function with 2 parameters");
        // Calling function with 2 parameters
        System.out.println(add(40, 16));
        System.out.println("add function with 3 parameters");
        System.out.println(add(40, 16, 27));
    }
}


// import java.io.*;

// class Animal {
// void eating()
// {
// System.out.println("eating method of base class"); System.out.println("eating.");
// }
// }


// class Dog extends Animal {
// void eating()
// {
// System.out.println("eating method of derived class"); 
// System.out.println("Dog is eating.");
// }
// }


// class MethodOverriding {


// public static void main(String args[])
// {
// Dog d1 = new Dog(); Animal a1 = new Animal(); d1.eating();
// a1.eating();
// Animal animal = new Dog(); animal.eating();
// }
// }
