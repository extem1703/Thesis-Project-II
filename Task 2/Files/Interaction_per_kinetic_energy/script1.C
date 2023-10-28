#include <TFile.h>
#include <TH1F.h>
#include <TTree.h>

void script1() {
    /*
    FILE *fp = fopen("df_Inter_per_kin.txt","r");
    
    Float_t x,y,z;
    Int_t ncols;
    Int_t nlines = 0;
    TFile *f = new TFile("basic.root","RECREATE");
    TH1F *h1 = new TH1F("h1","x distribution",100,-4,4);
    TNtuple *ntuple = new TNtuple("ntuple","data from ascii file","x:y:z");
    */
    // Crear un nuevo archivo ROOT
    TFile *archivo = new TFile("basic.root", "RECREATE");
    
    
}
void CrearHistogramaDesdeArchivo() {
    // Crear un nuevo archivo ROOT
    TFile *archivo = new TFile("histograma.root", "RECREATE");

    // Crear un histograma con 40 bins
    TH1F *histograma = new TH1F("mi_histograma", "Titulo del Histograma;Eje X;Eje Y", 40, 0, 100);

    // Abrir el archivo ASCII
    std::ifstream archivoDatos("datos.txt");

    // Leer los datos desde el archivo y llenar el histograma
    double valor;
    while (archivoDatos >> valor) {
        histograma->Fill(valor);
    }

    // Guardar el histograma en el archivo ROOT
    histograma->Write();

    // Cerrar el archivo ROOT
    archivo->Close();
}
/*
   while (1) {
      ncols = fscanf(fp,"%f %f %f",&x, &y, &z);
      if (ncols < 0) break;
      if (nlines < 5) printf("x=%8f, y=%8f, z=%8f\n",x,y,z);
      h1->Fill(x);
      ntuple->Fill(x,y,z);
      nlines++;
   }
   printf(" found %d points\n",nlines);
   
   fclose(fp);

   f->Write();
}*/
