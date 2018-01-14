#include <fstream>
#include <string>

std::ifstream f1("random.in");
std::ofstream f2("random.out");

int cerintaFoarteSerioasa;
std::string s[10]={"Robert Tarjan","Leslie Valiant","Alexander Razborov","Avi Wigderson","Peter Shor","Madhu Sudan","Jon Kleinberg","Daniel Spielman","Subhash Khot"};

int main()
{
    f1>>cerintaFoarteSerioasa;

    int raspuns = cerintaFoarteSerioasa - 1982;
    raspuns /= 4;

    f2<<s[raspuns];

    return 0;
}
