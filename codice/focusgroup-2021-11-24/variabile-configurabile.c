int main() {
  float a, b, m = 3.0;
  float* p;
  p = m * m > 5.0 ? &a : &b;
  *p = m;
}