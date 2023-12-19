void muonA_root_file(){
    fstream file;
    file.open("muon_mc.txt", ios::in);
    
    double pdg, pid, reco_coszen, reco_energy, true_energy, true_coszen, weight;
    
    TFile *output = new TFile("muonA.root", "recreate");
    
    TTree *datatree = new TTree("datatree","datatree");
    
    datatree -> Branch("pdg", &pdg, "pdg/D");
    datatree -> Branch("pid", &pid, "pid/D");
    datatree -> Branch("reco_coszen", &reco_coszen, "reco_coszen/D");
    datatree -> Branch("reco_energy", &reco_energy, "reco_energy/D");
    datatree -> Branch("true_energy", &true_energy, "true_energy/D");
    datatree -> Branch("true_coszen", &true_coszen, "true_coszen/D");
    datatree -> Branch("weight", &weight, "weight/D");
    
    while(1){
        file >> pdg >> pid >> reco_coszen >> reco_energy >> true_energy >> true_coszen >> weight;
        cout << pdg <<" "<< pid <<" "<< reco_coszen <<" "<< reco_energy <<" "<< true_energy <<" "<< true_coszen <<" "<< weight << endl;
        if(file.eof()) break;
        datatree -> Fill();
    }
    output->Write();
    output->Close();
    file.close();
}
