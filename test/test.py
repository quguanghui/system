for i in range(0,4096):
    result = i & ~4095
    if result != 0:
        print(result)