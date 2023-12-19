void Read_rootf(){
    
    TCanvas *c_CorsikaId = new TCanvas();
    TCanvas *c_px = new TCanvas();
    TCanvas *c_py = new TCanvas();
    TCanvas *c_pz = new TCanvas();
    TCanvas *c_x = new TCanvas();
    TCanvas *c_y = new TCanvas();
    TCanvas *c_t = new TCanvas();
    TCanvas *c_shower_id = new TCanvas();
    TCanvas *c_prm_id = new TCanvas();
    TCanvas *c_prm_energy = new TCanvas();
    TCanvas *c_prm_theta = new TCanvas();
    TCanvas *c_prm_phi = new TCanvas();
    
    TFile *input = new TFile("020014.root", "read");
    TTree *tree = (TTree*)input -> Get("tree");
    
    double CorsikaId, px, py, pz, x, y, t, shower_id, prm_id, prm_energy, prm_theta, prm_phi;
    
    tree -> SetBranchAddress("CorsikaId", &CorsikaId);
    tree -> SetBranchAddress("px", &px);
    tree -> SetBranchAddress("py", &py);
    tree -> SetBranchAddress("pz", &pz);
    tree -> SetBranchAddress("x", &x);
    tree -> SetBranchAddress("y", &y);
    tree -> SetBranchAddress("t", &t);
    tree -> SetBranchAddress("shower_id", &shower_id);
    tree -> SetBranchAddress("prm_id", &prm_id);
    tree -> SetBranchAddress("prm_energy", &prm_energy);
    tree -> SetBranchAddress("prm_theta", &prm_theta);
    tree -> SetBranchAddress("prm_phi", &prm_phi);
    
    int entries = tree -> GetEntries();
    
    //cout << entries << endl;
    
    TH1D *hist_CorsikaId = new TH1D("CorsikaId", "Histograma CorsikaId", 100, 0, 15);
    TH1D *hist_px = new TH1D("px", "Histograma px", 100, -120, 120);
    TH1D *hist_py = new TH1D("py", "Histograma py", 100, -120, 120);
    TH1D *hist_pz = new TH1D("pz", "Histograma pz", 100, -120, 120);
    TH1D *hist_x = new TH1D("x", "Histograma x", 100, -7000000, 7000000);
    TH1D *hist_y = new TH1D("y", "Histograma y", 100, -3000000, 3000000);
    TH1D *hist_t = new TH1D("t", "Histograma t", 100, 0, 3000000);
    TH1D *hist_shower_id = new TH1D("shower_id", "Histograma shower_id", 100, 0, 20000);
    TH1D *hist_prm_id = new TH1D("prm_id", "Histograma prm_id", 100, 12, 16);
    TH1D *hist_prm_energy = new TH1D("prm_energy", "Histograma prm_energy", 100, 0, 1300);
    TH1D *hist_prm_theta = new TH1D("prm_theta", "Histograma prm_theta", 100, 0, 90);
    TH1D *hist_prm_phi = new TH1D("prm_phi", "Histograma prm_phi", 100, -270, 270);
    
    for(int i=0; i<entries; i++){
        tree->GetEntry(i);
        //cout << CorsikaId <<" "<< px <<" "<< py <<" "<< pz <<" "<< x <<" "<< y <<" "<< t <<" "<< shower_id <<" "<< prm_id <<" "<< prm_energy <<" "<< prm_theta <<" "<< prm_phi << endl;
        
        hist_CorsikaId->Fill(CorsikaId);
        hist_px->Fill(px);
        hist_py->Fill(py);
        hist_pz->Fill(pz);
        hist_x->Fill(x);
        hist_y->Fill(y);
        hist_t->Fill(t);
        hist_shower_id->Fill(shower_id);
        hist_prm_id->Fill(prm_id);
        hist_prm_energy->Fill(prm_energy);
        hist_prm_theta->Fill(prm_theta);
        hist_prm_phi->Fill(prm_phi);
    }
    
    c_CorsikaId -> cd();
    hist_CorsikaId -> Draw();
    c_CorsikaId -> SaveAs("./graphs/graph_CorsikaId.pdf");
    c_px -> cd();
    hist_px -> Draw();
    c_px -> SaveAs("./graphs/graph_px.pdf");
    c_py -> cd();
    hist_py -> Draw();
    c_py -> SaveAs("./graphs/graph_py.pdf");
    c_pz -> cd();
    hist_pz -> Draw();
    c_pz -> SaveAs("./graphs/graph_pz.pdf");
    c_x -> cd();
    hist_x -> Draw();
    c_x -> SaveAs("./graphs/graph_x.pdf");
    c_y -> cd();
    hist_y -> Draw();
    c_y -> SaveAs("./graphs/graph_y.pdf");
    c_t -> cd();
    hist_t -> Draw();
    c_t -> SaveAs("./graphs/graph_t.pdf");
    c_shower_id -> cd();
    hist_shower_id -> Draw();
    c_shower_id -> SaveAs("./graphs/graph_shower_id.pdf");
    c_prm_id -> cd();
    hist_prm_id -> Draw();
    c_prm_id -> SaveAs("./graphs/graph_prm_id.pdf");
    c_prm_energy -> cd();
    hist_prm_energy -> Draw();
    c_prm_energy -> SaveAs("./graphs/graph_prm_energy.pdf");
    c_prm_theta -> cd();
    hist_prm_theta -> Draw();
    c_prm_theta -> SaveAs("./graphs/graph_prm_theta.pdf");
    c_prm_phi -> cd();
    hist_prm_phi -> Draw();
    c_prm_phi -> SaveAs("./graphs/graph_prm_phi.pdf");
    
    
    
    TFile *file_hist = new TFile("./graphs/file_hist.root", "RECREATE");
    hist_CorsikaId->Write();
    hist_px->Write();
    hist_py->Write();
    hist_pz->Write();
    hist_x->Write();
    hist_y->Write();
    hist_t->Write();
    hist_shower_id->Write();
    hist_prm_id->Write();
    hist_prm_energy->Write();
    hist_prm_theta->Write();
    hist_prm_phi->Write();
    file_hist->Close();
    
    input->Close();
    
}
