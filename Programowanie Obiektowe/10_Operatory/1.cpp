

struct vec3
{
	double x, y, z;
};

vec3 operator+(const vec3& v1, const vec3& v2)
{
	return vec3{ v1.x + v2.x,v1.y + v2.y,v1.z + v2.z };
}

vec3 operator-(const vec3& v1, const vec3& v2)
{
	return vec3{ v1.x - v2.x,v1.y - v2.y,v1.z - v2.z };
}

vec3& operator+=(vec3& v1, const vec3& v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	return v1;
}

vec3& operator-=(vec3& v1, const vec3& v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	return v1;
}

vec3 operator*(const vec3& v1, const vec3& v2)
{
	return vec3{ v1.y*v2.z - v1.z*v2.y,v1.z*v2.x - v1.x*v2.z,v1.x*v2.y - v1.y*v2.x };
}

vec3& operator*(vec3& v1, const vec3& v2)
{
	v1 = vec3{ v1.y*v2.z - v1.z*v2.y,v1.z*v2.x - v1.x*v2.z,v1.x*v2.y - v1.y*v2.x };
	return v1;
}

//int main()
//{
//	vec3 v{ 1,23,3 };
//	vec3 v2{ 2,5,2 };
//	auto v3 = v * v2;
//	return 0;
//}