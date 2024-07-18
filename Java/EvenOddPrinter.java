public class EvenOddPrinter {
    public static void main(String[] args) throws InterruptedException  {
        

        Thread evenThread = new Thread(() -> {
            for (int i = 2; i <= 10; i += 2) {
                System.out.println(i);
            }
        });

        Thread oddThread = new Thread(() -> {
            for (int i = 1; i <= 10; i += 2) {
                System.out.println(i);
            }
        });

        evenThread.start();
        oddThread.start();

        evenThread.join();
        oddThread.join();
    }
}