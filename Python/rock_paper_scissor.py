import random
user_choice=int(input("Enter Your Choice: Type 0 for Rock, 1 for paper ,2 for Scissor\n"))

if user_choice>=3 or user_choice<0:
   print("Invalid Input")

else:   
     computer_choice=random.randint(0,2)
print("Computer Choice:")
print(computer_choice)
if computer_choice==user_choice:
    print("It's a draw")
elif computer_choice== 0 and user_choice==2:
      print("you loose")
elif user_choice==2 and computer_choice==0:
      print("you Win")
elif computer_choice>user_choice:
        print("You Loose")
elif user_choice>computer_choice:
      print("You Win")
    