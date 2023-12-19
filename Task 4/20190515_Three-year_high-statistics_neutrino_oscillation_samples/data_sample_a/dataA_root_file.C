void dataA_root_file(){
    fstream file;
    file.open("data.txt", ios::in);
    
    double count, pid, reco_coszen, reco_energy;
    
    TFile *output = new TFile("dataA.root", "recreate");
    
    TTree *datatree = new TTree("datatree","datatree");
    
    datatree -> Branch("count", &count, "count/D");
    datatree -> Branch("pid", &pid, "pid/D");
    datatree -> Branch("reco_coszen", &reco_coszen, "reco_coszen/D");
    datatree -> Branch("reco_energy", &reco_energy, "reco_energy/D");
    
    while(1){
        file >> count >> pid >> reco_coszen >> reco_energy;
        cout << count <<" "<< pid <<" "<< reco_coszen <<" "<< reco_energy << endl;
        if(file.eof()) break;
        datatree -> Fill();
    }
    output->Write();
    output->Close();
    file.close();
}
