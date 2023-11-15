#include "algorithms.h"

#include <utility>

algorithms::algorithms(deployment *dep) {
    num_sensors = dep->get_num_sensors();
    sensor_radius = dep->get_sensor_radius();

    sensors = dep->get_sensors();
    depots = dep->get_depots();
}

void algorithms::algorithm_1() {
    cout << "alg1" << endl;
    tsp_neighbors();
}

void algorithms::algorithm_2() {
    cout << "alg2" << endl;
}

double algorithms::get_distance(sensor s, point p) {
    point pos_s = s.get_position();

    double x1, y1, x2, y2;
    tie(x1, y1) = p;
    tie(x2, y2) = pos_s;

    double delta_x = x2 - x1;
    double delta_y = y2 - y1;

    return sqrt(delta_x * delta_x + delta_y * delta_y);
}

int algorithms::get_angle(sensor s, point p) {
    point pos_s = s.get_position();

    double x1, y1, x2, y2;
    tie(x1, y1) = p;
    tie(x2, y2) = pos_s;

    double delta_x = x2 - x1;
    double delta_y = y2 - y1;

    double angle_rad = atan2(delta_y, delta_x);
    double angle_deg = angle_rad * (180.0 / M_PI);

    int rounded_angle = static_cast<int>(round(angle_deg));

    if (rounded_angle < 0) {
        rounded_angle += 360;
    }

    return rounded_angle;
}

bool algorithms::is_within_radius(const sensor& s, point p) {
    double dist = get_distance(s, p);
    return (dist <= sensor_radius);
}

bool algorithms::is_within_radius_doi(const sensor& s, point p) {
    double dist = get_distance(s, p);

    int angle = get_angle(s, p);
    double actual_radius = s.get_radius_doi(angle);

    return (dist <= actual_radius);
}

void algorithms::tsp_neighbors() {
    // sort sensors from left to right


    // create independent set

    // run TSP on the previous set

    vector<point_3d> points;

    // it would be a subset of "sensors"
    for (auto s : sensors) {
        auto pos = s.get_position();
        point_3d newPoint = {pos.first, pos.second, 0};
        points.push_back(newPoint);
    }

    TSP tsp(points);
    tsp.solve();

    vector<int> res = tsp.get_path();
    cout << "TSP path: ";
    for (auto p : res) {
        cout << p << ", ";
    }
    cout << endl;

    double len = tsp.get_length();
    cout << "TSP len: " << len << endl;
}

vector<point> algorithms::get_intersection_points(point a, point b) {
    // given two points a and b, returns the intersection points
    point int_ab_1 = {-1, -1};
    point int_ab_2 = {-1, -1};

    double x1 = get<0>(a);
    double y1 = get<1>(a);
    double x2 = get<0>(b);
    double y2 = get<1>(b);

    // TODO ...
    int_ab_1 = {4, 5};
    int_ab_2 = {24, 15};

    vector<point> int_points;
    int_points.push_back(int_ab_1);
    int_points.push_back(int_ab_2);

    return int_points;
}