#pragma once
#include <iostream>
#include <list>


namespace lm {
	// Constant variables
	const double PI = 3.141592653589793;
	const double E = 2.718281828459045;
	const double PIrad = PI / 180;

	// Converting euler degrees and radians
	float degrees2radians(float angle);
	float radians2degrees(float radians);

	// Vector types
	struct vec2 {
	private:
		float* ptr;
	public:
		float x, y;
		vec2() {
			x = 0; y = 0;
			ptr = &x;
		}
		vec2(float value) {
			x = value; y = value;
			ptr = &x;
		}
		vec2(float xVal, float yVal) {
			x = xVal; y = yVal;
			ptr = &x;
		}

		float& operator[] (int idx) {
			if (idx > 1) {
				std::cerr << "vec2: Index out of range 0-2." << std::endl;
				throw std::out_of_range("Index out of range 0-2.");
			}
			return ptr[idx];
		}

		vec2& operator=(vec2 v) {
			x = v.x;
			y = v.y;
			return *this;
		}
		vec2& operator=(float v) {
			x = v;
			y = v;
			return *this;
		}

		vec2& operator++(int) {
			x++;
			y++;
			return *this;
		}
		vec2& operator--(int) {
			x--;
			y--;
			return *this;
		}
	};
	struct vec3 {
	private:
		float* ptr;
	public:
		float x, y, z;
		vec3() {
			x = 0; y = 0; z = 0;
			ptr = &x;
		}
		vec3(float value) {
			x = value; y = value; z = value;
			ptr = &x;
		}
		vec3(float xVal, float yVal) {
			x = xVal; y = yVal; z = 0;
			ptr = &x;
		}
		vec3(float xVal, float yVal, float zVal) {
			x = xVal; y = yVal; z = zVal;
			ptr = &x;
		}
		vec3(const vec2& v) {
			x = v.x; y = v.y; z = 0;
			ptr = &x;
		}

		vec2 cutVec2() {
			return { x, y };
		}

		float& operator[] (int idx) {
			if (idx > 2) {
				std::cerr << "vec3: Index out of range 0-3." << std::endl;
				throw std::out_of_range("Index out of range 0-3.");
			}
			return ptr[idx];
		}

		vec3& operator=(vec2 v) {
			x = v.x;
			y = v.y;
			return *this;
		}
		vec3& operator=(vec3 v) {
			x = v.x;
			y = v.y;
			z = v.z;
			return *this;
		}
		vec3& operator=(float v) {
			x = v;
			y = v;
			z = v;
			return *this;
		}

		vec3& operator++(int) {
			x++;
			y++;
			z++;
			return *this;
		}
		vec3& operator--(int) {
			x--;
			y--;
			z--;
			return *this;
		}
	};
	struct vec4 {
	private:
		float* ptr;
	public:
		float x, y, z, w;
		vec4() {
			x = 0; y = 0; z = 0; w = 0;
			ptr = &x;
		}
		vec4(float value) {
			x = value; y = value; z = value; w = value;
			ptr = &x;
		}
		vec4(float xVal, float yVal) {
			x = xVal; y = yVal; z = 0; w = 0;
			ptr = &x;
		}
		vec4(float xVal, float yVal, float zVal) {
			x = xVal; y = yVal; z = zVal; w = 0;
			ptr = &x;
		}
		vec4(float xVal, float yVal, float zVal, float wVal) {
			x = xVal; y = yVal; z = zVal; w = wVal;
			ptr = &x;
		}
		vec4(const vec2& v) {
			x = v.x; y = v.y; z = 0; w = 0;
			ptr = &x;
		}
		vec4(const vec3& v) {
			x = v.x; y = v.y; z = v.z; w = 0;
			ptr = &x;
		}

		vec2 cutVec2() {
			return { x, y };
		}
		vec3 cutVec3() {
			return { x, y, z };
		}

		float& operator[] (int idx) {
			if (idx > 3) {
				std::cerr << "vec4: Index out of range 0-4." << std::endl;
				throw std::out_of_range("Index out of range 0-4.");
			}
			return ptr[idx];
		}

		vec4& operator=(vec2 v) {
			x = v.x;
			y = v.y;
			return *this;
		}
		vec4& operator=(vec3 v) {
			x = v.x;
			y = v.y;
			z = v.z;
			return *this;
		}
		vec4& operator=(vec4 v) {
			x = v.x;
			y = v.y;
			z = v.z;
			w = v.w;
			return *this;
		}
		vec4& operator=(float v) {
			x = v;
			y = v;
			z = v;
			w = v;
			return *this;
		}

		vec4& operator++(int) {
			x++;
			y++;
			z++;
			w++;
			return *this;
		}
		vec4& operator--(int) {
			x--;
			y--;
			z--;
			w--;
			return *this;
		}
	};

	// Vector math functions
	// Dot product
	float dot(const vec2& v1, const vec2& v2);
	float dot(const vec3& v1, const vec3& v2);
	float dot(const vec4& v1, const vec4& v2);
	
	// Cross product
	float cross(const vec2& v1, const vec2& v2);
	vec3 cross(const vec3& v1, const vec3& v2);

	// Magnitude
	float magnitude(const vec2& vector);
	float magnitude(const vec3& vector);
	float magnitude(const vec4& vector);

	// Normalize
	vec2 normalize(const vec2& vector);
	vec3 normalize(const vec3& vector);
	vec4 normalize(const vec4& vector);

	// Power
	vec2 vecPow(const vec2& vector, const int pow);
	vec3 vecPow(const vec3& vector, const int pow);
	vec4 vecPow(const vec4& vector, const int pow);

	// Square root
	vec2 vecSqrt(const vec2& vector);
	vec3 vecSqrt(const vec3& vector);
	vec4 vecSqrt(const vec4& vector);


	// Matrix types
	// Square matricies
	struct mat2 {
	private:
		vec2* ptr;
	public:
		vec2 x, y;

		mat2() {
			x = {}; y = {};
			ptr = &x;
		}
		mat2(const vec2& x1, const vec2& y1) {
			x = x1; y = y1;
			ptr = &x;
		}

		vec2 column(int idx) {
			return vec2(x[idx], y[idx]);
		}


		mat2& operator=(const mat2& value) {
			x = value.x;
			y = value.y;
			return *this;
		}

		vec2& operator[] (int idx) {
			if (idx > 1) {
				std::cerr << "vec4: Index out of range 0-2." << std::endl;
				throw std::out_of_range("Index out of range 0-2.");
			}
			return ptr[idx];
		}
	};
	struct mat3 {
	private:
		vec3* ptr;
	public:
		vec3 x, y, z;

		mat3() {
			x = {}; y = {}; z = {};
			ptr = &x;
		}
		mat3(const mat2& value) {
			x = value.x; y = value.y; z = {};
			ptr = &x;
		}
		mat3(const mat2& value, const vec3& z1) {
			x = value.x; y = value.y; z = z1;
			ptr = &x;
		}
		mat3(vec3 x1, vec3 y1, vec3 z1) {
			x = x1; y = y1; z = z1;
			ptr = &x;
		}


		vec3 column(int idx) {
			return vec3(x[idx], y[idx], z[idx]);
		}


		mat3& operator=(const mat3& value) {
			x = value.x;
			y = value.y;
			z = value.z;
			return *this;
		}
		mat3& operator=(const mat2& value) {
			x = value.x;
			y = value.y;
			return *this;
		}

		vec3& operator[] (int idx) {
			if (idx > 2) {
				std::cerr << "vec4: Index out of range 0-3." << std::endl;
				throw std::out_of_range("Index out of range 0-3.");
			}
			return ptr[idx];
		}
	};
	struct mat4 {
	private:
		vec4* ptr;
	public:
		vec4 x, y, z, w;

		mat4() {
			x = {}; y = {}; z = {}; w = {};
			ptr = &x;
		}
		mat4(const mat2& value) {
			x = value.x; y = value.y; z = {}; w = {};
			ptr = &x;
		}
		mat4(const mat2& value, const vec4& z1, const vec4& w1) {
			x = value.x; y = value.y; z = z1; w = w1;
			ptr = &x;
		}
		mat4(const mat3& value) {
			x = value.x; y = value.y; z = value.z; w = {};
			ptr = &x;
		}
		mat4(const mat3& value, const vec4& w1) {
			x = value.x; y = value.y; z = value.z; w = w1;
			ptr = &x;
		}
		mat4(vec4 x1, vec4 y1, vec4 z1, vec4 w1) {
			x = x1; y = y1; z = z1; w = w1;
			ptr = &x;
		}


		vec4 column(int idx) {
			return vec4(x[idx], y[idx], z[idx], w[idx]);
		}


		mat4& operator=(const mat4& value) {
			x = value.x;
			y = value.y;
			z = value.z;
			return *this;
		}
		mat4& operator=(const mat2& value) {
			x = value.x;
			y = value.y;
			return *this;
		}
		mat4& operator=(const mat3& value) {
			x = value.x;
			y = value.y;
			z = value.z;
			return *this;
		}

		vec4& operator[] (int idx) {
			if (idx > 4) {
				std::cerr << "vec4: Index out of range 0-4." << std::endl;
				throw std::out_of_range("Index out of range 0-4.");
			}
			return ptr[idx];
		}
	};

	// Useful matricies
	mat4 position3d(const vec3& position);
	mat3 position2d(const vec2& position);

	mat3 rotation3d(const vec3& rotation);
	mat2 rotation2d(const float& rotation);

	mat4 viewMatrix(vec3 at, vec3 eye, vec3 up = { 0, 1, 0 });
	mat4 orthographic(const float& right, const float& left, const float& top, const float& bottom, const float& far, const float& near);
	mat4 orthographic(const float& width, const float& height, const float& far, const float& near);
	mat4 orthographic(const float& width, const float& height, const float& depth);

	mat4 perspective(const float& fov, const float& near, const float& far, const float& width, const float& height);
	mat4 perspective(const float& fov, const float& near, const float& far, const float& ratio = 0.0f);



	// Non square matricies
	struct Matrix {
		size_t rowsSize, columnsSize;
		double* data;

		Matrix(const int& rows, const int& columns) {
			rowsSize = rows; columnsSize = columns;
			data = new double[rows * columns];
		}
		~Matrix() {
			delete data;
		}

		double& operator() (int row, int column) {
			return data[row * columnsSize + column];
		}

		Matrix& operator= (const Matrix& mat) {
			delete data;
			data = std::copy(mat.data, mat.data + (sizeof(double) * mat.rowsSize * mat.columnsSize), data);
			return *this;
		}
		Matrix& operator= (const mat2& mat) {
			delete data;
			data = new double[4] {mat.x.x, mat.x.y, mat.y.x, mat.y.y};
			return *this;
		}
		Matrix& operator= (const mat3& mat) {
			delete data;
			data = new double[9] {mat.x.x, mat.x.y, mat.x.z, mat.y.x, mat.y.y, mat.y.z, mat.z.x, mat.z.y, mat.z.z};
			return *this;
		}
		Matrix& operator= (const mat4& mat) {
			delete data;
			data = new double[16] {mat.x.x, mat.x.y, mat.x.z, mat.x.w, mat.y.x, mat.y.y, mat.y.z, mat.y.w, mat.z.x, mat.z.y, mat.z.z, mat.z.w, mat.w.x, mat.w.y, mat.w.z, mat.w.w};
			return *this;
		}
	};



	// Add operator overload for vectors
	vec2 operator+(const vec2& v1, const vec2& v2);
	vec3 operator+(const vec3& v1, const vec3& v2);
	vec4 operator+(const vec4& v1, const vec4& v2);

	// Multiply operator overload for vectors
	vec2 operator*(const vec2& v1, const vec2& v2);
	vec3 operator*(const vec3& v1, const vec3& v2);
	vec4 operator*(const vec4& v1, const vec4& v2);

	// Subtract operator overload for vectors
	vec2 operator-(const vec2& v1, const vec2& v2);
	vec3 operator-(const vec3& v1, const vec3& v2);
	vec4 operator-(const vec4& v1, const vec4& v2);

	// Divide operator overload for vectors
	vec2 operator/(const vec2& v1, const vec2& v2);
	vec3 operator/(const vec3& v1, const vec3& v2);
	vec4 operator/(const vec4& v1, const vec4& v2);

	// Vector operations with float
	// Add operator overload
	vec2 operator+(const float& value, const vec2& vector);
	vec3 operator+(const float& value, const vec3& vector);
	vec4 operator+(const float& value, const vec4& vector);

	// Multiply operator overload
	vec2 operator*(const float& value, const vec2& vector);
	vec3 operator*(const float& value, const vec3& vector);
	vec4 operator*(const float& value, const vec4& vector);

	// Subtract operator overload
	vec2 operator-(const float& value, const vec2& vector);
	vec3 operator-(const float& value, const vec3& vector);
	vec4 operator-(const float& value, const vec4& vector);

	// Divide operator overload
	vec2 operator/(const float& value, const vec2& vector);
	vec3 operator/(const float& value, const vec3& vector);
	vec4 operator/(const float& value, const vec4& vector);

	// Negative operator overload
	vec2 operator-(const vec2& vector);
	vec3 operator-(const vec3& vector);
	vec4 operator-(const vec4& vector);

	// Compound assign operators overload
	// Add
	vec2& operator+=(vec2& vector, const float& value);
	vec3& operator+=(vec3& vector, const float& value);
	vec4& operator+=(vec4& vector, const float& value);

	// Multiply
	vec2& operator*=(vec2& vector, const float& value);
	vec3& operator*=(vec3& vector, const float& value);
	vec4& operator*=(vec4& vector, const float& value);

	// Subtract
	vec2& operator-=(vec2& vector, const float& value);
	vec3& operator-=(vec3& vector, const float& value);
	vec4& operator-=(vec4& vector, const float& value);

	// Divide
	vec2& operator/=(vec2& vector, const float& value);
	vec3& operator/=(vec3& vector, const float& value);
	vec4& operator/=(vec4& vector, const float& value);

	// Compound assignment with vectors
	// Add
	vec2& operator+=(vec2& v1, const vec2& v2);
	vec3& operator+=(vec3& v1, const vec3& v2);
	vec4& operator+=(vec4& v1, const vec4& v2);

	// Multiply
	vec2& operator*=(vec2& v1, const vec2& v2);
	vec3& operator*=(vec3& v1, const vec3& v2);
	vec4& operator*=(vec4& v1, const vec4& v2);

	// Subtract
	vec2& operator-=(vec2& v1, const vec2& v2);
	vec3& operator-=(vec3& v1, const vec3& v2);
	vec4& operator-=(vec4& v1, const vec4& v2);

	// Divide
	vec2& operator/=(vec2& v1, const vec2& v2);
	vec3& operator/=(vec3& v1, const vec3& v2);
	vec4& operator/=(vec4& v1, const vec4& v2);

	// Modulo operator overload
	vec2 operator%(const vec2& vector, const float& value);
	vec3 operator%(const vec3& vector, const float& value);
	vec4 operator%(const vec4& vector, const float& value);

	// Cout operator overloading for vectors
	std::ostream& operator<<(std::ostream& os, const vec2& v);
	std::ostream& operator<<(std::ostream& os, const vec3& v);
	std::ostream& operator<<(std::ostream& os, const vec4& v);



	// Matrix operator overloads
	// Square matricies
	vec2 operator*(mat2 mat, vec2 vec);
	vec3 operator*(mat3 mat, vec3 vec);
	vec4 operator*(mat4 mat, vec4 vec);

	mat2 operator*(mat2 mat1, mat2 mat2);
	mat3 operator*(mat3 mat1, mat3 mat2);
	mat4 operator*(mat4 mat1, mat4 mat2);

	// Non-square matricies
	Matrix operator*(Matrix mat1, Matrix mat2);
	std::list<double> operator*(Matrix mat1, std::list<double> vec);



	std::ostream& operator<<(std::ostream& os, const mat2& v);
	std::ostream& operator<<(std::ostream& os, const mat3& v);
	std::ostream& operator<<(std::ostream& os, const mat4& v);

	std::ostream& operator<<(std::ostream& os, Matrix mat1);
}