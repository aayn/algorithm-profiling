"""Comparison of different ways of initializing lists.
"""

from perf_utils import Timer


def list_1d(list_size):
    with Timer("1d_product_none"):
        a = [None] * list_size

    with Timer("1d_product"):
        b = [0] * list_size

    with Timer("1d_list_comprehension"):
        c = [0 for _ in range(list_size)]

    with Timer("1d_append"):
        d = []
        for _ in range(list_size):
            d.append(0)


def list_2d(nrows, ncols, suffix=""):
    with Timer(f"2d_product_and_list_comprehension{suffix}"):
        a = [[0] * ncols for _ in range(nrows)]

    with Timer(f"2d_list_comprehension{suffix}"):
        b = [[0 for _ in range(ncols)] for _ in range(nrows)]


if __name__ == "__main__":
    list_1d(int(1e7))
    # list_2d(100000, 1000, "_more_rows")
    # list_2d(1000, 100000, "_more_cols")
