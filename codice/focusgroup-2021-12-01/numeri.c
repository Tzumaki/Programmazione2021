typedef struct {
  int num;
  int den;
} Frazione;

typedef union {
  float dato_dec;
  Frazione dato_fraz;
} Dato;

typedef struct {
  enum { razionale, decimale } tipo;
  Dato dato;
} Numero;

Frazione prodotto_frazionario(Frazione f1, Frazione f2) {
  Frazione risultato;
  risultato.num = f1.num * f2.num;
  risultato.den = f1.den * f2.den;
  return risultato;
}

Numero moltiplicazione(Numero n1, Numero n2) {
  Numero risultato;
  if (n1.tipo == razionale && n2.tipo == razionale) {
    risultato.tipo = razionale;
    risultato.dato.dato_fraz = prodotto_frazionario(n1.dato.dato_fraz, n2.dato.dato_fraz);
  } else {
    risultato.tipo = decimale;
    risultato.dato.dato_dec =
        (n1.tipo == razionale
             ? (float)(n1.dato.dato_fraz.num) / (n1.dato.dato_fraz.den)
             : n1.dato.dato_dec) *
        (n2.tipo == razionale
             ? (float)(n2.dato.dato_fraz.num) / n2.dato.dato_fraz.den
             : n2.dato.dato_dec);
  }

  return risultato;
}
