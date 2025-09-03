// Odd or Even Number by taking input

import java.util.Scanner;

class Third{
    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int number = scanner.nextInt();

        if(number == 0){
            System.out.println("The number is zero.");
        }
        else if (number % 2 == 0) {
            System.out.println(number + " is even.");
        } else {
            System.out.println(number + " is odd.");
        }

        scanner.close();
    }
}
 