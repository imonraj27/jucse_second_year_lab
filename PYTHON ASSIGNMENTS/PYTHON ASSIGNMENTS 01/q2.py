

coupon_codes = {
    "Monday": 2222,
    "Tuesday": 3333,
    "Wednesday": 1000,
    "Thursday": 8999,
    "Friday": 9945,
    "Saturday": 9033,
    "Sunday": 6099
}
i = input("Day for the coupon code:")
if i not in coupon_codes.keys():
    print("Sorry no such day exists!")
else:
    print("Hurrah! Your coupon code is:-", coupon_codes[i])
