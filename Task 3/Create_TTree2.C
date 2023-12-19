void Create_TTree2(){
    fstream file;
    file.open("Clean020014.sec", ios::in);
    
    double CorsikaId, px, py, pz, x, y, t, shower_id, prm_id, prm_energy, prm_theta, prm_phi;
    
    TFile *output = new TFile("020014.root", "recreate");
    
    TTree *tree = new TTree("tree","tree");
    
    tree -> Branch("CorsikaId", &CorsikaId, "CorsikaId/D");
    tree -> Branch("px", &px, "px/D");
    tree -> Branch("py", &py, "py/D");
    tree -> Branch("pz", &pz, "pz/D");
    tree -> Branch("x", &x, "x/D");
    tree -> Branch("y", &y, "y/D");
    tree -> Branch("t", &t, "t/D");
    tree -> Branch("shower_id", &shower_id, "shower_id/D");
    tree -> Branch("prm_id", &prm_id, "prm_id/D");
    tree -> Branch("prm_energy", &prm_energy, "prm_energy/D");
    tree -> Branch("prm_theta", &prm_theta, "prm_theta/D");
    tree -> Branch("prm_phi", &prm_phi, "prm_phi/D");
    
    while(1){
        file >> CorsikaId >> px >> py >> pz >> x >> y >> t >> shower_id >> prm_id >> prm_energy >> prm_theta >> prm_phi;
        if(file.eof()) break;
        cout << CorsikaId <<" "<< px <<" "<< py <<" "<< pz <<" "<< x <<" "<< y <<" "<< t <<" "<< shower_id <<" "<< prm_id <<" "<< prm_energy <<" "<< prm_theta <<" "<< prm_phi << endl;
        tree -> Fill();
    }
    output->Write();
    output->Close();
    file.close();
}
