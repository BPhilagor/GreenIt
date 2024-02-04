import random
import time

def main():
    random.seed()
    test = [random.randint(0, 2**31 - 1) for _ in range(100000000)]
    print("Done")
    time.sleep(20)
    print("Sorting start")
    test.sort()
    print("Sorting Done")
    time.sleep(10)

if __name__ == "__main__":
    main()