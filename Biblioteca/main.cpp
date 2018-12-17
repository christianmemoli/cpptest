
#include <cstring>
#include <cstdio>

class Libro
{
 private:

 int codice;
 char titolo[64];
 char autore[32];
 int anno;

 public:

 Libro(void)
 {
  codice = 0;
  strcpy(titolo, "");
  strcpy(autore, "");
  anno = 1900;
 }

 Libro(int _codice, char _titolo[], char _autore[], int _anno)
 {
  codice = _codice;
  strcpy(titolo, _titolo);
  strcpy(autore, _autore);
  anno = _anno;
 }

 int getCodice(void) { return codice; }
 void getTitolo(char* _titolo) { strcpy(_titolo, titolo); }
 void getAutore(char* _autore) { strcpy(_autore, autore); }
 int getAnno(void) { return anno; }
};

class Biblioteca
{
 private:

 int numero_libri;
 Libro libri[1000];

 public:

 Biblioteca(void) { numero_libri = 0; }
 int getNumeroLibri(void) { return numero_libri; }

 void addLibro(Libro libro)
 {
  if (numero_libri<1000)
    {
	 libri[numero_libri] = libro;
	 numero_libri++;
    }
 }

 Libro findLibro(char titolo[])
 {
  char _titolo[64];

  for (int i=0; i<numero_libri; i++)
     {
	  libri[i].getTitolo(_titolo);
      if (strcmp(titolo, _titolo) == 0)
	    return libri[i];
     }

  // libro inesistente
  Libro libro(0, "", "", 1900);
  return libro;
 }

 int findLibri(char autore[], Libro lista[])
 {
  char _autore[32];
  int l=0;

  for (int i=0; i<numero_libri; i++)
     {
	  libri[i].getAutore(_autore);
	  if (strcmp(autore, _autore) == 0)
	    {
	     lista[l] = libri[i];
		 l++;
	    }
     }
  return l;
 }
};

int main(void)
{
 int i, n;
 Biblioteca biblioteca;
 Libro libro;
 Libro libri[10];
 char autore[32], titolo[64];

 libro = Libro(1, "Pinocchio", "Collodi", 1999);
 biblioteca.addLibro(libro);
 libro = Libro(2, "Il barone rampante", "Calvino", 2001);
 biblioteca.addLibro(libro);
 libro = Libro(3, "Il visconte dimezzato", "Calvino", 2001);
 biblioteca.addLibro(libro);
 libro = Libro(4, "Il cavaliere inesistente", "Calvino", 2001);
 biblioteca.addLibro(libro);

 printf("%i libri presenti nella biblioteca\r\n",biblioteca.getNumeroLibri());
 libro = biblioteca.findLibro("Pinocchio");
 libro.getTitolo(titolo);
 libro.getAutore(autore);
 printf("%i %s %s %i\r\n", libro.getCodice(), titolo, autore, libro.getAnno());
 n = biblioteca.findLibri("Calvino", libri);
 for (i=0; i<n; i++)
   {
    libri[i].getTitolo(titolo);
	libri[i].getAutore(autore);
    printf("%i %s %s %i\r\n", libri[i].getCodice(), titolo, autore, libri[i].getAnno());
   }
}
