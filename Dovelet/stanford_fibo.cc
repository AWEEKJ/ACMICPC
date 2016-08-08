#include <cstdio>

struct matrix {
  int m[2][2];

  matrix() {
    m[0][0] = 1;
    m[0][1] = 1;
    m[1][0] = 1;
    m[1][1] = 0;
  }

  // operator overloading
  matrix operator * (matrix &b) {
    matrix res;
    res.m[0][0] = m[0][0] * b.m[0][0] + m[0][1] * b.m[1][0];
    res.m[0][1] = m[0][0] * b.m[0][1] + m[0][1] * b.m[1][1];
    res.m[1][0] = m[1][0] * b.m[0][0] + m[1][1] * b.m[1][0];
    res.m[1][1] = m[1][0] * b.m[0][1] + m[1][1] * b.m[1][1];
    return res;
  }
};

matrix matrix_pow(matrix &m, int n) {
  if (n == 1) return m;

  matrix tmp = matrix_pow(m, n/2);
  tmp = tmp * tmp;
  if (n % 2 == 1) {
    tmp = tmp * m;
  }
  return tmp;
}

int main() {
  int n;
  while (1) {
    scanf("%d", &n);
    if (n == -1) break;

    matrix m;
    m = matrix_pow(m, n);
    printf("%d", m.m[0][1]);
  }
  return 0;
}
