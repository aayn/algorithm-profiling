from perf_utils import timer
from functools import lru_cache
import sys


@timer
def rod_cutting(l, prices, mode="r"):
    if mode == "r":

        @lru_cache(maxsize=l + 1)
        def recursive_soln(l):
            if l == 0:
                return 0
            return max(prices[i] + recursive_soln(l - i) for i in range(1, l + 1))

        ans = recursive_soln(l)
    else:

        def iterative_soln(l):
            table = [0] * (l + 1)
            for i in range(1, l + 1):
                max_val = -1
                for j in range(1, i + 1):
                    max_val = max(max_val, prices[j] + table[i - j])
                table[i] = max_val
            return table[l]

        ans = iterative_soln(l)

    return ans


if __name__ == "__main__":
    sys.setrecursionlimit(999999)
    l = 5000
    prices = [0] * (l + 1)
    import random

    cumulative = 0
    for i in range(1, l + 1):
        rval = random.randint(0, 100)
        cumulative += rval
        prices[i] = cumulative

    print("Recursive", end=" ")
    print(rod_cutting(l, prices, "r"))

    print("Iterative", end=" ")
    print(rod_cutting(l, prices, "i"))

