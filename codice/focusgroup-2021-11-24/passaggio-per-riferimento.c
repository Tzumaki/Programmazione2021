void azzera(float* p) {
  *p = 0.0;
}

int main() {
  float x = 3.5;

  azzera(&x);
}