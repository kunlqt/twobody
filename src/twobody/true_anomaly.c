#include <twobody/true_anomaly.h>
#include <twobody/math_utils.h>

#include <math.h>

double true_radius(double p, double e, double f) {
    return p / (1.0 + e * cos(f));
}

double true_anomaly_from_radius(double p, double e, double r) {
    return acos(clamp(-1.0, 1.0, (p / r - 1.0) / e));
}

double true_dfdt(double mu, double p, double e, double f) {
    return sqrt(mu / cube(p)) * square(1 + e * cos(f));
}

double true_velocity(double mu, double p, double e, double f) {
    return sqrt(mu / p * (e*e + 2.0*e*cos(f) + 1));
}

double true_velocity_radial(double mu, double p, double e, double f) {
    return sqrt(mu/p) * e * sin(f);
}

double true_velocity_horizontal(double mu, double p, double e, double f) {
    return sqrt(mu/p) * (1 + e * cos(f));
}

double true_sigma(double p, double e, double f) {
    return sqrt(p) * (e * sin(f)) / (1 + e * cos(f));
}

double true_tan_phi(double e, double f) {
    return e * sin(f) / (1 + e * cos(f));
}

double true_flight_path_angle(double e, double f) {
    return atan(true_tan_phi(e, f));
}

double true_x(double p, double e, double f) {
    return cos(f) * true_radius(p, e, f);
}

double true_y(double p, double e, double f) {
    return sin(f) * true_radius(p, e, f);
}

double true_xdot(double mu, double p, double e, double f) {
    (void)e;
    return -sqrt(mu / p) * sin(f);
}

double true_ydot(double mu, double p, double e, double f) {
    return sqrt(mu / p) * (e + cos(f));
}

double true_f(double mu, double p, double r0, double r, double df) {
    (void)mu; (void)r0;
    return 1.0 - (r/p) * (1.0 - cos(df));
}

double true_g(double mu, double p, double r0, double r, double df) {
    return r*r0/sqrt(mu*p) * sin(df);
}

double true_fdot(double mu, double p, double r0, double r, double df) {
    return sqrt(mu/p) * tan(df/2.0) * ((1.0 - cos(df))/p - 1.0/r - 1.0/r0);
}

double true_gdot(double mu, double p, double r0, double r, double df) {
    (void)mu; (void)r;
    return 1.0 - r0/p * (1.0 - cos(df));
}
