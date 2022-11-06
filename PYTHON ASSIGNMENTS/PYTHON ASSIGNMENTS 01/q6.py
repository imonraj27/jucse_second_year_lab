from argparse import ArgumentError
import re


def is_valid_email_id(s: str):
    reg = r"^[a-zA-Z0-9]+@[a-zA-Z0-9]+\.[a-z]+$"
    if not re.match(reg, s) is not None:
        raise Exception("Invalid email")


def is_valid_age(x):
    if x is not int:
        try:
            x = int(x)
            # print("here")
        except Exception as e:
            print(e)
    if not int(x) >= 16:
        raise Exception("Invalid age")


def is_unique_user(listy, user):
    for i in listy:
        if i[0] == user:
            raise Exception("Non-unique user")


tuple_list = []
with open("./a.txt", 'r') as f:
    tuple_list = [tuple(i.strip().split()) for i in f.readlines()]
listy = []
for i in tuple_list:
    try:
        is_unique_user(listy, i[0])
        is_valid_age(i[1])
        is_valid_email_id(i[2])
    except Exception as e:
        print(e)
        continue
    listy.append((i[0], i[2]))
print(listy)
