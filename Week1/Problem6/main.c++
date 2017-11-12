#include <fstream>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
};


inline Point midpoint(const Point& a, const Point& b) {
    return Point{ (a.x + b.x)/2, (a.y + b.y)/2 };
}

inline double euclidean_distance(const Point& a, const Point& b) {
    return sqrt( (a.x-b.x)*(a.x - b.x) + (a.y-b.y)*(a.y-b.y) );
}

Point third_point_of_triangle(int ab, int ac, int bc) {
    double x = (ab*ab + ac*ac - bc*bc)/(2.0*ab);
    double y = sqrt(ac*ac - x*x);
    return Point{x, y};
}

double average_distance(const Point& a, const Point& b, const Point& c) {
    Point midpoint_ab = midpoint(a, b);
    Point midpoint_ac = midpoint(a, c);
    Point midpoint_bc = midpoint(b, c);

    double dist1 = euclidean_distance(midpoint_ab, midpoint_ac);
    double dist2 = euclidean_distance(midpoint_ab, midpoint_bc);
    double dist3 = euclidean_distance(midpoint_ac, midpoint_bc);

    return (dist1 + dist2 + dist3)/3;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fout.setf(ios::fixed);
    fout.precision(6);

    double ab, ac, bc;
    fin >> ab >> ac >> bc;

    Point a = Point{0, 0};
    Point b = Point{ab, 0};
    Point c = third_point_of_triangle(ab, ac, bc);

    fout << average_distance(a, b, c) << endl;

    return 0;
}
