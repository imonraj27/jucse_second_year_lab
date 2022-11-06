import re

num = input('Enter a mobile number to validate: ')

if len(num) != 10:
    print("Invalid Phone Number length(must be 10 digits)....")
else:
    Pattern = re.compile("[7-9][0-9]{9}")
    if Pattern.match(num):
        print('Valid Mobile Number')
    else:
        print("Invalid Mobile Number")
