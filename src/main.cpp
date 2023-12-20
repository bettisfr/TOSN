#include <iostream>

#include "input.h"
#include "core/algorithms.h"
#include "core/deployment.h"
#include "model/energy.h"

using namespace std;

void run_experiment(input &par) {
    if (par.experiment != 0) {
        par = load_parameters(par);
    }

    print_parameters(par);

    // Deployment creation with respect to the input parameters
    deployment dep(par);
    // cout << dep << endl;
    // Algorithms creation and invocation
    algorithms alg(&dep);
    
//    alg.approxTSPN_S(dep.get_sensor_radius());
//    alg.approxMPN_S(dep.get_sensor_radius());
//    alg.approxTSPN_M(dep.get_sensor_radius());
//    alg.approxMPN_M(dep.get_sensor_radius());
    
    // with DOI
//    alg.approxTSPN_S_doi();
//    alg.approxMPN_S_doi();
//    alg.approxTSPN_M_doi();
//    alg.approxMPN_M_doi();

    alg.approxTSPN_S_xxx();
}

int main(int argc, char** argv) {
//    energy e;

    input par;

    if (argc >= 3) {
        try {
            par.experiment = stoi(argv[1]);
        } catch (const invalid_argument& e) {
            cerr << "Error. Experiment number must be an integer." << endl;
            exit(1);
        } catch (const out_of_range& e) {
            cerr << "Error. Experiment number is out of range." << endl;
            exit(1);
        }

        par.exp_name = argv[2];
    } else {
        cerr << "Error. Use: " << argv[0] << " 0|1 filename" << endl;
        exit(1);
    }

    if (par.experiment != 0 && par.experiment != 1) {
        cerr << "\n[ERROR main] Experiment to run not present\n";
        exit(1);
    }

    run_experiment(par);

    return 0;
}
