import time
from functools import wraps


def timer(f):
    @wraps(f)
    def wrapper(*args, **kwargs):
        start = time.perf_counter()
        ret = f(*args, **kwargs)
        end = time.perf_counter()
        print(f"{f.__name__} took {end - start} seconds to run.")
        return ret

    return wrapper


class Timer:
    def __init__(self, name=""):
        self._name = name
        self._start = 0
        self._end = 0

    def __enter__(self):
        self._start = time.perf_counter()

    def __exit__(self, *exc):
        self._end = time.perf_counter()
        print(f"{self._name} took {self._end - self._start} seconds to run.")

