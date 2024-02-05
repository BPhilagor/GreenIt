import random
import array as arr
import time
import numpy as np

def main():
    random.seed()
    test = arr.array('i', (random.randint(0, 2**31 - 1) for _ in range(100000000)))
    print(test[:10])
    print("Done")
    time.sleep(2)
    print("Sorting start")
    result = np.sort(test)
    print(result[:10])
    print("Sorting Done")
    time.sleep(1)

if __name__ == "__main__":
    main()