# Define the parameter ranges
$algorithmRange = 0, 1, 2, 3
$numSensorsRange = 50, 100, 200
$numDepotsRange = 1, 3
$sensorRadiusRange = 50, 75, 100
$energyBudgetRange = 2500000, 5000000, 10000000

# Define the base command
$baseCommand = ".\cmake-build-release\TOSN.exe --params"

# Initialize a counter for total iterations
$it = 1
$tot = ($algorithmRange.Count * $numSensorsRange.Count * $numDepotsRange.Count * $sensorRadiusRange.Count * $energyBudgetRange.Count) / 2

# Nested loops to iterate over parameter combinations
foreach ($numSensors in $numSensorsRange) {
    foreach ($numDepots in $numDepotsRange) {
        foreach ($sensorRadius in $sensorRadiusRange) {
            foreach ($energyBudget in $energyBudgetRange) {
                foreach ($algorithm in $algorithmRange) {
                    # Check the constraints on numDepots and algorithm
                    if (($numDepots -eq 1 -and ($algorithm -eq 0 -or $algorithm -eq 1)) -or
                        ($numDepots -gt 1 -and ($algorithm -eq 2 -or $algorithm -eq 3))) {

                        # Define the exp_name parameter based on the parameter values
                        $expName = "dtr_s${numSensors}_d${numDepots}_r${sensorRadius}_b$([math]::Round($energyBudget/1e+6,2))_a${algorithm}"

                        # Construct the full command with varying parameters
                        $fullCommand = "$baseCommand -exp_name $expName -num_sensors $numSensors -num_depots $numDepots -sensor_radius $sensorRadius -energy_budget $energyBudget -algorithm $algorithm -scenario 2"

                        # Display the command
                        Write-Host "Executing $it/$tot = $fullCommand"

                        # Uncomment the next line to execute the command
                        Invoke-Expression $fullCommand

                        # Increment the total iterations counter
                        $it++
                    }
                }
            }
        }
    }
}
