# Define the parameter ranges
$algorithmRange = 0, 1, 2, 3
$numSensorsRange = 100, 200
$numDepotsRange = 1, 3
$sensorRadiusRange = 50, 100
$energyBudgetRange = 6000000, 10000000
$sensorRadiusDoiPercentageRange = 0.8, 0.9, 1
$doiRange = 0.001, 0.01, 0.1

# Define the base command
$baseCommand = ".\cmake-build-release\TOSN.exe --params"

# Initialize a counter for total iterations
$it = 1
$tot = $algorithmRange.Count * $numSensorsRange.Count * $numDepotsRange.Count * $sensorRadiusRange.Count * $energyBudgetRange.Count * $sensorRadiusDoiPercentageRange.Count * $doiRange.Count


# Nested loops to iterate over parameter combinations
foreach ($algorithm in $algorithmRange) {
    foreach ($numDepots in $numDepotsRange) {
        foreach ($sensorRadius in $sensorRadiusRange) {
            foreach ($energyBudget in $energyBudgetRange) {
                foreach ($numSensors in $numSensorsRange) {
					foreach ($sensorRadiusDoiPercentage in $sensorRadiusDoiPercentageRange) {
						foreach ($doi in $doiRange) {
							# Define the exp_name parameter based on the parameter values
							$expName = "doi_s${numSensors}_d${numDepots}_r${sensorRadius}_rd${sensorRadiusDoiPercentage}_doi${doi}_b$([math]::Round($energyBudget/1e+6,2))_a${algorithm}"

							# Construct the full command with varying parameters
							$fullCommand = "$baseCommand -exp_name $expName -num_sensors $numSensors -num_depots $numDepots -sensor_radius $sensorRadius -sensor_radius_doi_percentage $sensorRadiusDoiPercentage -doi $doi -energy_budget $energyBudget -algorithm $algorithm -scenario 1"

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
}
