void muonB_root_file(){
    fstream file;
    file.open("muons.txt", ios::in);
    
    double abs_uncert, count, pid, reco_coszen, reco_energy;
    
    TFile *output = new TFile("muonB.root", "recreate");
    
    TTree *datatree = new TTree("datatree","datatree");
    
    datatree -> Branch("abs_uncert", &abs_uncert, "abs_uncert/D");
    datatree -> Branch("count", &count, "count/D");
    datatree -> Branch("pid", &pid, "pid/D");
    datatree -> Branch("reco_coszen", &reco_coszen, "reco_coszen/D");
    datatree -> Branch("reco_energy", &reco_energy, "reco_energy/D");
    
    while(1){
        file >> abs_uncert >> count >> pid >> reco_coszen >> reco_energy;
        cout << abs_uncert << " " << count <<" "<< pid <<" "<< reco_coszen <<" "<< reco_energy << endl;
        datatree -> Fill();
        if(file.eof()) break;
    }
    output->Write();
    output->Close();
    file.close();
}
