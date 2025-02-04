# pi_mc.py
#
# This program calculates the value of pi using the Monte Carlo method.
# It uses Python multiprocessing for parallelization.
# The number of threads is set by command-line argument -p.
# The number of random trials is set by command-line argument -n.
#
# Nikolaos Stergioulas, Aristotle University of Thessaloniki 
#
# Content provided under a Creative Commons Attribution license, CC BY-NC-SA 4.0; code under GNU GPLv3 License. 
# (c)2024 Nikolaos Stergioulas   


import argparse
import random
import multiprocessing
import time
from numba import njit
from numba.typed import List
from numba import prange
from numba import jit
import argparse
import numpy as np


@njit(fastmath=False)
def count_hits(random_trials, seed=None):
    random.seed(seed)
    count = 0
    for _ in range(random_trials):
        x, y = random.uniform(-1.0, 1.0), random.uniform(-1.0, 1.0)
        if x * x + y * y <= 1.0:
            count += 1
    return count

# @jit(nopython=True, parallel=True)
# def count_hits(random_trials, seed=None):
#     np.random.seed(seed)
#     count = 0
#     for _ in prange(random_trials):
#         x, y = np.random.uniform(-1.0, 1.0), np.random.uniform(-1.0, 1.0)
#         if x * x + y * y <= 1.0:
#             count += 1
#     return count


if __name__ == "__main__":

    parser = argparse.ArgumentParser(description='Calculate Pi using Monte Carlo method.')
    parser.add_argument('-p', '--processes', type=int, default=multiprocessing.cpu_count(),
                        help='Number of processes to use')
    parser.add_argument('-n', '--N', type=int, default=100000000,
                        help='Number of random trials')
    args = parser.parse_args()

    num_processes = args.processes #multiprocessing.cpu_count()

    N = args.N

    pool = multiprocessing.Pool(processes=num_processes)

    start_time = time.time()

    random_trials_per_process = N // num_processes

    #counts = pool.map(count_hits, [random_trials_per_process] * num_processes)

    #seeds = [i for i in range(num_processes)]
    #seeds = [random.randint(0, 1e9) for _ in range(num_processes)]
    seeds = [int(time.time()) + i for i in range(num_processes)]

    counts = pool.starmap(count_hits, [(random_trials_per_process, seed) for seed in seeds])

    pi_estimate = 4 * float(sum(counts)) / float(N)

    end_time = time.time()
    print(f"Estimated value of Pi = {pi_estimate:.12f}")