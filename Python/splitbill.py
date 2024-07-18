# text="Welcome to my Python learning"
# # splited_text=text.split(" ")
# splited_text=text.split("o")
# print(splited_text)

import random

names=input("input the name of friends seperated by space:\n")
names_list=names.split(" ")
print(names_list)
length=len(names_list)
random_choice=random.randint(0,length-1)
print(f"{names_list[random_choice]} will pay the bill")


