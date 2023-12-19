double c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12;

char buffer[100] = "Clean020014.sec";

void Create_TTree(char *infile = buffer){
    //reads the data file
    ifstream in_rfile(infile);

    if ( !in_rfile || in_rfile.bad()) return 1;
    
    int k=0;
    double CorsikaId[10000]={0.0};
    double px[10000]={0.0};
    double py[10000]={0.0};
    double pz[10000]={0.0};
    double x[10000]={0.0};
    double y[10000]={0.0};
    double t[10000]={0.0};
    double shower_id[10000]={0.0};
    double prm_id[10000]={0.0};
    double prm_energy[10000]={0.0};
    double prm_theta[10000]={0.0};
    double prm_phi[10000]={0.0};
    
    TFile *output = new TFile("Clean020014.root", "recreate");
    TTree *tree = new TTree("tree", "tree");
    
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
    
    while (in_rfile >> c1 >> c2 >> c3 >> c4 >> c5 >> c6 >> c7 >> c8 >> c9 >> c10 >> c11 >> c12) {
        cout << c1 << " "<< c2 << " " << c3 << " " << c4 << " " << c5 << " " << c6 << " " << c7 << " " << c8 << " " << c9 << " " << c10 << " " << c11 << " " << c12 << endl;
        CorsikaId[k] = c1;
        px[k] = c2;
        py[k] = c3;
        pz[k] = c4;
        x[k] = c5;
        y[k] = c6;
        t[k] = c7;
        shower_id[k] = c8;
        prm_id[k] = c9;
        prm_energy[k] = c10;
        prm_theta[k] = c11;
        prm_phi[k] = c12;
        k++;
        
        tree -> Fill();
    }
    
    output -> Write();
    output -> Close();
    
    in_rfile.close();
}
