#include<bits/stdc++.h>
using namespace std;

class Vec3{
public:
    float x;
    float y;
    float z;
Vec3(float x,float y,float z) : x(x),y(y),z(z){}

Vec3 operator+(Vec3 const& p_vec) const {
    return Vec3(x+p_vec.x,y+p_vec.y,z+p_vec.z);
}

Vec3 operator-(Vec3 const& p_vec) const {
    return Vec3(x-p_vec.x,y-p_vec.y,z-p_vec.z);
}

Vec3 operator*(float p) const {
    return Vec3(p*x,p*y,p*z);
}

Vec3 operator/(float p) const {
    return (*this)*(1/p);
}

Vec3 operator-() const {
    return (*this)*(-1);
}

float operator[](char a) const {
    if(a=='x') return x;
    else if(a=='y') return y;
    else if(a=='z') return z;
}

float length() const {
    return sqrt(pow(x,2)+pow(y,2)+pow(z,2));
}

Vec3 unit() const {
    return (*this)/((*this).length());
}

float dot(Vec3 const& other) const {
    return x*other.x + y*other.y + z*other.z;
}

Vec3 cross(Vec3 const& other) const {
    float crx = y*other.z - z*other.y, cry = z*other.x - x*other.z, crz = x*other.y - y*other.x;
    return Vec3(crx,cry,crz);
}

Vec3 reflect(Vec3 const& normal) const {
    Vec3 unit_norm = normal.unit();
    return *this-unit_norm*2*(unit_norm.dot(*this));
}

Vec3 refract(Vec3 const&normal, float refr_index){
    Vec3 unit_norm = normal.unit();
    Vec3 unit_inc = (*this).unit();
    Vec3 refract_norm = unit_inc - unit_norm*(unit_inc.dot(unit_norm)) + unit_norm*(sqrt(1+pow(refr_index,2)+pow(unit_norm.dot(unit_inc),2)));
    return refract_norm*((*this).length()/refr_index);
}

void vecprint(){
    cout << x << " " << y << " " << z << "\n";
}

};



int main(){
    float q,w,e;
    float mew;
    cout << "A :";
    cin >> q >> w >> e;
    cout << "\n";
    Vec3 A(q,w,e);
    cout << "B :";
    cin >> q >> w >> e;
    cout << "\n";
    Vec3 B(q,w,e);
    cout << "N :";
    cin >> q >> w >> e;
    cout << "\n";
    Vec3 N(q,w,e);
    cout << "mew: ";
    cin >> mew;
    cout << "\n";
    (A+B).vecprint();
    (A-B).vecprint();
    cout << A.dot(B);
    (A.cross(B)).vecprint();
    cout << A.length() << "\n";
    (A.unit()).vecprint();
    (A.reflect(N)).vecprint();
    (A.refract(N,mew)).vecprint();


}