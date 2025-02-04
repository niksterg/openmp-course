# pi_mc.jl
#
# This program calculates the value of pi using the Monte Carlo method.
# It uses Julia's thread parallelization.
# The number of random trials is set by command-line argument -n.
#
# Nikolaos Stergioulas, Aristotle University of Thessaloniki 
#
# Content provided under a Creative Commons Attribution license, CC BY-NC-SA 4.0; code under GNU GPLv3 License. 
# (c)2024 Nikolaos Stergioulas   

# in the Julia REPL install the ArgParse package with
# import Pkg; Pkg.add("ArgParse")

using ArgParse
using Random

function count_hits(random_trials::Int, seed::Int)
    rng = MersenneTwister(seed)
    count = 0
    for _ in 1:random_trials
        # Julia generates random numbers in the interval [0,1)
        # to generate random numbers in the interval [-1,1) we use
        # 2*(rand(rng) - 0.5), which means that we generate random
        # numbers in the interval [-0.5,0.5) and then we multiply
        # by 2 and subtract 1.
        x, y = 2*(rand(rng) - 0.5), 2*(rand(rng) - 0.5)
        if x * x + y * y <= 1.0
            count += 1
        end
    end
    return count
end

# function count_hits(random_trials::Int, seed::Int)
#     rng = MersenneTwister(seed)
#     xs = 2.0 * (rand(rng, random_trials) .- 0.5)
#     ys = 2.0 * (rand(rng, random_trials) .- 0.5)
#     count = 0
#     @inbounds for i in 1:random_trials
#         if xs[i]^2 + ys[i]^2 <= 1.0
#             count += 1
#         end
#     end
#     return count
# end

function main()
    s = ArgParseSettings()
    @add_arg_table! s begin
        "--random_trials", "-n"
            arg_type = Int
            required = true
            help = "number of random trials"
        "--seed", "-s"
            arg_type = Int
            default = trunc(Int, time())
            help = "random seed"
        "--threads", "-p"
            arg_type = Int
            default = 1
            help = "number of threads"
    end

    parsed_args = parse_args(ARGS, s)
    random_trials = parsed_args["random_trials"]
    seed = parsed_args["seed"]
    threads = parsed_args["threads"]

    # Set the number of threads
    ENV["JULIA_NUM_THREADS"] = threads

    trials_per_thread = random_trials ÷ threads
    
    counts = zeros(Int, threads)
    Threads.@threads for i in 1:threads
        counts[i] = count_hits(trials_per_thread, seed + i)
    end

    count = sum(counts)

    pi_estimate = 4.0 * count / random_trials
    println("Pi estimate = ", pi_estimate)
end

main()