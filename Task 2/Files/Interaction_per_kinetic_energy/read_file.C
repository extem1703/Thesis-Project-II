#include <iostream>
#include <iomanip>
#include <time.h>

#include "Fit/Fitter.h"
#include "Fit/BinData.h"
#include "Fit/Chi2FCN.h"
#include "TH1.h"
#include "TList.h"
#include "Math/WrappedMultiTF1.h"
#include "HFitInterface.h"
#include "TCanvas.h"
#include "TStyle.h"

//gROOT->Reset();

double c1,c2,c3; 

char buffer[100] = "df_Inter_per_kin.txt";
char sbuffer[50];
char sbuffer1[50];
char sbuffer2[50];

const char *pngpatern="%s.png";
const char *jpgpatern="%s_b.png";
const char *badpatern="%s_e.png";
const char *fnamepatern="%s";
const char *datepatern="%s";

const char *spatern="summ_%s.txt";

/*
// ----------------------------- //

double cgauss(double *x, double *par)
{
   double xx =x[0];
   double g1 = par[0]*exp(-0.5*((xx-par[1])/par[2])**2);
   return g1;
}

// ----------------------------- //

double VEM(double *x, double *par)
{

   double alpha = 9.44;
   double beta = 0.27;

   double xx =x[0];
   double g1 = par[0]*exp(-0.5*((xx-par[1])/par[2])**2);
   double f1 = 1. - xx * (xx - par[1]) / (alpha * par[2]**2);

   TF1 *G = new TF1("G",cgauss,1,80,3);
   G->SetParameters(par[0],par[1],par[2]);
   double r1 = beta*G->Integral(xx,1000);
   delete G;

   return f1*g1;
}

// ---------------------------- //

*/

void read_file(char *infile = buffer) {

     const int nbins = 4096;
     double chn[nbins][3] = {0.0};

     // ------- //
     //reads the data file
     ifstream in_rfile(infile);

     if ( !in_rfile || in_rfile.bad()) return 1;

     int k=0; 
     double id[50]={0.0};
     double var1[50]={0.0};
     double var2[50]={0.0};

     while (in_rfile >> c1 >> c2 >> c3) {
	cout << c1 << " "<< c2 << " " << c3 << endl; 
       id[k] = c1;
       var1[k] = c2;
       var2[k] = c3;
       k++;
     }

     in_rfile.close();

     TCanvas *c1 = new TCanvas("c1","c1",720,720);

     int v_bsize = 1;  //change bin size here!!!!
     double h_llim = 0; //range lower limit
     double h_ulim = 1.e12; //range upper limit
     int h_nbins = 40; // #bins in selected range
     int h_fbin = h_llim/v_bsize; // first bin in selected range

     TH1D * h1 = new TH1D("h1","h1",h_nbins,h_llim,h_ulim);
     TH1D * h2 = new TH1D("h2","h2",h_nbins,h_llim,h_ulim);
     
     for (int m=0; m<h_nbins; m++) { //histogram of selected range
//  h1->AddBinContent(m+1,var1[m]);
//  h2->AddBinContent(m+1,var2[m]);
	h1->Fill(var1[m]);
	h2->Fill(var2[m]);
     }

     h2->Draw();
     h1->Draw("same");

}
