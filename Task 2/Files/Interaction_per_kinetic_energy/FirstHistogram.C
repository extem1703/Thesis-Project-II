#include<TF1.h>

double c1, c2, c3;

char buffer[100] = "df_Inter_per_kin.txt";

void FirstHistogram(char *infile = buffer){
    
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
    
    TCanvas *canvas = new TCanvas("canvas","Histogramas",79,66,636,478);
    
    double h_llim = -0.05e14; //range lower limit
    double h_ulim = 1.05e14; //range upper limit
    int h_nbins = 44; // #bins in selected range
    
    TH1D* h1 = new TH1D("h1", "Histograma", h_nbins, h_llim, h_ulim);
    TH1D* h2 = new TH1D("h2", "Histograma; Energy (GeV); Frecuency", h_nbins, h_llim, h_ulim);
    
    for (int imeas=0;imeas<40;imeas++){
        h1 -> Fill(var1[imeas]);
        h2 -> Fill(var2[imeas]);
    }
    h2->SetStats(0);
    h2->SetLineColor(kRed);
    h2->SetLineWidth(5);
    h2->Draw();
    h1->SetFillColor(kBlue);
    h1->SetFillStyle(3002);
    h1->Draw("SAME");
    
    TLegend *legend = new TLegend(0.74,0.79,0.89,0.887);
    legend->AddEntry(h1, "LOWER", "f");
    legend->AddEntry(h2, "UPPER", "f");
    legend->Draw();
    
    canvas->Update();
    canvas->Modified();
    canvas->SaveAs("histograma_ROOT.png");
}
