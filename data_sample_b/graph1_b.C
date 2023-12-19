void graph1_b(){
    
    TCanvas *c1 = new TCanvas("Canvas1","Canvas1",1200,600);
    TCanvas *c2 = new TCanvas("Canvas2","Canvas2",1200,600);
    TCanvas *c3 = new TCanvas("Canvas3","Canvas3",1200,600);
    TCanvas *c4 = new TCanvas("Canvas4","Canvas4",1200,600);
    TFile *input = new TFile("dataB.root", "read");
    TTree *tree = (TTree*)input->Get("datatree");
    double count, pid, reco_coszen, reco_energy;
    
    tree -> SetBranchAddress("count", &count);
    tree -> SetBranchAddress("pid", &pid);
    tree -> SetBranchAddress("reco_coszen", &reco_coszen);
    tree -> SetBranchAddress("reco_energy", &reco_energy);
    
    int entries = tree -> GetEntries();
    
    Double_t bin_energycas[9] = {5.623413,  7.498942, 10. , 13.335215, 17.782795, 23.713737, 31.622776, 42.16965 , 56.23413};
    Double_t bin_energytrac[9] = {5.623413,  7.498942, 10. , 13.335215, 17.782795, 23.713737, 31.622776, 42.16965 , 56.23413};
    Double_t bin_coszen[9] = {-1., -0.75, -0.5 , -0.25,  0., 0.25, 0.5, 0.75, 1.};
    
     TH2D *histCas = new TH2D("Cascade-like", "Cascade-like", 8, bin_energycas, 8, bin_coszen);
     TH2D *histTrac = new TH2D("Track-like", "Track-like", 8, bin_energytrac, 8, bin_coszen);
    for (int i=0; i<entries; i++){
        tree -> GetEntry(i);
        if (pid == 0) {
            for (int j=1; j<=count; j++){
                histCas -> Fill(reco_energy,reco_coszen);
            }
        }
        if (pid == 1) {
            for (int j=1; j<=count; j++){
                histTrac -> Fill(reco_energy,reco_coszen);
            }
        }
    }
    
    double globalMin = min(histCas->GetMinimum(), histTrac->GetMinimum());
    double globalMax = max(histCas->GetMaximum(), histTrac->GetMaximum());

    histCas->SetMinimum(globalMin);
    histCas->SetMaximum(globalMax);
    histTrac->SetMinimum(globalMin);
    histTrac->SetMaximum(globalMax);


    gStyle->SetPalette(53);
    gStyle->SetPadBottomMargin(0.1);
    gStyle->SetPadTopMargin(0.075);
    gStyle->SetPadLeftMargin(0.13);
    gStyle->SetPadRightMargin(0.16);
    gStyle->SetLabelSize(0.04,"xyz");
    gStyle->SetLabelOffset(0.015,"xyz");
    gStyle->SetTitleSize(0.04,"xyz");
    gStyle->SetTitleOffset(1.2,"x");
    gStyle->SetTitleOffset(1.5,"y");
    gStyle->SetTitleOffset(1.4,"z");
    gStyle->SetStatFontSize(0.07);
    gStyle->SetTextSize(0.04);
    gStyle->SetTitleBorderSize(0);
    gStyle->SetStatBorderSize(1);
    TGaxis::SetMaxDigits(3);
    
    c1 -> Divide(2,1);
    
    c1 -> cd(1);
    
    histCas -> GetXaxis() -> SetTitle("Reconstructed Energy (GeV)");
    histCas -> GetYaxis() -> SetTitle("Reconstructed Cos(Zenith)");
    histCas -> GetZaxis() -> SetTitle("Count");
    histCas -> SetStats(1);
    
    histCas -> Draw("ColZ");
    
    gPad->Update();
    TPaveStats *stCas1 = (TPaveStats*)histCas->FindObject("stats");
    stCas1->SetX1NDC(0.6);
    stCas1->SetX2NDC(0.8);
    stCas1->SetY1NDC(0.7);
    stCas1->SetY2NDC(0.9);
    
    c1 -> cd(2);
    
    histTrac -> GetXaxis() -> SetTitle("Reconstructed Energy (GeV)");
    histTrac -> GetYaxis() -> SetTitle("");
    histTrac -> GetZaxis() -> SetTitle("Count");
    histTrac -> SetStats(1);
    
    histTrac -> Draw("ColZ");
    
    gPad->Update();
    TPaveStats *stTrac1 = (TPaveStats*)histTrac->FindObject("stats");
    stTrac1->SetX1NDC(0.6);
    stTrac1->SetX2NDC(0.8);
    stTrac1->SetY1NDC(0.7);
    stTrac1->SetY2NDC(0.9);
    
    c1->Modified();
    c1->Update();
    
    c1 -> Draw();
    c1 -> SaveAs("./graphs/graph1_b.pdf");
    
    c2 -> Divide(2,1);
    
    c2 -> cd(1);
    histCas -> GetXaxis() -> SetTitle("Reconstructed Energy (GeV)");
    histCas -> GetYaxis() -> SetTitle("Reconstructed Cos(Zenith)");
    histCas -> GetZaxis() -> SetTitle("Count");
    histCas -> SetStats(1);
    histCas -> Draw("Cont1");
    gPad->Update();
    TPaveStats *stCas2 = (TPaveStats*)histCas->FindObject("stats");
    stCas2->SetX1NDC(0.6);
    stCas2->SetX2NDC(0.8);
    stCas2->SetY1NDC(0.7);
    stCas2->SetY2NDC(0.9);
    
    c2 -> cd(2);
    histTrac -> GetXaxis() -> SetTitle("Reconstructed Energy (GeV)");
    histTrac -> GetYaxis() -> SetTitle("");
    histTrac -> GetZaxis() -> SetTitle("Count");
    histTrac -> SetStats(1);
    histTrac -> Draw("Cont1");
    gPad->Update();
    TPaveStats *stTrac2 = (TPaveStats*)histTrac->FindObject("stats");
    stTrac2->SetX1NDC(0.6);
    stTrac2->SetX2NDC(0.8);
    stTrac2->SetY1NDC(0.7);
    stTrac2->SetY2NDC(0.9);
    
    c2 -> Draw();
    c2 -> SaveAs("./graphs/graph2_b.pdf");
    
    c3 -> Divide(2,1);
    
    c3 -> cd(1);
    histCas -> GetXaxis() -> SetTitle("Reconstructed Energy (GeV)");
    histCas -> GetYaxis() -> SetTitle("Reconstructed Cos(Zenith)");
    histCas -> GetZaxis() -> SetTitle("Count");
    histCas -> SetStats(1);
    histCas -> Draw("Lego2");
    
    c3 -> cd(2);
    histTrac -> GetXaxis() -> SetTitle("Reconstructed Energy (GeV)");
    histTrac -> GetYaxis() -> SetTitle("Reconstructed Cos(Zenith)");
    histTrac -> GetZaxis() -> SetTitle("Count");
    histTrac -> SetStats(1);
    histTrac -> Draw("Lego2");
    
    c3 -> Draw();
    c3 -> SaveAs("./graphs/graph3_b.pdf");
    
    c4 -> Divide(2,1);
    
    c4 -> cd(1);
    histCas -> GetXaxis() -> SetTitle("Reconstructed Energy (GeV)");
    histCas -> GetYaxis() -> SetTitle("Reconstructed Cos(Zenith)");
    histCas -> GetZaxis() -> SetTitle("Count");
    histCas -> SetStats(1);
    histCas -> Draw("Surf3");
    
    c4 -> cd(2);
    histTrac -> GetXaxis() -> SetTitle("Reconstructed Energy (GeV)");
    histTrac -> GetYaxis() -> SetTitle("Reconstructed Cos(Zenith)");
    histTrac -> GetZaxis() -> SetTitle("Count");
    histTrac -> SetStats(1);
    histTrac -> Draw("Surf3");
    
    c4 -> Draw();
    c4 -> SaveAs("./graphs/graph4_b.pdf");
    
    TFile *file_hist = new TFile("./graphs/file_histB.root", "RECREATE");
    c1->Write();
    c2->Write();
    c3->Write();
    c4->Write();
    file_hist->Close();
    
    input->Close();
}
