int main() {
  float a, b, m = 3.0;
  *(m * m > 5.0 ? &a : &b) = m;
}