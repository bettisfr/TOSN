import subprocess
import os
import sys


def run_simulation():
    # Define the output folder
    output_folder = "output"

    # Create the output folder if it doesn't exist
    if not os.path.exists(output_folder):
        os.makedirs(output_folder)

    # Define the parameter ranges
    algorithm_range = [0, 1]
    num_sensors_range = [50, 100, 200, 400]
    num_depots = 1
    sensor_radius_range = [40, 60, 80]
    wireless_technology = 1
    energy_budget = 1500000

    iterations = 10
    scenario = 2

    # Define the base command
    baseCommand = "./cmake-build-release --params"

    # Initialize a counter for total iterations
    it = 1
    tot = (len(algorithm_range) * len(num_sensors_range) * len(sensor_radius_range))

    for num_sensors in num_sensors_range:
        for algorithm in algorithm_range:
            for radius in sensor_radius_range:
                # Define the exp_name parameter based on the parameter values
                expName = f"dtr_s{num_sensors}_d{num_depots}_r{radius}_b{round(energy_budget / 1e+6, 2)}_w{wireless_technology}_a{algorithm}"

                # Construct the full command with varying parameters
                fullCommand = f"{baseCommand} -exp_name {expName} -iterations {iterations} -num_sensors {num_sensors} -num_depots {num_depots} -sensor_radius {radius} -energy_budget {energy_budget} -wireless_technology {wireless_technology} -algorithm {algorithm} -seed {it} -scenario {scenario}"

                # Display the command
                print(f"Executing {it}/{tot} = {fullCommand}")

                # Uncomment the next line to execute the command
                subprocess.run(fullCommand, shell=True)

                # Increment the total iterations counter
                it += 1


if __name__ == "__main__":
    run_simulation()
